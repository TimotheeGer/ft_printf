/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:39:08 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/09 15:40:30 by tigerber         ###   ########.fr       */
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