/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:44:00 by tigerber          #+#    #+#             */
/*   Updated: 2021/02/25 14:53:00 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_if_one_exa_min(long i, int j, int dot, int nega)
{
    int a;

    a = dot;
    if (dot < j)
        a = j;
    if (nega)
    {
        a++;
        i *= -1;
        ft_putchar('-');
    }
    while (dot-- > j)
        ft_putchar('0'); 
    ft_putnbr_base(i, "0123456789abcdef");
    return (a);
    
}

int     ft_if_two_exa_min(long i, int j, int dot, int large, int indic)
{
    int a;

    a = large;
    if (large < j)
        a = j;
    if (dot < 0 && indic == 0)
    {
        while (large-- > j)
            ft_putchar('0');
        ft_putnbr_base(i, "0123456789abcdef");
        return (a);
    }     
    if (indic == -1)
    {
        ft_putnbr_base(i, "0123456789abcdef");
        while (large-- > j)
            ft_putchar(' ');
    }
    if (indic == 0)
    {
        while (large-- > j)
            ft_putchar(' ');
        ft_putnbr_base(i, "0123456789abcdef");
    }
    return (a);
}

int     ft_if_three_exa_min(long i, int j, int dot, int large, int indic)
{
    int a;

    a = large;
    if (indic == -1)
    {
        while (j++ < dot)
            ft_putchar('0');
        ft_putnbr_base(i, "0123456789abcdef");
        while (j++ <= large)
            ft_putchar(' ');
    }
    if (indic == 0)
    {
        while (large-- > dot)
            ft_putchar(' ');
        while (dot-- > j)
            ft_putchar('0');
        ft_putnbr_base(i, "0123456789abcdef");
    }
    return (a); 
}

int     conv_x(varpf *pf, va_list ap)
{//printf("=====testx====\n");
    unsigned i;
    int  j;

    i = (unsigned)va_arg(ap, int);
    j = countnum_exa(i);
    if (pf->dot == 0 && i == 0)
        return (ft_is_zero(i, pf->dot, pf->large));
    if (pf->dot >= pf->large && (pf->indic == -1 || pf->indic == 0))
        return(ft_if_one_exa_min(i, j, pf->dot, pf->nega));
    if (pf->large > pf->dot && pf->dot <= j)
        return (ft_if_two_exa_min(i, j, pf->dot, pf->large, pf->indic));
    if (pf->large > pf->dot && pf->dot > j)
        return (ft_if_three_exa_min(i, j, pf->dot, pf->large, pf->indic));
    return (0);    
}