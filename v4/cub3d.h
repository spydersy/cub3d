/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:14:32 by abelarif          #+#    #+#             */
/*   Updated: 2020/12/13 00:54:20 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "./link.h"
#include "./GNL/get_next_line.h"
#include "./LBFT/libft.h"
#include "mlx.h"


#define PI 3.14159265359
typedef struct	s_data
{
	int			resolution[2];
	int			nb[8];
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*sp_texture;
	int			ce_color[3];
	int			fl_color[3];
}				t_data;

typedef	struct	s_player
{
	float			x;
	float			y;
	float			current;
	float			rotation;
	int				col;
}				t_player;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*nmlx;
	void		*nwin;

}				t_mlx;

typedef struct  s_img
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_img;

char			**g_map;
t_player		g_player;
t_data			g_data;
t_liste			*g_liste;
t_mlx			g_mlx;
t_img			img;
int				nb_line;
int				max_len;

float				dist;

void				my_mlx_pixel_put(t_img *data, int x, int y, int color);
float				distance(float x0, float y0, float x1, float y1);
float				vabs(float i);
void                ft_error (char *str);
void				dda(float x0, float y0,  float x1, float y1, int color, int col);
int                 max_of(int i, int j);
void                ft_data(int fd);
char				**my_split(char const *s, char c, char d);
void        		ft_map(int fd);
int					skip_line(const char *line);
int					get_resolution(char **content);
void				get_cl(int r, int g, int b);
void				get_fl(int r, int g, int b);
int					get_rgb(int index, const char *str);
int					get_path(int index, const char *str);
void				ft_init(void);
int					all_digit(const char *str);
int					skip_line(const char *line);
int					manip_line(const char *line);
int					get_texture(char **content);
void				cub3d(int nb_line, int max_len);

#endif
