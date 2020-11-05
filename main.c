/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:21:59 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/03 14:43:25 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int			max_of(int i, int j)
{
	return ((i < j) ? (j) : (i));
}

void		ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (str == NULL)
	{
		strerror(errno);
	}
	else
	{
		ft_putstr_fd(str, 2);
	}
	exit(-1);
}

void		ft_print(void)
{
	printf("value RESOLUTION X : %d\n", g_data.resolution[0]);
	printf("value RESOLUTION Y : %d\n", g_data.resolution[1]);
	printf("value CE COLORS  R : %d\n", g_data.ce_color[0]);
	printf("value CE COLORS  G : %d\n", g_data.ce_color[1]);
	printf("value CE COLORS  B : %d\n", g_data.ce_color[2]);
	printf("value FL COLORS  R : %d\n", g_data.fl_color[0]);
	printf("value FL COLORS  G : %d\n", g_data.fl_color[1]);
	printf("value FL COLORS  B : %d\n", g_data.fl_color[2]);
	printf("value NO texture   : %s\n", g_data.no_texture);
	printf("value SO texture   : %s\n", g_data.so_texture);
	printf("value WE texture   : %s\n", g_data.we_texture);
	printf("value EA texture   : %s\n", g_data.ea_texture);
	printf("value SP texture   : %s\n", g_data.sp_texture);
}

int			main(int argc, char *argv[])
{
	int	fd;

	if (argc < 2 || argc > 3)
		ft_error("nb Args\n");
	if (ft_strlen(argv[argc - 1]) < 4)
		ft_error("len Arg\n");
	if (ft_strncmp(".cub", argv[argc - 1] + ft_strlen(argv[argc - 1]) - 4, 4))
		ft_error("cpm Args\n");
	if (argc == 3 &&
	ft_strncmp("--save", argv[1], max_of(6, ft_strlen(argv[1]))))
		ft_error("arg Save\n");
	if ((fd = open(argv[argc - 1], O_RDONLY)) < 0)
		ft_error("Read file\n");
	ft_data(fd);
	ft_map(fd);
	return (0);
}
