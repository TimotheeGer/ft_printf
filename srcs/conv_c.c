/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:23:39 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/05 12:01:30 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			if_one_c(char c, int j, int large)
{
	int	a;

	a = large;
	while (large > j)
	{
		ft_putchar(' ');
		large--;
	}
	ft_putchar(c);
	return (a);
}

int			if_two_c(char c, int j, int large)
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

int			conv_c(t_varpf *pf, va_list ap)
{
	char	c;
	int		j;

	c = (char)va_arg(ap, int);
	j = 1;
	if (pf->indic == 0 && pf->large > j)
		return (if_one_c(c, j, pf->large));
	if (pf->indic == -1 && pf->large > j)
		return (if_two_c(c, j, pf->large));
	else
		ft_putchar(c);
	return (j);
}
