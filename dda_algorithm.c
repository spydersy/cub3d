/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:49:10 by abelarif          #+#    #+#             */
/*   Updated: 2021/01/04 06:25:18 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		vabs(int i)
{
	return ((i >= 0) ? (i) : (i * (-1)));
}

float	mydist(float x0, float y0, float x1, float y1)
{
	float	xdist = (x0 - x1) * (x0 - x1);
	float	ydist = (y0 - y1) * (y0 - y1);
	return (sqrtf(xdist + ydist));
}

void	dda(int x0, int y0,  int x1, int y1, int color)
{
	int		dx = x1 - x0;
	int		dy = y1 - y0;

	int		step = ((vabs(dx) > vabs(dy)) ? (abs(dx)) : (vabs(dy)));

	float	xi = dx / (float)step;
	float	yi = dy / (float)step;

	float x = x0;
	float y = y0;

	int		i  = 0;
	
	while (i <= step)
	{
		// if (g_map[(int)y / 20][(int)x / 20] == '2' && (int)x % 20 ==  10 && (int)y % 20== 10)
		// {
			// color = 0xffffff;
		// }
		if (g_map[(int)y / 20][(int)x / 20] == '2' && mydist((int)(x / 20) * 20 + 10, (int)(y / 20) * 20 + 10, x, y) <= 10)
			color = 0x00ff00;
		else
		{
			color = 0xff0000;
		}
			mlx_pixel_put(g_mlx.mlx, g_mlx.win, x, y, color);
		if (g_map[(int)y / 20][(int)x / 20] == '2')
		{
			mlx_pixel_put(g_mlx.mlx, g_mlx.win, (int)(x / 20) * 20 + 10, (int)(y / 20) * 20 + 10, 0xffffff);
		}
		if (!(int)y || !(int)x || !((int)x % 20) || !((int)y % 20) || !(((int)x + 1) % 20) || !(((int)y + 1) % 20))
		{
		
			if (g_map[(int)y / 20][(int)x / 20] == '1' || g_map[(int)y / 20][(int)x / 20] == ' ')
			{
				break;
			}
		}
		if (!(((int)x) % 20) && !(((int)y) % 20) && (g_map[((int)y - 2) / 20][((int)x + 2) / 20] == '1' && g_map[((int)y + 2) / 20][((int)x - 2) / 20] == '1'))
		{
				// printf("4\n");
				break;
		}
		if (!(((int)x + 1) % 20) && !(((int)y) % 20) && (g_map[((int)y - 2) / 20][((int)x - 2) / 20] == '1' && g_map[((int)y + 2) / 20][((int)x + 2) / 20] == '1'))
		{
				// printf("DONE\n");
				break;
		}

			x += xi;
			y += yi;
			i++;
	}
}
