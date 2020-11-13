/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:21:57 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/13 15:05:49 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	draw_wall(int x, int y)
// {
	// int			x_i;
	// int			y_i;
	// int			x_max;
	// int			y_max;
	
	// x_i = x * 20;
	// y_i = y * 20;
	// x_max = x_i + 19;
	// y_max = x_i + 19;
	// while (x_i <= x_max)
	// {
		// // y_i = y * 20;
		// while (y_i <= y_max)
		// {
			// if (!y_i || !x_i || !(y % 20)
			// || !(x % 20) || !((y + 1) % 20) || !((x + 1) % 20))
				// mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0xffffff);
			// y_i++;
		// }
		// x_i++;
	// }
// }

void	draw_space(int x, int y)
{
	int		x_i;
	int		y_i;
	int		x_max;
	int		y_max;

	x_i = x * 20;
	y_i = y * 20;
	x_max  = x_i + 20;
	y_max  = y_i + 20;
	while (x_i <= x_max)
	{
		y_i = y * 20;
		while (y_i <= y_max)
		{
			if (!y_i || !x_i || !(x_i % 20) || !(y_i % 20) || !((x_i + 1) % 20) || !((y_i + 1) % 20))
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x000000);
			else
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x49979d);
			// printf("y:%6d y_max:%6d x:%6d x_max: %6d\n", y_i, y_max, x_i, x_max);
			y_i++;
		}
		x_i++;
	}
}


void	draw_player(int x, int y)
{
	int		x_i;
	int		y_i;
	int		x_max;
	int		y_max;

	x_i = x * 20;
	y_i = y * 20;
	x_max  = x_i + 20;
	y_max  = y_i + 20;
	while (x_i <= x_max)
	{
		y_i = y * 20;
		while (y_i <= y_max)
		{
			if (!y_i || !x_i || !(x_i % 20) || !(y_i % 20) || !((x_i + 1) % 20) || !((y_i + 1) % 20))
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x000000);
			else
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0xff0000);
			// printf("y:%6d y_max:%6d x:%6d x_max: %6d\n", y_i, y_max, x_i, x_max);
			y_i++;
		}
		x_i++;
	}
}


void	draw_wall(int x, int y)
{
	int		x_i;
	int		y_i;
	int		x_max;
	int		y_max;

	x_i = x * 20;
	y_i = y * 20;
	x_max  = x_i + 20;
	y_max  = y_i + 20;
	while (x_i <= x_max)
	{
		y_i = y * 20;
		while (y_i <= y_max)
		{
			if (!y_i || !x_i || !(x_i % 20) || !(y_i % 20) || !((x_i + 1) % 20) || !((y_i + 1) % 20))
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x000000);
			else
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0xffffff);
			// printf("y:%6d y_max:%6d x:%6d x_max: %6d\n", y_i, y_max, x_i, x_max);
			y_i++;
		}
		x_i++;
	}
}

void	draw(int index, int x, int y)
{
	if (index == 1)
	{
		draw_wall(x, y);
	}
	else if (index == 2)
	{
		draw_space(x, y);
	}
	else if (index == 3)
	{
		draw_player(x, y);
	}
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
	g_mlx.mlx = mlx_init();
	g_mlx.win = mlx_new_window(g_mlx.mlx, 880, 280, "CUB3D");
	draw_map(nb_line, max_len);
	mlx_loop(g_mlx.mlx);
}

