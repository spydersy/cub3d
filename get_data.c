/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:01:08 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/11 04:35:30 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_player(char orientation, int x, int y)
{
	if (g_player.oreintation)
		ft_error("Multiple definition of Player\n");
	g_player.x = x;
	g_player.y = y;
	if (orientation == 'N')
		g_player.oreintation = 1;
	else if (orientation == 'S')
		g_player.oreintation = 2;
	else if (orientation == 'E')
		g_player.oreintation = 3;
	else if (orientation == 'W')
		g_player.oreintation = 4;
}

int		get_resolution(char **content)
{
	if (ft_strlen(content[0]) != 1)
		ft_error("Resolution\n");
	if (ft_strncmp("R", content[0], 1))
		ft_error("Resolution\n");
	if (all_digit(content[1]) && all_digit(content[2]) && g_data.nb[0] == 0)
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

void	get_cl(int r, int g, int b)
{
	g_data.ce_color[0] = r;
	g_data.ce_color[1] = g;
	g_data.ce_color[2] = b;
}

void	get_fl(int r, int g, int b)
{
	g_data.fl_color[0] = r;
	g_data.fl_color[1] = g;
	g_data.fl_color[2] = b;
}

int		get_rgb(int index, const char *str)
{
	char	**rgb;
	int		nb;

	nb = 0;
	rgb = ft_split(str, ',');
	while (rgb[nb])
		nb++;
	if (nb != 3)
		ft_error("RGB\n");
	if (!(all_digit(rgb[0]) && all_digit(rgb[1]) && all_digit(rgb[2])))
		ft_error("RGB\n");
	if (index == 6)
		get_cl(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	else
		get_fl(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
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
		g_data.so_texture = ft_strdup(str);
	else if (index == 3 && g_data.nb[3] == 0)
		g_data.we_texture = ft_strdup(str);
	else if (index == 4 && g_data.nb[4] == 0)
		g_data.ea_texture = ft_strdup(str);
	else if (index == 5 && g_data.nb[5] == 0)
		g_data.sp_texture = ft_strdup(str);
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
