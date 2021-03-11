/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:39:08 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/11 12:23:31 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Nom de l'affectation: inter
// Fichiers attendus: inter.c
// Fonctions autorisées: écriture
// --------------------------------------------------------------------------------
// 
// Écrivez un programme qui prend deux chaînes et affiche, sans double, le
// caractères qui apparaissent dans les deux chaînes, dans l'ordre dans lequel ils apparaissent dans la première
// une.
// 
// L'affichage sera suivi d'un \ n.
// 
// Si le nombre d'arguments n'est pas 2, le programme affiche \ n.
// 
// Exemples:

// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
// $

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
	return ;
}

void	ft_inter(char *str1, char *str2)
{
	int	tab[127] = {0};
	int i = 0;
	int j = 0;
	
	while (str1[i])
	{
		while(str2[j])
		{
			if (str1[i] == str2[j] && tab[(int)str1[i]] == 0)
			{
				ft_putchar(str1[i]);
				tab[(int)str1[i]] = 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int		main(int ac, char **av)
{
	if (ac == 3)
		ft_inter(av[1], av[2]);
	ft_putchar('\n');
	return (0);
}