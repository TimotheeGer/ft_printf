/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:47:26 by tigerber          #+#    #+#             */
/*   Updated: 2021/02/25 15:31:54 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     conv_s(varpf *pf, va_list ap)
{
    // printf("===============conv_d_i=====================\n");
    // printf("indic = [%i]\n", pf->indic);
    // printf("large = [%i]\n", pf->large);
    // printf("dot   = [%i]\n", pf->dot);
    // printf("type  = [%c]\n", pf->type);
    // printf("base  = [%s]\n", pf->base);
    // printf("===============conv_d_i=====================\n");
 char *str;
 int i;
 int j;
 
 i = 0;
 j = pf->large;
 str = va_arg(ap, char*);
 
 if (pf->dot == 0)
 {
    while(i < pf->large)
    {
        ft_putchar(' ');
        i++;
    }
    return (pf->large);
 }
 if (pf->dot < ft_strlen(str) && pf->large > ft_strlen(str) && pf->indic == 0)
 {//printf("***test***\n");
    while (pf->large >= (ft_strlen(str) - pf->dot))
    {
        ft_putchar(' ');
        pf->large--;
    }
    while (i < pf->dot)
     {
         ft_putchar(str[i]);
         i++;
     }
     return (pf->large);
 }
 if (pf->dot < ft_strlen(str) && pf->large > ft_strlen(str) && pf->indic == -1)
 {
    while (i < pf->dot)
    {
        ft_putchar(str[i]);
        i++;
    }
    while (pf->large >= (ft_strlen(str) - pf->dot))
    {
        ft_putchar(' ');
        pf->large--;
    }
    return (j);
 }
 else
 {
     ft_putstr(str);
 }
 //printf("***test1***\n");
 return (ft_strlen(str));
}