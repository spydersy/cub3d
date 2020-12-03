
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2dmap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 00:52:39 by abelarif          #+#    #+#             */
/*   Updated: 2020/12/02 17:51:43 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float		normalize(float angle)
{
	while (angle < 0)
	{
		angle += PI * 2;
	}
	while (angle >= PI * 2)
	{
		angle -= PI * 2;
	}
	return angle;
}

void            my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

float	distance(float x0, float y0, float x1, float y1)
{
	float		distance;

	distance = sqrtf((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
	return (distance);
}

void	draw_space(int x, int y)
{
	int		x_i;
	int		y_i;
	int		x_max;
	int		y_max;

	x_i = x * 64;
	y_i = y * 64;
	x_max  = x_i + 64;
	y_max  = y_i + 64;
	while (x_i <= x_max && x_i < max_len * 64)
	{
		y_i = y * 64;
		while (y_i <= y_max && y_i < nb_line * 64)
		{
			if (!y_i || !x_i || !(x_i % 64) || !(y_i % 64) || !((x_i + 1) % 64) || !((y_i + 1) %64))
			{
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x000000);
				// my_mlx_pixel_put(&img, x_i, y_i, 0x000000);
			}
			else
			{
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x49979d);
				// my_mlx_pixel_put(&img, x_i, y_i, 0x49979d);
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

	x_i = x * 64;
	y_i = y * 64;
	x_max  = x_i + 64;
	y_max  = y_i + 64;
	while (x_i <= x_max && x_i < max_len * 64)
	{
		y_i = y * 64;
		while (y_i <= y_max && y_i < nb_line * 64)
		{
			if (!y_i || !x_i || !(x_i % 64) || !(y_i % 64) || !((x_i + 1) % 64) || !((y_i + 1) % 64))
			{
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x000000);
				// my_mlx_pixel_put(&img, x_i, y_i, 0x000000);
			}
			else if ((7 <= y_i % 64 && y_i % 64 <= 12) && (7 <= x_i % 64 && x_i % 64 <= 12))
			{
				if (y_i % 64 == 10)
					g_player.y = y_i;
				if (x_i % 64 == 10)
					g_player.x = x_i;
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x49979d);	//0xff0000
				// my_mlx_pixel_put(&img, x_i, y_i, 0x49979d);
			}
			else
			{
					mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x49979d);
					// my_mlx_pixel_put(&img, x_i, y_i, 0x49979d);
			}
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

	x_i = x * 64;
	y_i = y * 64;
	x_max  = x_i + 64;
	y_max  = y_i + 64;
	while (x_i <= x_max && x_i < max_len * 64)
	{
		y_i = y * 64;
		while (y_i <= y_max && y_i < nb_line * 64)
		{
			if (!y_i || !x_i || !(x_i % 64) || !(y_i % 64) || !((x_i + 1) % 64) || !((y_i + 1) % 64))
			{
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0x000000);
				// my_mlx_pixel_put(&img, x_i, y_i, 0x000000);
			}
			else
			{
				mlx_pixel_put(g_mlx.mlx, g_mlx.win, x_i, y_i, 0xffffff);
				// my_mlx_pixel_put(&img, x_i, y_i, 0xffffff);
			}
			y_i++;
		}
		x_i++;
	}
}

void	draw_background(int x, int y)
{
	if (x < y)
	{
		
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

void	get_new_position(float x0, float y0, float x1, float y1, int nb_steps)
{
	float		dx = x1 - x0;
	float		dy = y1 - y0;

	int		step = ((vabs(dx) > vabs(dy)) ? (vabs(dx)) : (vabs(dy)));

	float	xi = dx / (float)step;
	float	yi = dy / (float)step;

	float x = x0;
	float y = y0;

	int		i  = 0;
	nb_steps =((nb_steps <= step) ? (nb_steps) : (step));
	while (i <= nb_steps)
	{
		x += xi;
		y += yi;
		i++;
	}
	if (!(g_map[(int)y / 64][(int)x / 64] == '1' || g_map[(int)y / 64][(int)x /64] == ' '))
	{
		g_player.x = x;
		g_player.y = y;
	}
}

void	ft_move_v(int direction)
{

	get_new_position(
	g_player.x,
	g_player.y,
	(g_player.x + (direction * -1) * cosf(g_player.rotation) * 100000000),
	(g_player.y + (direction * -1) * sinf(g_player.rotation) * 100000000), 10);
	// mlx_pixel_put(g_mlx.mlx, g_mlx.win, g_player.x, g_player.y, 0xff0000);
}

void	ft_move_h(int direction)
{

	get_new_position(g_player.x,
		g_player.y,
		(g_player.x + (direction) * cosf(g_player.rotation + PI / 2) * 100000000),
		(g_player.y + (direction) * sinf(g_player.rotation + PI / 2) * 100000000), 10);
	// mlx_pixel_put(g_mlx.mlx, g_mlx.win, g_player.x, g_player.y, 0xff0000);
}

int		ft_key(int key,  void *param)
{

	if (param)
	{
		
	}
	
	if (key == 65361)	//- linux = 65361, macos 123; //rotation
	{
		mlx_clear_window(g_mlx.mlx, g_mlx.win);
		// mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, img.img, 0, 0);
		g_player.rotation = g_player.rotation  - PI / 100;
		g_player.rotation = normalize(g_player.rotation);
	}
	else if (key == 65363)	//+ linux = 65363, macos 124; //rotation
	{
		mlx_clear_window(g_mlx.mlx, g_mlx.win);
		// mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, img.img, 0, 0);
		g_player.rotation = (g_player.rotation  + PI / 100);
		g_player.rotation = normalize(g_player.rotation);
	}

	if (key == 97) //A linex = 97; A macos = 0
	{
		mlx_clear_window(g_mlx.mlx, g_mlx.win);
		// mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, img.img, 0, 0);
		ft_move_h(-1);
	}
	else if (key == 100) //D linux = 100; A macos = 2
	{
		mlx_clear_window(g_mlx.mlx, g_mlx.win);
		// mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, img.img, 0, 0);
		ft_move_h(1);
	}
	else if (key == 119) //W linux = 119; W macos = 13
	{
		mlx_clear_window(g_mlx.mlx, g_mlx.win);
		// mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, img.img, 0, 0);
		ft_move_v(-1);
	}
	else if (key == 115) //S linux = 115; Smacos = 1
	{
		mlx_clear_window(g_mlx.mlx, g_mlx.win);
		ft_move_v(1);
	}

	/*START*/
		int		step = -1;
	float	old_angle = g_player.rotation;

	float	teta = PI / (3 * g_data.resolution[0]);
	
	g_player.rotation = g_player.rotation - PI / 6;
	while (++step < g_data.resolution[0])
	{
		dda(g_player.x,
		g_player.y,
		(int)(g_player.x + cosf(g_player.rotation) * 100000000),
		(int)(g_player.y + sinf(g_player.rotation) * 100000000), 0XFF0000, step);
		g_player.rotation = g_player.rotation + teta;
	}
	/* END */
	g_player.rotation = old_angle;
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, img.img, 0, 0);
	return (0);
}

void	cub3d(int nb_line, int max_len)
{
	g_mlx.mlx = mlx_init();
	g_data.resolution[0] = 1000;
	g_data.resolution[1] = 1000;
	
	if (nb_line && max_len)
	{
		
	}
	g_mlx.win = mlx_new_window(g_mlx.mlx, g_data.resolution[0], g_data.resolution[1], "CUB3D");
	draw_map(nb_line, max_len);
	img.img = mlx_new_image(g_mlx.mlx, g_data.resolution[0], g_data.resolution[1]);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_key_hook(g_mlx.win, ft_key, (void*)0);
	mlx_hook(g_mlx.win, 2, 1L << 0, ft_key, (void*)0);
	mlx_expose_hook(g_mlx.win, ft_key, (void*)0);
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
