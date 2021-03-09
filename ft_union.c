/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:36:35 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/09 15:40:35 by tigerber         ###   ########.fr       */
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
