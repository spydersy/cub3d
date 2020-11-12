/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:21:57 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/11 11:34:56 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		draw_wall(int x, int x_map, int y)
{
	void *mlx_ptr;
	mlx_pixel_put();
}

void	draw(int index, int x, int y)
{
	static int x_map = 0;

	if (index == 1)
		x_map = draw_wall(x, x_map, y);
	else if (index == 2)
		x = draw_space();
	else if (index == 3)
		x = draw_nothing();
}

void	draw_map(int y_max, int x_max)
{
	int		x;
	int		y;

	y = -1;
	while (++y < y_max)
	{
		x = -1;
		while (++x < x_max)
		{
			if (g_map[y][x] == '1')
				draw(1, x, y);
			else if (g_map[y][x] == '0' || g_map[y][x] == '2')
				draw(2, x, y);
			else if (ft_isalpha(g_map[y][x]))
				draw(3, x, y);
		}
	}
}

void	cub3d(int nb_line, int max_len)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 660 * 2, 280* 2 , "CUB3D");
	draw_map(nb_line, max_len);
	mlx_loop(mlx);
}

