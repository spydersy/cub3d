/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:31:43 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/09 14:27:46 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"
#include "cub3d.h"

void		insertion(t_liste *liste, char *nvline)
{
    /* Création du nouvel élément */
    t_line *nouveau;
	nouveau = malloc(sizeof(nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->line = nvline;

    /* Insertion de l'élément au début de la liste */
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

    return liste;
}

void	afficherListe(t_liste *liste)
{
    if (liste == NULL)
        exit(EXIT_FAILURE);
    t_line *actuel;
	actuel = liste->first;

    while (actuel != NULL)
    {
        printf("link : >>%s<<\n", actuel->line);
        actuel = actuel->next;
    }
    printf(">>NULL<<\n");
}

// int main()
// {
//     t_liste *maListe;

// 	const char *str = "first";
// 	maListe = initialisation(str);
//     afficherListe(maListe);
//     insertion(maListe, "1");
//     afficherListe(maListe);
//     insertion(maListe, "2");
//     afficherListe(maListe);
//     insertion(maListe, "3");
//     afficherListe(maListe);
//     return 0;
// }