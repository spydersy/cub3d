/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:19:35 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/25 13:39:13 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "../mlx.h"

#define PI 3.142857

int			main()
{
	void		*mlx_ptr;
	void		*mlx_win;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 800, 800, "TETA");
	
	int			xp = 399;
	int			yp = 399;
	int			i  = 100;

	float		t;

	t = (15 * PI) / 180;
	while (--i)
	{
		mlx_pixel_put(mlx_ptr, mlx_win, xp, yp - i, 0xff0000);
		mlx_pixel_put(mlx_ptr,mlx_win,
									(int)(xp * sinf(t) + (yp - i) * cosf(t)),
									(int)(xp * cosf(t) - (yp - i) * sinf(t)), 0x0000ff);
	}
	mlx_loop(mlx_ptr);
	return (0);
}

