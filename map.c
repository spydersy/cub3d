/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:09:57 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/11 10:59:53 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include "./mlx/mlx.h"
#include "./mlx/mlx_int.h"

void	check_horizontal(int x, int y, int y_max)
{
	if (y == 0)
	{
		// printf(">>%s<<\n", g_map[y]);
		printf("(%d,%d)\n", y, x);
		ft_error("bad char at first line\n");
	}
	else if (y == y_max - 1)
	{
		// printf(">>%s<<\n", g_map[y]);
		ft_error("bad char at last line\n");
	}
	else if (g_map[y - 1][x] != '0' && g_map[y - 1][x] != '1'
	&& g_map[y - 1][x] != '2' && g_map[y - 1][x] != 'N'
	&& g_map[y - 1][x] != 'E' && g_map[y - 1][x] != 'S'
	&& g_map[y - 1][x] != 'W')
	{
		printf ("to check   : >>%c<<\n", g_map[y][x]);
		printf ("check with : >>%c<<\n", g_map[y - 1][x]);
		// printf(">>%s<<\n", g_map[y]);
		// printf(">>%d, %d<<\n", y, x);
		ft_error("+++++++++++++++++++++");
	}
	else if (g_map[y + 1][x] != '0' && g_map[y + 1][x] != '1'
	&& g_map[y + 1][x] != '2' && g_map[y + 1][x] != 'N'
	&& g_map[y + 1][x] != 'E' && g_map[y + 1][x] != 'S'
	&& g_map[y + 1][x] != 'W')
	{
		// printf(">>%s<<\n", g_map[y]);
		// printf(">>%d, %d<<\n", y, x);
		ft_error("---------------------");
	}
}

void	horizontal_map(int y_max)
{
	int		y;
	int		i;
	int		x;
	char	*check_char;

	y = -1;
	check_char = "02ENSW";
	while (g_map[++y])
	{
		x = -1;
		// printf("line : >>%s<<\n", g_map[y]);
		while (g_map[y][++x])
		{
			i = -1;
			while (check_char[++i])
			{
				if (check_char[i] == g_map[y][x])
					check_horizontal(x, y, y_max);
			}
		}
	}
}

void	bef_aft(char check_char, const char *line,
				int nb_line, int i)
{
	if (check_char == 'N' || check_char == 'S'
	|| check_char == 'E' || check_char == 'W')
		get_player(check_char, i, nb_line);
	if (i == 0 || i == (int)ft_strlen(line) - 1)
		ft_error("First or Last char in map\n");
	else if (line[i - 1] == ' ' || line[i - 1] == '\t')
		ft_error("BEFORE\n");
	else if (line[i + 1]
	&& (line[i + 1] == ' ' || line[i + 1] == '\t'))
		ft_error("AFTER\n");
}

void	map_2d(int nb_line, int max_len)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	if ((g_map = malloc(sizeof(char *) * (nb_line + 1))) == 0)
		ft_error("malloc map 1\n");
	g_map[nb_line] = NULL;
	while (i < nb_line)
	{
		if ((g_map[i] = malloc(sizeof(char) * (max_len + 1))) == 0)
			ft_error("malloc map 2\n");
		i++;
	}
	ft_move(nb_line, max_len);
	horizontal_map(nb_line);
}

void	ft_map(int fd)
{
	static int		nb_line = 0;
	int				r;
	char			*line;
	int				max_len;

	r = 11;
	max_len = skip_void(fd);
	nb_line++;
	while ((r = get_next_line(fd, &line)) > 0)
	{
		nb_line++;
		max_len = ((max_len <= (int)ft_strlen(line))
				? (ft_strlen(line)) : (max_len));
		insertion(g_liste, line);
		if (skip_line(line) == 0)
			check_line(line, nb_line);
	}
	nb_line++;
	check_line(line, nb_line);
	insertion(g_liste, line);
	printf("nb_line : %d\n", nb_line);
	printf("max_len : %d\n", max_len);
	map_2d(nb_line, max_len);
	int	i = 0;
	while (g_map[i])
	{
		printf(">>%s<<\n", g_map[i]);
		i++;
	}
	cub3d(nb_line, max_len);
}
