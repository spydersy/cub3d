// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/12/15 18:54:08 by abelarif          #+#    #+#             */
// /*   Updated: 2020/12/17 05:05:15 by abelarif         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../mlx.h"
// #include <stdio.h>

// typedef struct  s_img
// {
//     void        *img;
//     char        *addr;
//     int         bits_per_pixel;
//     int         line_length;
//     int         endian;
// }               t_img;

// t_img		img;
// t_img		new;
// void	*mlx_win;
// void	*mlx_ptr;

// int	size[2] = {128, 128};

// int		main()
// {
// 	mlx_ptr  = mlx_init();
// 	mlx_win  = mlx_new_window(mlx_ptr, 1000, 1000, "test xpm file\n\n\n");
// 	img.img = mlx_xpm_file_to_image(mlx_ptr, "N.xpm", &size[1], &size[0]);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	int	x = -1;
// 	int	y = -1;
// 	while (++y < 1000)
// 	{
// 		x = -1;
// 		while (++x < 1000)
// 		{
// 			mlx_pixel_put(mlx_ptr, mlx_win, x, y, 0xffffff);
// 		}
// 	}
// 	int	i = -1;
// 	int	j = -1;
// 		int c = 0;
// 		char*dst;
// 	while (++j < 125)
// 	{
// 		i= -1;
// 		while (++i < 128)
// 		{
// 			    dst = img.addr + (j * img.line_length + i * (img.bits_per_pixel / 8));
// 			mlx_pixel_put(mlx_ptr, mlx_win, i + 10 + 129, j + 10,     *(unsigned int*)dst);
// 		}
// 	}
// 	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 10, 10);
// 	mlx_loop(mlx_ptr);
// 	return (0);
// }
