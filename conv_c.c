/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:23:39 by tigerber          #+#    #+#             */
/*   Updated: 2021/02/24 15:26:08 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     if_one_c(char c, int j, int large)
{
    int a;
    
    a = large;
    while (large > j)
    {
        ft_putchar(' ');
        large--;
    }
    ft_putchar(c);
    return(a);
}

int     if_two_c(char c, int j, int large)
{
    int a;
    
    a = large;
    ft_putchar(c);
    while (large > j)
    {
        ft_putchar(' ');
        large--;
    }
    return (a);
}

int     conv_c(varpf *pf, va_list ap)
{//printf("=====testc====\n");
    //     printf("===============conv_p=====================\n");
    // printf("indic = [%i]\n", pf->indic);
	//  printf("large = [%i]\n", pf->large);
	// printf("dot   = [%i]\n", pf->dot)
	// printf("type  = [%c]\n", pf->type);
	// printf("base  = [%s]\n", pf->base);
    // printf("===============conv_p=====================\n");
    char c;
    int  j;
    c = (char)va_arg(ap, int);
    j = 1;
    if (pf->indic == 0 && pf->large > j)
    {//printf("=====test1====\n");
        return (if_one_c(c, j, pf->large));
    }
    if (pf->indic == -1 && pf->large > j)
    {//printf("=====test2====\n");
        return (if_two_c(c, j, pf->large));    
    }
    else
    {//pest3====
        ft_putchar(c);
    }
    return (j);
}