/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:07:53 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/05 12:01:13 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			print_pad(char c, int len)
{
	while (len > 0)
	{
		len--;
		ft_putchar(c);
	}
}

int				ft_is_zero_new(long long nb, t_varpf *pf, int ret_len)
{
	if (pf->large == 0 && pf->dot == 0)
		pf->count = 0;
	if (pf->indic == 0)
		print_pad(' ', pf->large - max(pf->count, pf->dot));
	if (pf->indic == 1)
	{
		if (pf->dot >= 0)
			print_pad(' ', pf->large - max(pf->count, pf->dot));
		else
			print_pad('0', pf->large - max(pf->count, pf->dot));
	}
	if (pf->dot)
		print_pad('0', pf->dot - pf->count);
	if (pf->dot != 0)
		ft_putnbr(nb);
	else if (pf->large > 0)
		ft_putchar(' ');
	if (pf->indic == -1)
		print_pad(' ', (pf->large - max(pf->count, pf->dot)));
	ret_len = max(pf->count, max(pf->dot, pf->large));
	return (ret_len);
}

int				ft_is_nega(long long nb, t_varpf *pf, int ret_len)
{
	pf->count = countnum(nb) + 1;
	if (pf->indic == 0 && (pf->large > pf->dot + 1))
		print_pad(' ', (pf->large) - max(pf->count, pf->dot + 1));
	if ((pf->indic == 1 && pf->dot >= 0) && (pf->large > pf->dot + 1))
		print_pad(' ', pf->large - max(pf->count, pf->dot + 1));
	ft_putchar('-');
	if (pf->dot == -1 && pf->indic == 1)
		print_pad('0', pf->large - pf->count);
	if (pf->dot > 0)
		print_pad('0', pf->dot - (pf->count - 1));
	ft_putnbr(nb * -1);
	if (pf->indic == -1)
		print_pad(' ', (pf->large - max(pf->count, (pf->dot + 1))));
	ret_len = max(pf->count, max(pf->dot + 1, pf->large));
	return (ret_len);
}

int				ft_is_posi(long long nb, t_varpf *pf, int ret_len)
{
	if (pf->indic == 0 || (pf->indic == 1 && pf->dot >= 0))
		print_pad(' ', pf->large - max(pf->count, pf->dot));
	if (pf->dot == -1 && pf->indic == 1)
		print_pad('0', pf->large - pf->count);
	if (pf->dot > pf->count)
		print_pad('0', pf->dot - pf->count);
	ft_putnbr(nb);
	if (pf->indic == -1)
		print_pad(' ', (pf->large - max(pf->count, pf->dot)));
	ret_len = max(pf->count, pf->dot);
	ret_len = max(ret_len, pf->large);
	return (ret_len);
}

int				conv_d_i(t_varpf *pf, va_list ap)
{
	long long	nb;
	int			ret_len;

	ret_len = 0;
	nb = va_arg(ap, int);
	pf->count = countnum(nb);
	if (nb == 0)
		return (ft_is_zero_new(nb, pf, ret_len));
	if (nb < 0)
		return (ft_is_nega(nb, pf, ret_len));
	if (nb > 0)
		return (ft_is_posi(nb, pf, ret_len));
	return (0);
}
