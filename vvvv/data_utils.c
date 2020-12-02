/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 00:37:18 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/28 09:55:01 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init(void)
{
	g_data.nb[0] = 0;
	g_data.nb[1] = 0;
	g_data.nb[2] = 0;
	g_data.nb[3] = 0;
	g_data.nb[4] = 0;
	g_data.nb[5] = 0;
	g_data.nb[6] = 0;
	g_data.nb[7] = 0;
	g_data.resolution[0] = -1;
	g_data.resolution[1] = -1;
	g_player.x = -1;
	g_player.y = -1;
	g_player.rotation = 0;
}

int		all_digit(const char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}

int		skip_line(const char *line)
{
	int		i;

	i = 0;
	if (ft_strlen(line) == 0)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int		manip_line(const char *line)
{
	char			**content;
	static int		nb_data = 0;
	int				nb;
	int				i;

	i = 0;
	nb = 0;
	if ((content = my_split(line, ' ', '\t')) == NULL)
		ft_error("Split\n");
	while (content[nb])
		nb++;
	if (nb == 3)
		nb_data += get_resolution(content);
	else if (nb == 2)
		nb_data += get_texture(content);
	else
		ft_error("Content line\n");
	return (1);
}
