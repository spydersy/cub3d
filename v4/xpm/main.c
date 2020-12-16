/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:54:08 by abelarif          #+#    #+#             */
/*   Updated: 2020/12/15 19:29:47 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct  s_img
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_img;

t_img		img;
t_img		new;
void	*mlx_win;
void	*mlx_ptr;

int	size[2] = {128, 128};

int		main()
{
	mlx_ptr  = mlx_init();
	mlx_win  = mlx_new_window(mlx_ptr, 1000, 1000, "test xpm file\n\n\n");
	img.img = mlx_xpm_file_to_image(mlx_ptr, "N.xpm", &size[1], &size[0]);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int	i = -1;
	int	j = -1;
		int c = 0;
		char*dst;
	while (++j < 128)
	{
		i= -1;
		while (++i < 128)
		{
			printf("%d\n", ++c);
			    dst = img.addr + (j * img.line_length + i * (img.bits_per_pixel / 8));
			mlx_pixel_put(mlx_ptr, mlx_win, i + 500, j + 500,     *(unsigned int*)dst);
		}
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 10, 10);
	mlx_loop(mlx_ptr);
	return (0);
}
