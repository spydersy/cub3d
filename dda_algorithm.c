/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:49:10 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/28 12:37:00 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		vabs(int i)
{
	return ((i >= 0) ? (i) : (i * (-1)));
}

void	dda(int x0, int y0,  int x1, int y1)
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
		if (g_map[(int)y / 20][(int)x / 20] == '1' || g_map[(int)y / 20][(int)x / 20] == ' ')
		{
			break;
		}
		else
		{
			mlx_pixel_put(g_mlx.mlx, g_mlx.win, x, y, 0xff0000);
			x += xi;
			y += yi;
			i++;
		}
	}
}

// int		main(int argc, char *argv[])
// {

// 	int	x0 = atoi(argv[1]);
// 	int	y0 = atoi(argv[2]);
// 	int	x1 = atoi(argv[3]);
// 	int	y1 = atoi(argv[4]);



// 	dda(x0, y0, x1, y1);
// 	return (0);
// }
