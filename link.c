/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:31:43 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/11 04:07:47 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"
#include "cub3d.h"

void		insertion(t_liste *liste, char *nvline)
{
	t_line *nouveau;

	nouveau = malloc(sizeof(nouveau));
	if (liste == NULL || nouveau == NULL)
		ft_error("link\n");
	nouveau->line = nvline;
	nouveau->next = liste->first;
	liste->first = nouveau;
}

t_liste		*initialisation(char *str)
{
	t_liste		*liste;
	t_line		*element;

	liste = malloc(sizeof(t_liste));
	element = malloc(sizeof(t_line));
	if (liste == NULL || element == NULL)
		ft_error("link\n");
	element->line = str;
	element->next = NULL;
	liste->first = element;
	return (liste);
}
