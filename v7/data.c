/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 12:48:01 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/16 00:42:07 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	ft_data(int fd)
{
	static int		nb = 0;
	char			*line;
	int				r;

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
