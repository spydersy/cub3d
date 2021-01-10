/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:12:35 by abelarif          #+#    #+#             */
/*   Updated: 2021/01/09 16:54:52 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		max_of(int i, int j)
{
	return ((i < j) ? (j) : (i));
}

int		min_of(int i, int j)
{
	return ((i > j) ? (j) : (i));
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (str == NULL)
		strerror(errno);
	else
	{
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\n', 2);
	}
	exit(-1);
}
int		check_args_errors(int argc, char *argv[])
{
	int		fd;

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
	return (fd);
}

void	print_data()
{

	printf("resolution : (%d, %d)\n", g_data.resolution[0], g_data.resolution[1]);
	printf("NO TEXTURE : >>%s<<\n", g_data.no_texture);
	printf("SO TEXTURE : >>%s<<\n", g_data.so_texture);
	printf("WE TEXTURE : >>%s<<\n", g_data.we_texture);
	printf("EA TEXTURE : >>%s<<\n", g_data.ea_texture);
	printf("SP TEXTURE : >>%s<<\n", g_data.sp_texture);
	printf("CE COLOR   : (%d, %d, %d)\n", g_data.ce_color[0], g_data.ce_color[1], g_data.ce_color[2]);
	printf("FL COLOR   : (%d, %d, %d)\n", g_data.fl_color[0], g_data.fl_color[1], g_data.fl_color[2]);

}

int		main(int argc, char *argv[])
{
	int		fd;

	fd = check_args_errors(argc, argv);
	g_mlx.mlx = mlx_init();
	ft_data(fd);
	// print_data();
	init_text();
	ft_map(fd);
	return (0);
}
