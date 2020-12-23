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
	g_sprite[g_nb_sprite].xp = x / 64;
	g_sprite[g_nb_sprite].yp = y / 64;
	g_sprite[g_nb_sprite].distance = distance(g_player.x, g_player.y, x, y);
	g_nb_sprite++;
}

// void	print_sprite()
// {
// 	int		i;

// 	i = -1;
// 	printf("\n\nSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n");
// 	while (++i < g_nb_sprite)
// 	{
// 		printf("\n******\ndistance : %f, sx : %f, ex : %f, sy : %f, ey : %f,  sr : %d, er : %d\n******\n", g_sprite[i].distance, g_sprite[i].start_x, g_sprite[i].end_x, g_sprite[i].start_y, g_sprite[i].end_y, g_sprite[i].first_ray, g_sprite[i].last_ray);

// 	}
// 	printf("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\n\n");
// }

void		draw_sprite()
{
	
}

void	calc_diff_sprite()
{
	if (vabs(g_sprite[0].start_y - g_sprite[0].end_y)
	>= vabs(g_sprite[0].start_x - g_sprite[0].end_x))
	{
		g_sprite[0].start_x = g_sprite[0].start_y;
		g_sprite[0].end_x = g_sprite[0].end_y;
	}
	else
	{
		g_sprite[0].start_y = g_sprite[0].start_x;
		g_sprite[0].end_y = g_sprite[0].end_x;
	}

	int	i=0;
	g_sprite[0].diff_max = vabs(g_sprite[0].start_x - g_sprite[0].end_x);
	printf("\nDIFF00\n");
	printf("nb : %d\n", g_nb_sprite);
	printf("sr : %5d, er : %5d, diff : %5d\n",g_sprite[i].first_ray, g_sprite[i].last_ray, g_sprite[i].last_ray - g_sprite[i].first_ray);
	printf("ms : %5d, me : %5d, diff : %5d\n", ((int)g_sprite[0].start_y) % 64, (int)g_sprite[0].end_y % 64, ((int)g_sprite[0].start_y) % 64 - (int)g_sprite[0].end_y % 64);
	printf("DIFF11\n\n");
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
		if (x_position ==  g_sprite[i].xp && y_position == g_sprite[i].yp)
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