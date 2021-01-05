/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:15:08 by abelarif          #+#    #+#             */
/*   Updated: 2020/12/21 10:16:34 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_sprite(float x, float y, int ray)
{

	g_sprite[g_nb_sprite].first_ray = ray;
	g_sprite[g_nb_sprite].start_x = x;
	g_sprite[g_nb_sprite].start_y = y;
	g_sprite[g_nb_sprite].x_map = x / 64;
	g_sprite[g_nb_sprite].y_map = y / 64;
	g_sprite[g_nb_sprite].distance = distance(g_player.x, g_player.y,
	g_sprite[g_nb_sprite].x_map * 64 - 32, g_sprite[g_nb_sprite].y_map * 64 - 32);
	g_sprite[g_nb_sprite].distance = g_sprite[g_nb_sprite].distance
	* cos(vabs(g_player.current - g_player.rotation));
	g_nb_sprite++;
}

void	draw_limits()
{
	int		i;
	int		j;

	i = -1;
	while (++i < g_data.resolution[0])
	{
		j = -1;
		while (++j < g_data.resolution[1])
		{
			if (i % 50 == 0 || j % 50 == 0)
			{
				my_mlx_pixel_put(&img, i, j, 0xffffff);
			}
		}
	}
}

int		calc_y_sprite(float h, float i)
{
	return ((int)((128 * (i - (g_data.resolution[1] - h) / 2)) / h));
}

int		calc_x_sprite(float x)
{
	return ((((int)x  * 2) % 128));
}

void	draw_sprite()
{
	printf("\nstart : %f\n", g_sprite[0].start_x);
	printf("end   : %f\n", g_sprite[0].end_x);

	float		start_ray = min_of(g_sprite[0].first_ray, g_sprite[0].last_ray);	
	float		  end_ray = max_of(g_sprite[0].first_ray, g_sprite[0].last_ray);

	// int xxxx = random();
	float	i;

	char	*adr;
	int		xs;
	int		ys;

	float	h = (64 * g_data.resolution[0]) / g_sprite[0].distance;
			i = (((float)g_data.resolution[1] - h) / 2) + 1;

	while (start_ray++ <= end_ray)
	{
		i = (((float)g_data.resolution[1] - h) / 2) + 1;
		while (i++ < (((float)g_data.resolution[1] + h) / 2))
		{
			xs = calc_x_sprite(g_sprite[0].start_x++);
			ys = calc_y_sprite(h, i);
			
			if (30 < xs && xs < 98)
			{
				xs = xs - 31;
				adr = g_txts.addr + (ys * g_txts.line_length + xs * (g_txts.bits_per_pixel / 8));
				if (*(unsigned int*)adr != 0x980088)
					my_mlx_pixel_put(&img, start_ray, i, *(unsigned int *)adr);
			}
			// my_mlx_pixel_put(&img, start_ray, i, xxxx);
		}
		// printf("i : %f\n", c);
	}
}

void	calc_diff_sprite()
{
	if (vabs(g_sprite[0].start_y - g_sprite[0].end_y)
	<= vabs(g_sprite[0].start_x - g_sprite[0].end_x))
	{
		g_sprite[0].start_x = g_sprite[0].start_y;
		g_sprite[0].end_x = g_sprite[0].end_y;
	}
	else
	{
		g_sprite[0].start_y = g_sprite[0].start_x;
		g_sprite[0].end_y = g_sprite[0].end_x;
	}

	// int	i=0;
	g_sprite[0].diff = vabs(g_sprite[0].start_x - g_sprite[0].end_x);
}

int		check_sprite(float x, float y, int col)
{
	int		x_position;
	int		y_position;
	int		i;

	x_position = x / 64;
	y_position = y / 64;
	i = -1;

	if (g_nb_sprite == 0)
	{

		add_sprite(x, y, col);
		return (0);
	}
	while (++i < g_nb_sprite)
	{
		if (x_position ==  g_sprite[i].x_map && y_position == g_sprite[i].y_map)
		{
			g_sprite[i].end_x = x;
			g_sprite[i].end_y = y;
			g_sprite[i].last_ray = col;
			// print_sprite();
			return (0);
		}
	}
	add_sprite(x, y, col);
	return (0);
}