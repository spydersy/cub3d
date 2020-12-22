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

int	    sort_sprite()
{
	int		i;

	i = -1;
	if (g_nb_sprite == 1)
	{
		g_sprite[g_nb_sprite - 1].id = 1;
		return (0);
	}
	while (++i < g_nb_sprite)
	{
		if (g_sprite[g_nb_sprite - 1].distance >= g_sprite[i].distance)
		{
			g_sprite[g_nb_sprite - 1].id = g_sprite[i].id;
			g_sprite[i].id++;
		}
	}
	
}

void	add_sprite(float x, float y, int ray)
{
	g_sprite[g_nb_sprite].first_ray = ray;
	g_sprite[g_nb_sprite].start_x = x;
	g_sprite[g_nb_sprite].start_y = y;
	g_sprite[g_nb_sprite].xp = x / 64;
	g_sprite[g_nb_sprite].yp = y / 64;
	g_nb_sprite++;

	sort_sprite();
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
			return (0);
		}
	}
	add_sprite(x, y, col);
	return (0);
}