/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:09:57 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/03 12:30:20 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_line(int nb_line, int len, const char *line)
{
	int			i;
	char		*check_map;
	int			j;

	j = -1;
	i = 0;
	check_map = "02NSEW";
	while (line[i])
	{
		while (check_map[++j])
		{
			if (line[i] == check_map[j])
			{
				if (i == ft_strlen(line) - 1 || i == 0)
					ft_error("First or Last bit Map\n");
				else if (line[i + 1] != '0' && line[i - 1] != '1')
					ft_error("Wrong bit bef\n");
				else if (line[i + 1] != '0' && line[i + 1] != '1')
					ft_error("Wrong bit aft\n");
			}
		}
		i++;
	}
}

void   ft_map(int fd)
{
	static int      nb_line = 0;
	static int      len = 0;
	int             r;
	char            *line;

	r = 11;
	while ((r = get_next_line(fd, &line)) > 0)
	{
		if (skip_line(line) == 0)
		{
			nb_line++;
			check_line(nb_line, len , line);
		}
	}
}