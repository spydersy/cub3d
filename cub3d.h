/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:21:55 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/11 11:00:10 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include "./GNL/get_next_line.h"
# include "./LBFT/libft.h"
# include "link.h"

#include "./mlx/mlx_int.h"
#include "./mlx/mlx.h"

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
	int			x;
	int			y;
	int			oreintation;
}				t_player;

char			**g_map;
t_player		g_player;
t_data			g_data;
t_liste			*g_liste;

void			cub3d(int nb_line, int max_len);
t_liste			*initialisation(char *str);
void			ft_move(int nb_line, int max_len);
size_t			my_strlcpy(char *dst, const char *src, size_t size);
void			ft_data(int fd);
void			ft_map(int fd);
void			get_player(char orientation, int x, int y);
void			bad_char(const char *line, int i);
void			check_line(const char *line, int nb_line);
int				skip_void(int fd);
void			bef_aft(char check_char, const char *line,
				int nb_line, int i);
void			ft_error(char *str);
int				max_of(int i, int j);
char			**my_split(char const *s, char c, char d);
int				get_texture(char **content);
int				get_path(int index, const char *str);
int				get_rgb(int index, const char *str);
int				get_resolution(char **content);
int				all_digit(const char *str);
int				skip_line(const char *line);

#endif
