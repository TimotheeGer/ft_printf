/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:07:53 by tigerber          #+#    #+#             */
/*   Updated: 2021/02/25 15:38:39 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_if_one(long i, int j, int dot, int nega)
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
    ft_putnbr(i);
    return (a);
    
}

int     ft_if_two(long i, int j, int dot, int large, int indic)
{
    int a;

    a = large;
    if (large < j)
        a = j;
    (void)dot;
    // if (dot < 0 && indic == 0)
    // {printf("test\n");
        // while (large-- > j)
            // ft_putchar('0');
        // ft_putnbr(i);
        // return (a);
    // }     
    if (indic == -1)
    {
        ft_putnbr(i);
        while (large-- > j)
            ft_putchar(' ');
    }
    if (indic == 0)
    {
        while (large-- > j)
            ft_putchar(' ');
        ft_putnbr(i);
    }
    return (a);
}

int     ft_if_three(long i, int j, int dot, int large, int indic)
{
    int a;

    a = large;
    if (indic == -1)
    {
        while (j++ < dot)
            ft_putchar('0');
        ft_putnbr(i);
        while (j++ <= large)
            ft_putchar(' ');
    }
    if (indic == 0)
    {
        while (large-- > dot)
            ft_putchar(' ');
        while (dot-- > j)
            ft_putchar('0');
        ft_putnbr(i);
    }
    return (a); 
}

int		conv_d_i(varpf *pf, va_list ap)
{   //printf("=====testd====\n");
    // printf("===============conv_d_i=====================\n");
    // printf("indic = [%i]\n", pf->indic);
	//  printf("large = [%i]\n", pf->large);
	// printf("dot   = [%i]\n", pf->dot);
	// printf("type  = [%c]\n", pf->type);
	// printf("base  = [%s]\n", pf->base);
    // printf("===============conv_d_i=====================\n");
    long i;
    int j;
    
    i = (long)va_arg(ap, int);
    j = countnum((long)i);
    if (i < 0)
        pf->nega = 1;
    if (pf->dot == 0 && i == 0)
        return (ft_is_zero(i, pf->dot, pf->large));
    if (pf->dot >= pf->large && (pf->indic == -1 || pf->indic == 0))
        return(ft_if_one(i, j, pf->dot, pf->nega));
    if (pf->large > pf->dot && pf->dot <= j)
    {
        if (pf->nega)
            return(ft_if_two_nega(i, j, pf->dot, pf->large, pf->indic));
        else
            return (ft_if_two(i, j, pf->dot, pf->large, pf->indic));
    }
    if (pf->large > pf->dot && pf->dot > j)
    {
        if (pf->nega)
            return (ft_if_three_nega(i, j, pf->dot, pf->large, pf->indic));
        else
            return (ft_if_three(i, j, pf->dot, pf->large, pf->indic));
    }
	return (0);
}