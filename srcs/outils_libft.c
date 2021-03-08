/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:26:44 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/05 12:37:24 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

void	ft_putnbr_base(long nb, char *base)
{
	if (nb >= (long)ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putnbr_base(nb % ft_strlen(base), base);
	}
	else
		write(1, &base[nb], 1);
}

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
	return ;
}

int		ft_atoi(char *nptr)
{
	int i;
	int res;
	int neg;

	i = 0;
	res = 0;
	neg = 1;
	while (!(ft_isdigit(nptr[i])))
	{
		i++;
	}
	if (nptr[i] == '-')
	{
		neg = -1;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10;
		res = res + (nptr[i] - 48);
		i++;
	}
	return (res * neg);
}
