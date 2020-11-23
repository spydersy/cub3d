/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:49:10 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/23 14:37:13 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dda_algorithm.h"
#include <math.h>
#include <stdlib.h>

int		vabs(int i)
{
	return ((i >= 0) ? (i) : (i * (-1)));
}
void	dda(int x0, int y0,  int x1, int y1)
{
	void	*mlx_ptr;
	void	*mlx_win;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 800, 800, "DDA ALGORITHM");

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
		mlx_pixel_put(mlx_ptr, mlx_win, x, y, 0xff0000);
		x += xi;
		y += yi;
		i++;
	}
	mlx_loop(mlx_ptr);
}

int		main(int argc, char *argv[])
{

	int	x0 = atoi(argv[1]);
	int	y0 = atoi(argv[2]);
	int	x1 = atoi(argv[3]);
	int	y1 = atoi(argv[4]);



	dda(x0, y0, x1, y1);
	return (0);
}
