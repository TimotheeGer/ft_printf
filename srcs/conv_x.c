/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 10:44:00 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/05 12:02:43 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_is_posi_exa_min(long long nb, t_varpf *pf, int ret_len)
{
	if (pf->indic == 0 || (pf->indic == 1 && pf->dot >= 0))
		print_pad(' ', pf->large - max(pf->count, pf->dot));
	if (pf->dot == -1 && pf->indic == 1)
		print_pad('0', pf->large - pf->count);
	if (pf->dot > pf->count)
		print_pad('0', pf->dot - pf->count);
	ft_putnbr_base(nb, "0123456789abcdef");
	if (pf->indic == -1)
		print_pad(' ', (pf->large - max(pf->count, pf->dot)));
	ret_len = max(pf->count, pf->dot);
	ret_len = max(ret_len, pf->large);
	return (ret_len);
}

int				conv_x(t_varpf *pf, va_list ap)
{
	unsigned	i;
	int			ret_len;

	ret_len = 0;
	i = (unsigned)va_arg(ap, int);
	pf->count = countnum_exa(i);
	if (i == 0)
		return (ft_is_zero_new(i, pf, ret_len));
	if (i > 0)
		return (ft_is_posi_exa_min(i, pf, ret_len));
	return (0);
}
