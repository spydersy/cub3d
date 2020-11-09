/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 09:31:43 by abelarif          #+#    #+#             */
/*   Updated: 2020/11/09 09:33:41 by abelarif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"

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

t_liste		*initialisation()
{
    t_liste *liste;
    t_line *element;

	liste = malloc(sizeof(t_liste));
    element = malloc(sizeof(t_line));
	if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element->line = "0";
    element->next = NULL;
    liste->first = element;

    return liste;
}

void	afficherListe(t_liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    t_line *actuel;
	actuel = liste->first;

    while (actuel != NULL)
    {
        printf("%s -> ", actuel->line);
        actuel = actuel->next;
    }
    printf("NULL\n");
}

int main()
{
    t_liste *maListe;

	maListe = initialisation();
    afficherListe(maListe);
    insertion(maListe, "1");
    afficherListe(maListe);
    insertion(maListe, "2");
    afficherListe(maListe);
    insertion(maListe, "3");
    afficherListe(maListe);
    return 0;
}