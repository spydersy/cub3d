/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:31:52 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/15 18:31:02 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINK_H
#define LINK_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_line t_line;

typedef struct  s_line
{

    char        *line;
    t_line      *next;

}               t_line;

typedef struct  s_liste
{

    t_line      *first;

}               t_liste;

t_liste			*initialisation(char *str);
void			insertion(t_liste *liste, char *nvline);

#endif