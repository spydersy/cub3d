/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:08:50 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/01 13:34:33 by abelarif         ###   ########.fr       */
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

int		all_digit(const char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}

int		get_resolution(char **content)
{
	if (ft_strlen(content[0]) != 1)
		ft_error("Resolution\n");
	if (ft_strncmp("R", content[0], 1))
		ft_error("Resolution\n");
	if (all_digit(content[1]) && content[2] && g_data.nb[0] == 0)
	{
		g_data.resolution[0] = ft_atoi(content[1]);
		g_data.resolution[1] = ft_atoi(content[2]);
		g_data.nb[0] = 1;
		return (1);
	}
	else if (g_data.nb[0] == 1)
	{
		ft_error("Resolution already exist\n");
		return (1);
	}
	else
		ft_error("Resolution value\n");
	return (0);
}

int		get_rgb(int index, const char *str)
{
	char	*rgb;
	int		nb;

	nb = 0;
	rgb = ft_split(str, ',');
	while (rgb[nb])
		nb ++;
	if (nb != 3)
		ft_error("RGB\n");
	if (!(all_digit(rgb[0]) && all_digit(rgb[1]) && all_digit(rgb[2])))
		ft_error("RGB\n");
	if (index == 6)
	{
		g_data.ce_color[0] = ft_atoi(rgb[0]);
		g_data.ce_color[1] = ft_atoi(rgb[1]);
		g_data.ce_color[2] = ft_atoi(rgb[2]);
	}
	else
	{
		g_data.fl_color[0] = ft_atoi(rgb[0]);
		g_data.fl_color[1] = ft_atoi(rgb[1]);
		g_data.fl_color[2] = ft_atoi(rgb[2]);
	}
	g_data.nb[index] = 1;
	return (1);
}

int		get_path(int index, const char *str)
{
	if (g_data.nb[index] != 0)
		ft_error("Texture\n");
	else if (index == 1 && g_data.nb[1] == 0)
		g_data.no_texture = ft_strdup(str);
	else if (index == 2 && g_data.nb[2] == 0)
		g_data.no_texture = ft_strdup(str);
	else if (index == 3 && g_data.nb[3] == 0)
		g_data.no_texture = ft_strdup(str);
	else if (index == 4 && g_data.nb[4] == 0)
		g_data.no_texture = ft_strdup(str);
	else if (index == 5 && g_data.nb[5] == 0)
		g_data.no_texture = ft_strdup(str);
	else if (index == 6 && g_data.nb[6] == 0)
		return (get_rgb(index, str));
	else if (index == 7 && g_data.nb[7] == 0)
		return (get_rgb(index, str));
	else
		ft_error("Texture exist\n");
	g_data.nb[index] = 1;
	return (1);
}

int		get_texture(char **content)
{
	int		index;

	index = 0;
	if (!ft_strncmp(content[0], "NO", max_of(ft_strlen(content[0]), 2)))
		index = 1;
	else if (!ft_strncmp(content[0], "SO", max_of(ft_strlen(content[0]), 2)))
		index = 2;
	else if (!ft_strncmp(content[0], "WE", max_of(ft_strlen(content[0]), 2)))
		index = 3;
	else if (!ft_strncmp(content[0], "EA", max_of(ft_strlen(content[0]), 2)))
		index = 4;
	else if (!ft_strncmp(content[0], "S", max_of(ft_strlen(content[0]), 2)))
		index = 5;
	else if (!ft_strncmp(content[0], "F", max_of(ft_strlen(content[0]), 1)))
		index = 6;
	else if (!ft_strncmp(content[0], "C", max_of(ft_strlen(content[0]), 1)))
		index = 7;
	else
		ft_error("Not a valid content\n");
	return (get_path(index, content[1]));
}

int		manip_line(const char *line)
{
	char			**content;
	static int		nb_data = 0;
	int				nb;

	nb = 0;
	if ((content = my_split(line, ' ', '\t')) == NULL)
	{
		ft_error("Split\n");
	}
	while (content[nb])
	{
		nb++;
	}
	if (nb == 3)
	{
		nb_data += get_resolution(content);
	}
	else if (nb == 2)
	{
		nb_data += get_texture(content);
	}
	else
	{
		
	}
	
}

void	ft_init(void)
{
	g_data.nb[0] = 0;
	g_data.nb[1] = 0;
	g_data.nb[2] = 0;
	g_data.nb[3] = 0;
	g_data.nb[4] = 0;
	g_data.nb[5] = 0;
	g_data.nb[6] = 0;
	g_data.nb[7] = 0;
	g_data.resolution[0] = -1;
	g_data.resolution[1] = -1;
	
}

void	ft_data(int save, int fd)
{
	int			r;
	static int	nb = 0;
	char		*line;

	r = 1;
	ft_init();
	while (r && nb < 8)
	{
		if ((r = get_next_line(fd, &line)) < 0)
			ft_error("GNL\n");
		if (skip_line(line) == 0)
		{
			if (manip_line(line) == 1)
				nb++;
			
		}
	}
}