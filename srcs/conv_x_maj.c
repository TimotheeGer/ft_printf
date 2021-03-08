/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x_maj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:10:35 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/05 12:02:29 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_is_posi_exa_maj(long long nb, t_varpf *pf, int ret_len)
{
	if (pf->indic == 0 || (pf->indic == 1 && pf->dot >= 0))
		print_pad(' ', pf->large - max(pf->count, pf->dot));
	if (pf->dot == -1 && pf->indic == 1)
		print_pad('0', pf->large - pf->count);
	if (pf->dot > pf->count)
		print_pad('0', pf->dot - pf->count);
	ft_putnbr_base(nb, "0123456789ABCDEF");
	if (pf->indic == -1)
		print_pad(' ', (pf->large - max(pf->count, pf->dot)));
	ret_len = max(pf->count, pf->dot);
	ret_len = max(ret_len, pf->large);
	return (ret_len);
}

int				conv_x_maj(t_varpf *pf, va_list ap)
{
	unsigned	nb;
	int			ret_len;

	ret_len = 0;
	nb = (unsigned)va_arg(ap, int);
	pf->count = countnum_exa(nb);
	if (nb == 0)
		return (ft_is_zero_new(nb, pf, ret_len));
	if (nb > 0)
		return (ft_is_posi_exa_maj(nb, pf, ret_len));
	return (0);
}
