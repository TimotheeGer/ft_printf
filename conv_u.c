/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:45:40 by tigerber          #+#    #+#             */
/*   Updated: 2021/02/25 14:52:41 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     conv_u(varpf *pf, va_list ap)
{//printf("=====testu====\n");
    unsigned int i;
    int j;
    
    i = va_arg(ap, unsigned int);
    j = countnum((long)i);
    if (i < 0)
        pf->nega = 1;
    if (pf->dot == 0 && i == 0)
        return (ft_is_zero(i, pf->dot, pf->large));
    if (pf->dot >= pf->large && (pf->indic == -1 || pf->indic == 0))
        return(ft_if_one(i, j, pf->dot, pf->nega));
    if (pf->large > pf->dot && pf->dot <= j)
    {
            return (ft_if_two(i, j, pf->dot, pf->large, pf->indic));
    }
    if (pf->large > pf->dot && pf->dot > j)
    {
            return (ft_if_three(i, j, pf->dot, pf->large, pf->indic));
    }
    return (0);
}