/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:49:32 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/22 12:49:33 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main()
{
	char	*line;
	int	r;
	int	fd;

		fd = open("get_next_line.c", O_RDONLY);
	r = get_next_line(fd, &line);
	printf("%d | %s\n", r, line);
	return (0);
}
