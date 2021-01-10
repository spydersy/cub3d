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

int		main(int argc, char *argv[])
{
	int		fd;

	fd = check_args_errors(argc, argv);
	g_mlx.mlx = mlx_init();
	ft_data(fd);
	init_text();
	ft_map(fd);
	return (0);
}
