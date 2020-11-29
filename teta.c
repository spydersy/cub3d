/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teta.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:19:35 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/29 02:52:45 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <math.h>
// #include "../mlx.h"

// #define PI 3.14159265359

// int			main()
// {
	// void		*mlx_ptr;
	// void		*mlx_win;

	// mlx_ptr = mlx_init();
	// mlx_win = mlx_new_window(mlx_ptr,1920,1080, "TETA");
	
	// int			xp = 127;
	// int			yp = 399;
	// int			i  = 0;

	// float		t;

	// t = (270 * PI) / 180;
	// while (++i < 100)
	// {
		// mlx_pixel_put(mlx_ptr, mlx_win, xp, yp - i, 0xff0000);
		// // mlx_pixel_put(mlx_ptr,mlx_win,
		// // 							(int)(xp * cosf(t) - (yp - i) * sinf(t)),
		// // 							(int)(xp * sinf(t) + (yp - i) * cosf(t)), 0x0000ff);
				// mlx_pixel_put(mlx_ptr,mlx_win,
									// (int)(xp + (i * cosf(t) - (i) * sinf(t))),
									// (int)(yp + (i * sinf(t) + (i) * cosf(t))), 0x0000ff);
		// printf("(x, y) = (%d, %d)\n", (int)(xp * cosf(t) - (yp - i) * sinf(t)),(int)(xp * sinf(t) + (yp - i) * cosf(t)));
	// }
	// mlx_loop(mlx_ptr);
	// return (0);
// }

