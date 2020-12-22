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

void	change_order(int id, int index)
{
	int		i;

	i = -1;
	while (++i < g_nb_sprite)
	{
		if (g_sprite[i].id >= id && i != index)
		{
			g_sprite[i].id++;
		}
	}
}

int	    sort_sprite()
{
	int		i;
	int		j;

	if (g_nb_sprite == 1)
	{
		g_sprite[g_nb_sprite - 1].id = 1;
		return (0);
	}
	j = 0;
	while (1)
	{
		j++;
		i = -1;
		while (++i < g_nb_sprite)
		{
			if (j == g_sprite[i].id)
			{
				if (g_sprite[g_nb_sprite - 1].distance >= g_sprite[i].distance)
				{
					g_sprite[g_nb_sprite - 1].id = g_sprite[i].id;
					g_sprite[i].id++;
					change_order(g_sprite[i].id, i);
					return (0);
				}
			}
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
	g_sprite[g_nb_sprite].distance = distance(g_player.x, g_player.y, x, y);
	g_nb_sprite++;
	sort_sprite();
}

void	print_sprite()
{
	int		i;

	i = -1;
	printf("\n\nSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n");
	while (++i < g_nb_sprite)
	{
		printf("id : %d, distance : %f\n", g_sprite[i].id, g_sprite[i].distance);
	}
	printf("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\n\n");
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
			// printf("nb_sprite : %d %lu\n", g_nb_sprite, random());
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
	print_sprite();
	return (0);
}