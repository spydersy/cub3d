/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:49:10 by abelarif          #+#    #+#             */
/*   Updated: 2020/12/13 01:31:34 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float		vabs(float i)
{
	return ((i >= 0) ? (i) : (i * (-1)));
}
//  0x4287f5 blue
//	0x4e7341 green
//	0x855569 brown


//	E	MAUVE	D
//	S	GREEN	E
//	W	RED  	D
//	N	BLEU 	E

int		calc_y(float h, float i)
{
	return ((int)((128 * (i - (g_data.resolution[1] - h) / 2)) / h));
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
			my_mlx_pixel_put(&img, c, i, 0x4287f5);
		else if ((((float)g_data.resolution[1] - h) / 2) < i && i < (((float)g_data.resolution[1] + h) / 2))
		{
			if (color == 0x8934eb)
			{
				dst = g_txt1.addr + (calc_y(h, i) * g_txt1.line_length + calc_x(y) * (g_txt1.bits_per_pixel / 8));
				// my_mlx_pixel_put(&img, c, i, color);
				my_mlx_pixel_put(&img, c, i, *(unsigned int*)dst);

			}
			else if (color == 0x34eb46)
			{
				dst = g_txt3.addr + (calc_y(h, i) * g_txt1.line_length + calc_x(x) * (g_txt1.bits_per_pixel / 8));
				// my_mlx_pixel_put(&img, c, i, color);
				my_mlx_pixel_put(&img, c, i, *(unsigned int*)dst);
				// my_mlx_pixel_put(&img, c, i, color);
			}
			else if (color == 0xeb4034)
			{
				// my_mlx_pixel_put(&img, c, i, color);
				dst = g_txt2.addr + (calc_y(h, i) * g_txt1.line_length + calc_x(y) * (g_txt1.bits_per_pixel / 8));
				// my_mlx_pixel_put(&img, c, i, color);
				my_mlx_pixel_put(&img, c, i, *(unsigned int*)dst);

			}
			else if (color == 0x34d0eb)
			{
				// my_mlx_pixel_put(&img, c, i, color);
				dst = g_txt4.addr + (calc_y(h, i) * g_txt1.line_length + calc_x(x) * (g_txt1.bits_per_pixel / 8));
				// my_mlx_pixel_put(&img, c, i, color);
				my_mlx_pixel_put(&img, c, i, *(unsigned int*)dst);
			}
		}
		else
			my_mlx_pixel_put(&img, c, i, 0x4e7341);
	}
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

	static int wcolor = 0xffffff;
	int			done = 0;
	while (i <= step)
	{
		if (!(((int)x + 1) % 64) && !(((int)y + 1) % 64) && (g_map[((int)y - 2) / 64][((int)x - 2) / 64] == '1' && g_map[((int)y + 2) / 64][((int)x + 2) / 64] == '1'))
		{
			dist = distance(g_player.x, g_player.y, x, y);
			dist = dist * cos(vabs(g_player.current - g_player.rotation));
			build_wall(dist, col, wcolor, x, y);
			break;
		}
		else if (!(((int)x) % 64) && !(((int)y + 1) % 64) && (g_map[((int)y - 2) / 64][((int)x + 2) / 64] == '1' && g_map[((int)y + 2) / 64][((int)x - 2) / 64] == '1'))
		{
			dist = distance(g_player.x, g_player.y, x, y);
			dist = dist * cos(vabs(g_player.current - g_player.rotation));
			build_wall(dist, col, wcolor, x, y);
			break;
		}
		else if (!(((int)x) % 64) && !(((int)y) % 64) && (g_map[((int)y - 2) / 64][((int)x + 2) / 64] == '1' && g_map[((int)y + 2) / 64][((int)x - 2) / 64] == '1'))
		{
			dist = distance(g_player.x, g_player.y, x, y);
			dist = dist * cos(vabs(g_player.current - g_player.rotation));
			build_wall(dist, col, wcolor, x, y);
			break;
		}
		else if (!(((int)x + 1) % 64) && !(((int)y) % 64) && (g_map[((int)y - 2) / 64][((int)x - 2) / 64] == '1' && g_map[((int)y + 2) / 64][((int)x + 2) / 64] == '1'))
		{
			dist = distance(g_player.x, g_player.y, x, y);
			dist = dist * cos(vabs(g_player.current - g_player.rotation));
			build_wall(dist, col, wcolor, x, y);
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
				break;
			}
		}
		x += xi;
		y += yi;
		i++;
	}
}
