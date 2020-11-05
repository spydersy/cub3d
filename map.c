/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:09:57 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/05 11:49:05 by abelarif         ###   ########.fr       */
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
			if (!(line[i] == '1' || line[i] == '0' || line[i] == '2'
			|| line[i] == 'N' || line[i] == 'E' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == ' ' || line[i] == '\t'))
				ft_error("BAAAD CHAR\n");
			if (check_char[j] == line[i])
			{
				if (2 <= j)
					get_player(check_char[j], i, nb_line);
				if (i == 0 || i == (int)ft_strlen(line) - 1)
					ft_error("First or Last char in map\n");
				else if (line[i - 1] == ' ' || line[i - 1] == '\t')	//before
				{
					ft_error("BEFORE\n");
				}
				else if (line[i + 1]
				&& (line[i + 1] == ' ' || line[i + 1] == '\t'))		//after
				{
					ft_error("AFTER\n");
				}
			}
		}
	}
}

void   ft_map(int fd)
{
	static int      nb_line = 0;
	int             r;
	char            *line;

	r = 11;
	while ((r = get_next_line(fd, &line)) > 0)
	{
		// printf("%d|map : >>%s<<\n", r, line);
		if (skip_line(line) == 0)
		{
			nb_line++;
			printf("map : >>%s<<\n", line);
			check_line(line, nb_line);
		}
	}
	printf("last line : %s\n", line);
	check_line(line, nb_line);
}