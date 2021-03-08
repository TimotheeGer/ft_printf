/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_libft2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:11:39 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/05 12:42:52 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int			countnum_exa(long long n)
{
	int			i;
	long long	nb;

	i = 0;
	nb = n;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		nb = nb * -1;
	}
	while (nb)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int			countnum(long n)
{
	int		i;
	long	nb;

	i = 0;
	nb = n;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		nb = nb * -1;
	}
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
