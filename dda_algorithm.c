/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:49:10 by abelarif          #+#    #+#             */
/*   Updated: 2020/12/01 06:11:54 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		vabs(int i)
{
	return ((i >= 0) ? (i) : (i * (-1)));
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
		if (!(int)y || !(int)x || !((int)x % 20) || !((int)y % 20) || !(((int)x + 1) % 20) || !(((int)y + 1) % 20))
		{
			mlx_pixel_put(g_mlx.mlx, g_mlx.win, x, y, color);
		
			if (g_map[(int)y / 20][(int)x / 20] == '1' || g_map[(int)y / 20][(int)x / 20] == ' ')
			{
				break;
			}
		}
		if (!(((int)x + 1) % 20) && !(((int)y + 1) % 20) && (g_map[((int)y - 2) / 20][((int)x - 2) / 20] == '1' && g_map[((int)y + 2) / 20][((int)x + 2) / 20] == '1'))
		{
			ft_error("1");
				printf("1\n");
				break;
		}
		if (!(((int)x) % 20) && !(((int)y + 1) % 20) && (g_map[((int)y - 2) / 20][((int)x + 2) / 20] == '1' && g_map[((int)y + 2) / 20][((int)x - 2) / 20] == '1'))
		{
			ft_error("2");
				printf("2\n");
				break;
		}
		if (!(((int)x) % 20) && !(((int)y) % 20) && (g_map[((int)y - 2) / 20][((int)x + 2) / 20] == '1' && g_map[((int)y + 2) / 20][((int)x - 2) / 20] == '1'))
		{
				printf("4\n");
				break;
		}
		if (!(((int)x + 1) % 20) && !(((int)y) % 20) && (g_map[((int)y - 2) / 20][((int)x - 2) / 20] == '1' && g_map[((int)y + 2) / 20][((int)x + 2) / 20] == '1'))
		{
				printf("3\n");
				break;
		}

			x += xi;
			y += yi;
			i++;
	}
}