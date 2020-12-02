/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:49:10 by abelarif          #+#    #+#             */
/*   Updated: 2020/12/02 06:41:39 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		vabs(int i)
{
	return ((i >= 0) ? (i) : (i * (-1)));
}
//  0x4287f5 blue
//	0x4e7341 green
//	0x855569 brown

// void	build_wall(float dist, int c)
// {
// 	float		ry2;
// 	float		h;
// 	float		h2;

// 	h = 500 / dist;
// 	h2  = h / 2;
// 	ry2 = g_data.resolution[1] / 2;
// 	while (ry2-- >= 0)
// 	{
// 		if (h2-- > 0)
// 		{
// 			mlx_pixel_put(g_mlx.mlx, g_mlx.win, c, ry2, 0x855569);
// 		}
// 		else
// 		{
// 			mlx_pixel_put(g_mlx.mlx, g_mlx.win, c, ry2, 0x4287f5);
// 		}
// 	}
// 	h2  = h / 2;
// 	ry2 = g_data.resolution[1] / 2;
// 	int	i=0;
// 	while (ry2++ <= g_data.resolution[1])
// 	{
// 		++i;
// 		// printf("%ld\n", random());
// 		if (h2++ < h)
// 		{
// 			mlx_pixel_put(g_mlx.mlx, g_mlx.win, c, ry2, 0x855569);
// 		}
// 		else
// 		{
// 			mlx_pixel_put(g_mlx.mlx, g_mlx.win, c, ry2, 0x4e7341);
// 		}
// 	}
// 		printf("%d\n", i);

// }

void	build_wall(float dist, int c, int color)
{
	float h = (64 * g_data.resolution[0]) / dist;
	if (color)
	{
		
	}
	// printf("%ld\n", random());
		float	i = -1;
		while (++i < (float)g_data.resolution[1])
		{
			if (i <= (float)((float)(g_data.resolution[1] - h) / 2))
			{
				// mlx_pixel_put(g_mlx.mlx, g_mlx.win, c, i, 0x4287f5);
				my_mlx_pixel_put(&img, c, i, 0x4287f5);
			}
			else if ((((float)g_data.resolution[1] - h) / 2) < i && i < (((float)g_data.resolution[1] + h) / 2))
			{
				my_mlx_pixel_put(&img, c, i, 0x43454a);
			}
			else
			{
				// mlx_pixel_put(g_mlx.mlx, g_mlx.win, c, i, 0x4e7341);
				my_mlx_pixel_put(&img, c, i, 0x4e7341);
			}
		}
}

void	dda(float x0, float y0,  float x1, float y1, int color, int col)
{
	if (color)
	{
		
	}
	
	float		dx = x1 - x0;
	float		dy = y1 - y0;

	int		step = ((vabs(dx) > vabs(dy)) ? (vabs(dx)) : (vabs(dy)));

	float	xi = dx / (float)step;
	float	yi = dy / (float)step;

	float x = x0;
	float y = y0;

	int		i  = 0;

	int wcolor;
	while (i <= step)
	{
		if (!y || !x || !((int)x % 64) || !((int)y % 64) || !(((int)x + 1) % 64) || !(((int)y + 1) % 64))
		{
			if (g_map[(int)y / 64][(int)x / 64] == '1' || g_map[(int)y / 64][(int)x / 64] == ' ')
			{
				if (!(int)x || !((int)x % 64) || !(((int)x + 1) % 64))
				{
					wcolor = 0xff0000;
				}
				else
					wcolor = 0xf5ce42;
				dist = distance(g_player.x, g_player.y, x, y);
				build_wall(dist, col, wcolor);
				break;
			}
		}
		x += xi;
		y += yi;
		i++;
	}
}

	// while (i <= step)
	// {
		// if (g_map[(int)y / 20][(int)x / 20] == '1' || g_map[(int)y / 20][(int)x / 20] == ' ')
		// {
			// ddai++;
			// break;
		// }
		// else
		// {
			// mlx_pixel_put(g_mlx.mlx, g_mlx.win, x, y, color);
			// x += xi;
			// y += yi;
			// i++;
		// }
	// }