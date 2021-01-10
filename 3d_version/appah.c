#include "cub3d.h"

float	deg(float x)
{
	return ((180 / M_PI) * x);
}

// void	init_sprite(void)
// {
// 	int i;
// 	int j;
// 	int k;
// 	int w;
// 	int h;
// 	k = 0;
// 	i = -1;
// 	g_sp = malloc(sizeof(t_sprite) * (g_s_count + 1));
// 	if (!(g_si.img = mlx_xpm_file_to_image(g_vars.mlx, g_s, &w, &h)))
// 		texture_error(5);
// 	g_si.addr = mlx_get_data_addr(g_si.img, &g_si.bpp, &g_si.ll, &g_si.en);
// 	while (g_map_array[++i] && (j = -1) && (k < g_s_count))
// 	{
// 		while (g_map_finished[i][++j] && (k < g_s_count))
// 			if (g_map_finished[i][j] == '2')
// 			{
// 				g_sp[k].x = (float)((j + 0.5) * 64);
// 				g_sp[k].y = (float)((i + 0.5) * 64);
// 				g_sp[k].dist = sqrtf(((g_sp[k].x) - g_p.x) * ((g_sp[k].x)
// 					- g_p.x) + ((g_sp[k].y) - g_p.y) * ((g_sp[k].y) - g_p.y));
// 				k++;
// 			}
// 	}
// }

// void	to_sort(void)
// {
// 	int				i;
// 	int				j;
// 	t_sprite		tmp;
// 	i = 0;
// 	while (i < g_s_count - 1)
// 	{
// 		j = i;
// 		while (j < g_s_count - 1)
// 		{
// 			if (g_sp[j].dist < g_sp[j + 1].dist)
// 			{
// 				tmp = g_sp[j];
// 				g_sp[j] = g_sp[j + 1];
// 				g_sp[j + 1] = tmp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	draw_sprite(int id)
{
	int		i;
	int		j;
	int		c;
	int		*l9alwa;
	float	size;

    i = -1;
	size = g_sprite[id].size;
	l9alwa = (int*)g_txts.addr;
	while (++i < size - 1 && (j = -1))
	{
		if (g_sprite[id].xof + i <= 0 || g_sprite[id].xof + i > g_data.resolution[0] - 1)
			continue ;
		// if (g_rays[(int)(g_sp[id].xof + i)].dist <= g_sp[id].dist)
        if (g_wall_distances[(int)(g_sprite[id].xof + i)] <= g_sprite[id].distance)
			continue ;
		while (++j < size - 1)
		{
			if (g_sprite[id].yof + j <= 0 || g_sprite[id].yof + j > g_data.resolution[1] - 1)
				continue ;
			c = l9alwa[(int)((64) *
					(64 * j / (int)size) + (64 * i / (int)size))];
			if (c != l9alwa[0])
            {
            	my_mlx_pixel_put(&img, i + g_sprite[id].xof, j + g_sprite[id].yof, c);
            }
        }
	}
}

void	to_sprite(void)
{
	float	angle;
	int		k;

	k = -1;
	// to_sort();
	angle = 0;
	while (++k < g_nb_sprite)
	{
		angle = atan2f(g_sprite[k].y - g_player.y, g_sprite[k].x - g_player.x);
		while (angle - g_player.rotation > M_PI)
			angle -= 2 * M_PI;
		while (angle - g_player.rotation < -M_PI)
			angle += 2 * M_PI;
		g_sprite[k].size = (float)((g_data.resolution[0] / g_sprite[k].distance) * 64);
		g_sprite[k].yof = (float)(g_data.resolution[1] / 2 - g_sprite[k].size / 2);
		g_sprite[k].xof = (float)(((deg(angle) - deg(g_player.rotation)) * g_data.resolution[0])
		/ 64 + ((g_data.resolution[0] / 2) - (int)g_sprite[k].size / 2));
		draw_sprite(k);
	}
}
