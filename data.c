/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:48:24 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/27 08:52:57 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		skip_line(const char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
	}
	return (1);
}

int		all_digits(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	get_resolution(char **content)
{
	if (g_data.nb_data[0] == 1)
		ft_error("Get Data\n");
	if (ft_srncmp(content[0], "R", ft_strlen(content[0])))
		ft_error("Get Data\n");
	if (all_digits(content[1]) &&  all_digits(content[2]))
	{
		g_data.resolution[0] = ft_atoi(content[1]);
		g_data.resolution[1] = ft_atoi(content[2]);
		g_data.nb_data[0] = 1;
	}
}

void	get_texture(char **content)
{
	if (!ft_strncmp("NO", content[0], 2) && g_data.nb_data[1] == 0)
	{
		g_data.no_texture = ft_strdup(content[1]);
		g_data.nb_data[1] = 1;
	}
	else if (!ft_strncmp("SO", content[0], 2) && g_data.nb_data[2] == 0)
	{
		g_data.so_texture = ft_strdup(content[1]);
		g_data.nb_data[2] = 1;
	}
	else if (!ft_strncmp("WE", content[0], 2) && g_data.nb_data[3] == 0)
	{
		g_data.we_texture = ft_strdup(content[1]);
		g_data.nb_data[3] = 1;
	}
	else if (!ft_strncmp("EA", content[0], 2) && g_data.nb_data[4] == 0)
	{
		g_data.ea_texture = ft_strdup(content[1]);
		g_data.nb_data[4] = 1;
	}
	else
		ft_error("Data\n");
}

void	get_colors(char **content)
{
	char		*rgb;

	if (content[0][0] == 'S')
		g_data.sp_texture = ft_strdup(content[1]);
	else if (content[0][0] == 'F' || content[0][0] == 'C')
	{
		rgb = ft_split(content[1], ',');
		if (all_digits(rgb[0]) && all_digits(rgb[1]) && all_digits(rgb[2]))
		{
			if (content[0][0] == 'F')
			{
				g_data.floor[0] = ft_atoi(rgb[0]);
				g_data.floor[1] = ft_atoi(rgb[1]);
				g_data.floor[2] = ft_atoi(rgb[2]);
			}
			else
			{
				g_data.ceilling[0] = ft_atoi(rgb[0]);
				g_data.ceilling[1] = ft_atoi(rgb[1]);
				g_data.ceilling[2] = ft_atoi(rgb[2]);
			}
		}
	}
	else
		ft_error("Data\n");
}

void	get_data(int fd)
{
	int				r;
	static int 		nb = 0;
	char			**content;
	char			*line;
	int				nb_content;

	r = 1;
	nb_content = 0;
	while (r)
	{
		if ((r = get_next_line(fd, &line)) == -1)
			ft_error("Get Data\n");
		if (skip_line(line) == 0)
		{
			if ((content = my_split(line, ' ', '\t')) == NULL)
				ft_error("Get Data\n");
			while(content[nb_content])
				nb_content++;
			if (nb_content == 3)
			{
				get_resolution(content);
				nb_content++;
			}
			if (nb_content == 2 && ft_strlen(content[0]) == 2)
			{
				get_texture(content);
				nb_content++;
			}
			if (nb_content == 2 && ft_strlen(content[0]) == 1)
			{
				get_colors(content);
				nb_content++;
			}
}
	}
}