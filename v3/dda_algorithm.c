/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:49:10 by abelarif          #+#    #+#             */
/*   Updated: 2020/12/01 06:36:10 by abelarif         ###   ########.fr       */
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
	int	i = -1;
	float h = 1000 / dist;
	// printf("%ld\n", random());
	while (++i < g_data.resolution[1])
	{
		if (i <= (float)((g_data.resolution[1] - h) / 2))
		{
			// mlx_pixel_put(g_mlx.mlx, g_mlx.win, c, i, 0x4287f5);
			my_mlx_pixel_put(&img, c, i, 0x4287f5);
		}
		else if ((float)((g_data.resolution[1] - h) / 2) < i && i < (float)((g_data.resolution[1] + h) / 2))
		{
			// mlx_pixel_put(g_mlx.mlx, g_mlx.win, c, i, 0x855569);
			my_mlx_pixel_put(&img, c, i, color);
		
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
	int wcolor;
	while (i <= step)
	{
		if (!(int)y || !(int)x || !((int)x % 20) || !((int)y % 20) || !(((int)x + 1) % 20) || !(((int)y + 1) % 20))
		{
			if (g_map[(int)y / 20][(int)x / 20] == '1' || g_map[(int)y / 20][(int)x / 20] == ' ')
			{
				if (!(int)x || !((int)x % 20) || !(((int)x + 1) % 20))
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