/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d_i_nega.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:04:59 by tigerber          #+#    #+#             */
/*   Updated: 2021/02/24 15:26:11 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int     ft_is_zero(long i, int dot, int large)
{
    int a;
    
    a = large;
    if (dot == 0 && i == 0)
    {
        while (large-- > 0)
            ft_putchar(' ');
    }
    return (a);    
}

int     ft_if_two_nega(long i, int j, int dot, int large, int indic)
{
    int a;
   
    a = large;
    if (large < j)
        a = j + 1;
    if (dot == 0)
    {
        while (large-- > j + 1)
            ft_putchar(' ');
        ft_putnbr(i);
        return (a);
    }
    if (indic == -1 && dot < j)
    {
        ft_putnbr(i);
        while (large-- > j + 1)
            ft_putchar(' ');
    }
    if (indic == 0 && dot < j)
    {
        ft_putchar('-');
        while (large-- > j + 1)
            ft_putchar('0');
        ft_putnbr(i *= -1);
    }
    return (a);
}

int     ft_if_three_nega(long i, int j, int dot, int large, int indic)
{
    int a;

    a = large;
    if (indic == 0)
    {
        while (large-- > dot + 1)
            ft_putchar(' ');
        ft_putchar('-');
        while (dot-- > j)
            ft_putchar('0');
        ft_putnbr(i *= -1);
        return (a);
    }
    if (indic == -1)
    {
        ft_putchar('-');
        while(j++ < dot)
            ft_putchar('0');
        ft_putnbr(i *= -1);
        while (large-- > dot + 1)
            ft_putchar(' ');
        return (a);
    }
    return (a);
}