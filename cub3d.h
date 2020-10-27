/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 18:48:26 by abelarif          #+#    #+#             */
/*   Updated: 2020/10/27 08:42:00 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include "./LBFT/libft.h"
#include "./GNL/get_next_line.h"

typedef	struct s_data
{
	int		resolution[2];
	int		nb_data[8];
	int		floor[3];
	int		ceilling[3];
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*sp_texture;
} t_data;

t_data		g_data;

char                            **my_split(char const *s, char c, char d);

#endif