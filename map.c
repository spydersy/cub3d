/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:09:57 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/10 09:46:24 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

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

void	bad_char(const char *line, int i)
{
	if (!(line[i] == '1' || line[i] == '0' || line[i] == '2'
	|| line[i] == 'N' || line[i] == 'E' || line[i] == 'S'
	|| line[i] == 'W' || line[i] == ' ' || line[i] == '\t'))
		ft_error("BAAAD CHAR\n");
}

void	check_horizontal(int x, int y, int y_max)
{
	if (y == 0)
		ft_error("bad char at first line\n");
	else if (y == y_max - 1)
		ft_error("bad char at last line\n");
	else if (g_map[y - 1][x] != '0' || g_map[y - 1][x] != '1')
	{
		printf(">>%s<<\n", g_map[y]);
		printf(">>%c, %d<<\n", g_map[y][x], x);
		ft_error("+++++++++++++++++++++");
	}
	else if (g_map[y + 1][x] != '0' || g_map[y + 1][x] != '1')
	{
		printf(">>%s<<\n", g_map[y]);
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

void	check_line(const char *line, int nb_line)
{
	int		i;
	int		j;
	char	*check_char;

	i = -1;
	check_char = "02NSEW";
	while (line[++i])
	{
		j = -1;
		while (check_char[++j])
		{
			bad_char(line, i);
			if (check_char[j] == line[i])
			{
				bef_aft(check_char[j], line, nb_line, i);
			}
		}
	}
}

int		skip_void(int fd)
{
	char	*line;
	int		r;

	r = 1;
	while ((r = get_next_line(fd, &line)))
	{
		if (skip_line(line) == 0)
		{
			check_line(line, 1);
			g_liste = initialisation(line);
			return (ft_strlen(line));
		}
	}
	if (r == 0)
		ft_error("No map\n");
	return (0);
}

size_t	my_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t size_src;

	i = 0;
	if (!src)
		return (0);
	size_src = ft_strlen(src);
	if (size > 0)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (size_src);
}

void	ft_move(int nb_line, int max_len)
{
	t_line		*actual;
	int			i;

	actual = g_liste->first;
	nb_line--;
	while (nb_line >= 0 && g_map[nb_line])
	{
		// printf("map : %4d|>>%s<<\n", nb_line, actual->line);
		my_strlcpy(g_map[nb_line], actual->line, ft_strlen(actual->line));
		if ((i = ft_strlen(actual->line)) < max_len)
		{
			while (i < max_len)
			{
				g_map[nb_line][i] = ' ';
				i++;
			}
			g_map[nb_line][i] = '\0';
		}
		actual = actual->next;
		nb_line--;
	}
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

void	show_map(void)
{
	int		i;

	i = 0;
	printf("\nSHOW MAP\n\n");
	while (g_map[i])
	{
		printf("ret : %4d|>>%s<<\n", i, g_map[i]);
		i++;
	}
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
	show_map();
}
