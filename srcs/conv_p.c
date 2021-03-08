/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:47:42 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/05 12:59:22 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			if_one_p(long long i, int j, int large)
{
	int		a;

	a = large;
	while (large > j + 2)
	{
		ft_putchar(' ');
		large--;
	}
	ft_putstr("0x");
	ft_putnbr_base(i, "0123456789abcdef");
	return (a);
}

int			if_two_p(long long i, int j, int large)
{
	int a;

	a = large;
	ft_putstr("0x");
	ft_putnbr_base(i, "0123456789abcdef");
	while (large > j + 2)
	{
		ft_putchar(' ');
		large--;
	}
	return (a);
}

int			conv_p(t_varpf *pf, va_list ap)
{
	long	i;
	int		j;

	i = (long long)va_arg(ap, void*);
	j = countnum_exa(i);
	if (pf->indic == 0 && pf->large > j + 2)
		return (if_one_p(i, j, pf->large));
	if (pf->indic == -1 && pf->large > j + 2)
		return (if_two_p(i, j, pf->large));
	else
	{
		ft_putstr("0x");
		ft_putnbr_base(i, "0123456789abcdef");
	}
	return (j + 2);
}
