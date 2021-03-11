/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:36:35 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/11 11:26:07 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Nom de l'affectation: union
// Fichiers attendus: union.c
// Fonctions autorisées: écriture
// --------------------------------------------------------------------------------
// 
// Écrivez un programme qui prend deux chaînes et affiche, sans double, le
// caractères qui apparaissent dans l'une ou l'autre des chaînes.
// 
// L'affichage sera dans l'ordre des caractères apparaissant dans la ligne de commande, et
// sera suivi d'un \ n.
// 
// Si le nombre d'arguments n'est pas 2, le programme affiche \ n.
// 
// Exemple:

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
	return ;
}

void	ft_union(char *str1, char *str2)
{
	int tab[127] = {0};
	int i = 0;
		
	while (str1[i])
	{
		if (tab[(int)str1[i]] == 0)
		{
			tab[(int)str1[i]] = 1;
			ft_putchar(str1[i]);
		}
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if (tab[(int)str2[i]] == 0)
		{
			tab[(int)str2[i]] = 1;
			ft_putchar(str2[i]);
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_union(av[1], av[2]);
	ft_putchar('\n');
	return(0);
}