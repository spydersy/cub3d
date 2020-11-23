/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2dmap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 00:52:39 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/23 13:21:49 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	N
W		E
	S
*/

void            my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	draw_space(int x, int y)
{
	int		x_i;
	int		y_i;
	int		x_max;
	int		y_max;

	x_i = x * 20;
	y_i = y * 20;
	x_max  = x_i + 20;
	y_max  = y_i + 20;
	while (x_i <= x_max && x_i < max_len * 20)
	{
		y_i = y * 20;
		while (y_i <= y_max && y_i < nb_line * 20)
		{
			if (!y_i || !x_i || !(x_i % 20) || !(y_i % 20) || !((x_i + 1) % 20) || !((y_i + 1) % 20))
			{
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x000000);
				my_mlx_pixel_put(&img, x_i, y_i, 0x000000);
			}
			else
			{
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x49979d);
				my_mlx_pixel_put(&img, x_i, y_i, 0x49979d);
			}
			y_i++;
		}
		x_i++;
	}
}

void	draw_player(int x, int y)
{
	int		x_i;
	int		y_i;
	int		x_max;
	int		y_max;

	x_i = x * 20;
	y_i = y * 20;
	x_max  = x_i + 20;
	y_max  = y_i + 20;
	while (x_i <= x_max && x_i < max_len * 20)
	{
		y_i = y * 20;
		while (y_i <= y_max && y_i < nb_line * 20)
		{
			// draw_direction(x_i, y_i);
			if (!y_i || !x_i || !(x_i % 20) || !(y_i % 20) || !((x_i + 1) % 20) || !((y_i + 1) % 20))
			{
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x000000);
				my_mlx_pixel_put(&img, x_i, y_i, 0x000000);
			}
			else if ((7 <= y_i % 20 && y_i % 20 <= 12) && (7 <= x_i % 20 && x_i % 20 <= 12))
			{
				if (y_i % 20 == 10)
					g_player.y = y_i;
				if (x_i % 20 == 10)
					g_player.x = x_i;
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x49979d);	//0xff0000
				my_mlx_pixel_put(&img, x_i, y_i, 0x49979d);
			}
			else
			{
					mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x49979d);
					my_mlx_pixel_put(&img, x_i, y_i, 0x49979d);
			}
			// printf("y:%6d y_max:%6d x:%6d x_max: %6d\n", y_i, y_max, x_i, x_max);
			y_i++;
		}
		x_i++;
	}
}

void	draw_wall(int x, int y)
{
	int		x_i;
	int		y_i;
	int		x_max;
	int		y_max;

	x_i = x * 20;
	y_i = y * 20;
	x_max  = x_i + 20;
	y_max  = y_i + 20;
	while (x_i <= x_max && x_i < max_len * 20)
	{
		y_i = y * 20;
		while (y_i <= y_max && y_i < nb_line * 20)
		{
			if (!y_i || !x_i || !(x_i % 20) || !(y_i % 20) || !((x_i + 1) % 20) || !((y_i + 1) % 20))
			{
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x000000);
				// printf("WALL00\n");
				my_mlx_pixel_put(&img, x_i, y_i, 0x000000);
			}
			else
			{
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0xffffff);
				// printf("WALL01\n");
				my_mlx_pixel_put(&img, x_i, y_i, 0xffffff);
			}
			// printf("y:%6d y_max:%6d x:%6d x_max: %6d\n", y_i, y_max, x_i, x_max);
			y_i++;
		}
		x_i++;
	}
}

void	draw_background(int x, int y)
{
	int		x_i;
	int		y_i;
	int		x_max;
	int		y_max;

	x_i = x * 20;
	y_i = y * 20;
	x_max  = x_i + 20;
	y_max  = y_i + 20;
	while (x_i <= x_max && x_i < max_len * 20)
	{
		y_i = y * 20;
		while (y_i <= y_max && y_i < nb_line * 20)
		{
			mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0xf8ff6b);
			my_mlx_pixel_put(&img, x_i, y_i, 0xf8ff6b);
			y_i++;
		}
		x_i++;
	}
}

void	draw(int index, int x, int y)
{
	if (index == 1)
	{
		draw_wall(x, y);
	}
	else if (index == 2)
	{
		draw_space(x, y);
	}
	else if (index == 3)
	{
		draw_player(x, y);
	}
	else if (index == 4)
	{
		draw_background(x, y);
	}
}

void	draw_map(int y_max, int x_max)
{
	int			x;
	int			y;
	static int	first = 1;

	img.img = mlx_new_image(g_mlx.mlx, max_len * 20, 20 * nb_line);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// background(y_max, x_max);
	y = -1;
	while (++y < y_max)
	{
		x = -1;
		while (++x < x_max)
		{
			if (g_map[y][x] == '1')
				draw(1, x, y);
			else if (g_map[y][x] == ' ')
			{
				draw(4, x, y);
			}
			else if (g_map[y][x] == '0' || g_map[y][x] == '2' || (ft_isalpha(g_map[y][x]) && !first))
				draw(2, x, y);
			else if (ft_isalpha(g_map[y][x]))
			{
				draw(3, x, y);
				first = 0;
			}
		}
	}
}

void	ft_move_v(int direction)
{
	int		i;
	int		j;
	
	g_player.y = g_player.y + (direction * 4);

	if ((g_map[g_player.y / 20][g_player.x / 20] == '1' || g_map[g_player.y / 20][g_player.x / 20] == ' '))
	{
		g_player.y = g_player.y - (direction * 4);
	}

	i = g_player.x - 3;
	j = g_player.y - 3;
	if (direction < 0)
	{
		while (i <= g_player.x + 2)
		{
			j = g_player.y - 3;
			while (j <= g_player.y +2)
			{
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, i, j, 0xFF0000);
				j++;
			}
			i++;
		}
	}
	else
	{
			while (i <= g_player.x + 2)
		{
			j = g_player.y - 3;
			while (j <= g_player.y +2)
			{
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, i, j, 0xFF0000);
				j++;
			}
			i++;
		}

	}
}

void	ft_move_h(int direction)
{
	int		i;
	int		j;
	
	g_player.x = g_player.x + (direction * 4);

	if ((g_map[g_player.y / 20][g_player.x / 20] == '1' || g_map[g_player.y / 20][g_player.x / 20] == ' '))
	{
		g_player.x = g_player.x - (direction * 4);
	}
	i = g_player.x - 3;
	j = g_player.y - 3;
	if (direction < 0)
	{
		while (i <= g_player.x + 2)
		{
			j = g_player.y - 3;
			while (j <= g_player.y +2)
			{
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, i, j, 0xFF0000);
				j++;
			}
			i++;
		}
	}
	else
	{
			while (i <= g_player.x + 2)
		{
			j = g_player.y - 3;
			while (j <= g_player.y +2)
			{
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, i, j, 0xFF0000);
				j++;
			}
			i++;
		}

	}
}

int		ft_key(int key,  void *param)
{
	if (param)
	{
		
	}
	if (key == 0) //A linex = 97; A macos = 0
	{
		mlx_clear_window(g_mlx.mlx, g_mlx.win);
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, img.img, 0, 0);
		ft_move_h(-1);
	}
	else if (key == 2) //D linux = 100; A macos = 2
	{
		mlx_clear_window(g_mlx.mlx, g_mlx.win);
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, img.img, 0, 0);
		ft_move_h(1);
	}
	else if (key == 13) //W linux = 119; W macos = 13
	{
		mlx_clear_window(g_mlx.mlx, g_mlx.win);
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, img.img, 0, 0);
		ft_move_v(-1);
	}
	else if (key == 1) //S linux = 115; Smacos = 1
	{
		mlx_clear_window(g_mlx.mlx, g_mlx.win);
		mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, img.img, 0, 0);
		ft_move_v(1);
	}
	return (1);
}

void	cub3d(int nb_line, int max_len)
{
	g_mlx.mlx = mlx_init();
	g_mlx.win = mlx_new_window(g_mlx.mlx, max_len * 20, nb_line * 20, "CUB3D");
	draw_map(nb_line, max_len);
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, img.img, 0, 0);
	mlx_key_hook(g_mlx.win, ft_key, (void*)0);
	mlx_hook(g_mlx.win, 2, 1L<<0, ft_key, (void*)0);
	mlx_expose_hook(g_mlx.win, ft_key, (void*)0);
	// mlx_expose_hook(g_mlx.win, ft_key, (void*)0);
	mlx_loop(g_mlx.mlx);
}

/*
	W	13
	A	0
	S	1
	D	2
	ESC	53
	Q	12
	L	123
	R	124
	H	126
	B	125
*/
