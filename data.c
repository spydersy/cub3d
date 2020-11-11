/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:08:50 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/11 04:35:18 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int		manip_line(const char *line)
{
	char			**content;
	static int		nb_data = 0;
	int				nb;
	int				i;

	i = 0;
	nb = 0;
	if ((content = my_split(line, ' ', '\t')) == NULL)
		ft_error("Split\n");
	while (content[nb])
		nb++;
	if (nb == 3)
		nb_data += get_resolution(content);
	else if (nb == 2)
		nb_data += get_texture(content);
	else
		ft_error("Content line\n");
	return (1);
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
	g_player.x = -1;
	g_player.y = -1;
	g_player.oreintation = 0;
}

void	ft_data(int fd)
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
