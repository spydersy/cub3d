/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:09:57 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/09 07:39:27 by abelarif         ###   ########.fr       */
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
			printf("%d|map : >>%s<<\n", 1, line);
			check_line(line, 1);
			return (1);
		}
	}
	if (r == 0)
		ft_error("No map\n");
	return (0);
}

void	ft_map(int fd)
{
	static int      nb_line = 0;
	int             r;
	char            *line;

	r = 11;
	nb_line = skip_void(fd);
	while ((r = get_next_line(fd, &line)) > 0)
	{
		nb_line++;
		printf("%d|map : >>%s<<\n", nb_line, line);
		if (skip_line(line) == 0)
		{
			// printf("map : >>%s<<\n", line);
			check_line(line, nb_line);
		}
	}
	nb_line++;
	printf("%d|last line : %s\n", nb_line, line);
	check_line(line, nb_line);
}