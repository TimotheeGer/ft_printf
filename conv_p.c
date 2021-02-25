/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:47:42 by tigerber          #+#    #+#             */
/*   Updated: 2021/02/25 14:52:22 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     if_one_p(long i, int j, int large)
{
    int a;
    
    a = large;
    while (large > j + 2)
    {
        ft_putchar(' ');
        large--;
    }
    ft_putstr("0x");
    ft_putnbr_base(i, "0123456789abcdef");
    return(a);
}

int     if_two_p(long i, int j, int large)
{
    int a;
    
    a = large;
    ft_putstr("0x");
    ft_putnbr_base(i, "0123456789abcdef");
    while (large > j +2)
    {
        ft_putchar(' ');
        large--;
    }
    return (a);
}

int     conv_p(varpf *pf, va_list ap)
{   //printf("=====testp====\n");
    //     printf("===============conv_p=====================\n");
    // printf("indic = [%i]\n", pf->indic);
	//  printf("large = [%i]\n", pf->large);
	// printf("dot   = [%i]\n", pf->dot)
	// printf("type  = [%c]\n", pf->type);
	// printf("base  = [%s]\n", pf->base);
    // printf("===============conv_p=====================\n");
    long i;
    int  j;
    i = (long)va_arg(ap, void*);
    j = countnum_exa(i);
    if (pf->indic == 0 && pf->large > j + 2)
    {//printf("=====test1====\n");
        return (if_one_p(i, j, pf->large));
    }
    if (pf->indic == -1 && pf->large > j + 2)
    {//printf("=====test2====\n");
        return (if_two_p(i, j, pf->large));    
    }
    else
    {//pest3====
        ft_putstr("0x");
        ft_putnbr_base(i, "0123456789abcdef");
    }
    return (j + 2);
}