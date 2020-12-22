/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:49:10 by abelarif          #+#    #+#             */
/*   Updated: 2020/12/21 17:34:21 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float		vabs(float i)
{
	return ((i >= 0) ? (i) : (i * (-1)));
}

int		calc_y(float h, float i)
{
	return ((int)((124 * (i - (g_data.resolution[1] - h) / 2)) / h));
}

int		calc_x(float x)
{
	return ((((int)x * 2) % 128));
}

void	build_wall(float dist, int c, int color, float x, float y)
{
	float					h;
	float					i;
	char					*dst;

	h = (64 * g_data.resolution[0]) / dist;
	i = -1;

	while (++i < (float)g_data.resolution[1])
	{
		if (i <= (float)((float)(g_data.resolution[1] - h) / 2))
			my_mlx_pixel_put(&img, c, i, 0x800080);
		else if ((((float)g_data.resolution[1] - h) / 2) < i && i < (((float)g_data.resolution[1] + h) / 2))
		{
			if (color == 0x8934eb)
			{
				dst = g_txt1.addr + (calc_y(h, i) * g_txt1.line_length + calc_x(y) * (g_txt1.bits_per_pixel / 8));
				my_mlx_pixel_put(&img, c, i, *(unsigned int*)dst);

			}
			else if (color == 0x34eb46)
			{
				dst = g_txt3.addr + (calc_y(h, i) * g_txt1.line_length + calc_x(x) * (g_txt1.bits_per_pixel / 8));
				my_mlx_pixel_put(&img, c, i, *(unsigned int*)dst);
			}
			else if (color == 0xeb4034)
			{
				dst = g_txt2.addr + (calc_y(h, i) * g_txt1.line_length + calc_x(y) * (g_txt1.bits_per_pixel / 8));
				my_mlx_pixel_put(&img, c, i, *(unsigned int*)dst);

			}
			else if (color == 0x34d0eb)
			{
				dst = g_txt4.addr + (calc_y(h, i) * g_txt1.line_length + calc_x(x) * (g_txt1.bits_per_pixel / 8));
				my_mlx_pixel_put(&img, c, i, *(unsigned int*)dst);
			}
		}
		else
			my_mlx_pixel_put(&img, c, i, 0xb78443);
	}
}

void	calc_dist_sprite(void)
{
	int		i;
	float	min_di;
	i = -1;
	
	while (++i < g_nb_sprite)
	{
		// g_sprite[i].measure = 0;
		if (vabs(g_sprite[i].start_y - g_sprite[i].end_y)
		> vabs(g_sprite[i].start_x - g_sprite[i].end_x))
		{
			g_sprite[i].start_y = g_sprite[i].start_x;
			g_sprite[i].end_y = g_sprite[i].end_x;
		}
		else
		{
			g_sprite[i].start_x = g_sprite[i].start_y;
			g_sprite[i].end_x = g_sprite[i].end_y;
		}
		printf("dist : %f, %lu\n", distance(g_sprite[i].start_x, 0, g_sprite[i].end_x, 0), random());
		g_sprite[i].distance = distance(g_player.x, g_player.y,
		vabs((g_sprite[i].start_y - g_sprite[i].end_y) / 2),
		g_sprite[i].end_x);
	}
}

void	add_sprite(float x, float y, int ray, int i)
{
	g_sprite[g_nb_sprite].start_x = x;
	g_sprite[g_nb_sprite].start_y = y;
	g_sprite[g_nb_sprite].end_x = x;
	g_sprite[g_nb_sprite].end_y = y;
	g_sprite[g_nb_sprite].first_ray = ray;
	g_sprite[g_nb_sprite].last_ray = ray;
	g_sprite[g_nb_sprite].xp = x / 64;
	g_sprite[g_nb_sprite].yp = y / 64;
	g_nb_sprite++;
	calc_dist_sprite();
}

int		check_sprite(float x, float y, int ray)
{
	int		x_position;
	int		y_position;
	int		i;

	i = -1;
	x_position = x / 64;
	y_position = y / 64;
	if (g_nb_sprite == 0)
	{
		add_sprite(x, y, ray, 0);
		return (0);
	}
	while (++i < g_nb_sprite)
	{
		if (x_position == g_sprite[i].xp && y_position == g_sprite[i].yp)
		{
			printf("\nend_x %f\n", g_sprite[i].end_x = x);
			printf("end_y %f\n\n", g_sprite[i].end_y = y);
			g_sprite[i].last_ray = ray;
			return (0);
		}
	}
	add_sprite(x, y, ray, i);
	return (0);
}

void	build_sprite(int col)
{
	// if ()
	// {
		
	// }
}

void	dda(float x0, float y0,  float x1, float y1, int color, int col)
{
	float		dx = x1 - x0;
	float		dy = y1 - y0;

	int		step = ((vabs(dx) > vabs(dy)) ? (vabs(dx)) : (vabs(dy)));

	float	xi = dx / (float)step;
	float	yi = dy / (float)step;

	float x = x0;
	float y = y0;

	int		i  = 0;

	static int wcolor;
	int			done = 0;
	while (i <= step)
	{
		if (g_map[(int)y / 64][(int)x / 64] == '2')
		{
			check_sprite(x, y, col);
		}
		if (!(((int)x + 1) % 64) && !(((int)y + 1) % 64) && (g_map[((int)y - 2) / 64][((int)x - 2) / 64] == '1' && g_map[((int)y + 2) / 64][((int)x + 2) / 64] == '1'))
		{
			dist = distance(g_player.x, g_player.y, x, y);
			dist = dist * cos(vabs(g_player.current - g_player.rotation));
			build_wall(dist, col, wcolor, x, y);
			build_sprite(col);
			break;
		}
		else if (!(((int)x) % 64) && !(((int)y + 1) % 64) && (g_map[((int)y - 2) / 64][((int)x + 2) / 64] == '1' && g_map[((int)y + 2) / 64][((int)x - 2) / 64] == '1'))
		{
			dist = distance(g_player.x, g_player.y, x, y);
			dist = dist * cos(vabs(g_player.current - g_player.rotation));
			build_wall(dist, col, wcolor, x, y);
			build_sprite(col);
			break;
		}
		else if (!(((int)x) % 64) && !(((int)y) % 64) && (g_map[((int)y - 2) / 64][((int)x + 2) / 64] == '1' && g_map[((int)y + 2) / 64][((int)x - 2) / 64] == '1'))
		{
			dist = distance(g_player.x, g_player.y, x, y);
			dist = dist * cos(vabs(g_player.current - g_player.rotation));
			build_wall(dist, col, wcolor, x, y);
			build_sprite(col);
			break;
		}
		else if (!(((int)x + 1) % 64) && !(((int)y) % 64) && (g_map[((int)y - 2) / 64][((int)x - 2) / 64] == '1' && g_map[((int)y + 2) / 64][((int)x + 2) / 64] == '1'))
		{
			dist = distance(g_player.x, g_player.y, x, y);
			dist = dist * cos(vabs(g_player.current - g_player.rotation));
			build_wall(dist, col, wcolor, x, y);
			build_sprite(col);
			break;
		}
		else if (!y || !x || !((int)x % 64) || !((int)y % 64) || !(((int)x + 1) % 64) || !(((int)y + 1) % 64))
		{
			if (g_map[(int)y / 64][(int)x / 64] == '1' || g_map[(int)y / 64][(int)x / 64] == ' ')
			{
				if (!((int)x % 64) && ((int)y % 64) && (((int)y + 1) % 64))
					wcolor = 0x8934eb;
				else if (!((int)y % 64) && ((int)x % 64) && (((int)x + 1) % 64))
					wcolor = 0x34eb46;
				else if(!(((int)x + 1) % 64) && ((int)y % 64) && (((int)y + 1) % 64))
					wcolor = 0xeb4034;
				else if(!(((int)y + 1) % 64) && ((int)x % 64) && (((int)x + 1) % 64))
					wcolor = 0x34d0eb;
				dist = distance(g_player.x, g_player.y, x, y);
				dist = dist * cos(vabs(g_player.current - g_player.rotation));
				build_wall(dist, col, wcolor, x, y);
				build_sprite(col);
				break;
			}
		}
		x += xi;
		y += yi;
		i++;
	}
}
