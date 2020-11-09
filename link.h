/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:31:52 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/09 14:08:59 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINK_H
#define LINK_H

#include <stdlib.h>
#include <stdio.h>
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
void			afficherListe(t_liste *liste);
void			insertion(t_liste *liste, char *nvline);

#endif