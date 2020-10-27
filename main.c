/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:48:17 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/27 06:59:30 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(const char *str)
{
	ft_putstr_fd("Error\n", 2);
	if (str == NULL)
	{
		ft_putstr_fd(strerror(errno), 2);
	}
	else
	{
		ft_putstr_fd(str, 2);
	}
	//free
	exit(-1);
}

int		main(int argc, char *argv[])
{
	int		fd;

	if (argc < 2 || argc > 3)
		ft_error("Args\n");
	if (argc == 3
	&& ft_strncmp("--save", argv[1], max_of(6, ft_strlen(argv[1]))))
		ft_error("Args\n");
	if (ft_strncmp(".cub", argv[argc - 1] + ft_strlen(argv[argc - 1] - 4), 4))
		ft_error("Args\n");
	if (fd = open(argv[argc - 1], O_RDONLY) == -1)
		ft_error("Args\n");
	ft_init();
	get_data(fd);
	return (0);
}