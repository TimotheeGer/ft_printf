/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 10:03:34 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/05 12:01:56 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		if_one_pc(int j, int large)
{
	int a;

	a = large;
	while (large > j)
	{
		ft_putchar('0');
		large--;
	}
	ft_putchar('%');
	return (a);
}

int		if_two_pc(int j, int large)
{
	int a;

	a = large;
	ft_putchar('%');
	while (large > j)
	{
		ft_putchar(' ');
		large--;
	}
	return (a);
}

int		if_three_pc(int j, int large)
{
	int a;

	a = large;
	while (large > j)
	{
		ft_putchar(' ');
		large--;
	}
	ft_putchar('%');
	return (a);
}

int		conv_pc(t_varpf *pf)
{
	int	j;

	j = 1;
	if (pf->indic == 1 && pf->large > j)
		return (if_one_pc(j, pf->large));
	if (pf->indic == -1 && pf->large > j)
		return (if_two_pc(j, pf->large));
	if (pf->indic == 0 && pf->large > j)
		return (if_three_pc(j, pf->large));
	else
	{
		ft_putchar('%');
		return (j);
	}
	return (j);
}
