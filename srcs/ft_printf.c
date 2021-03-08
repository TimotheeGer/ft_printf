/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:14:55 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/05 12:03:14 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_varpf		*ip(t_varpf *pf)
{
	pf->indic = 0;
	pf->large = 0;
	pf->dot = -1;
	pf->type = 0;
	pf->nega = 0;
	pf->a = 0;
	pf->len = 0;
	return (pf);
}

int			ccv(t_varpf *pf, va_list ap)
{
	if (pf->type == '%')
		return (conv_pc(pf));
	if (pf->type == 's')
		return (conv_s(pf, ap));
	if (pf->type == 'c')
		return (conv_c(pf, ap));
	if (pf->type == 'X')
		return (conv_x_maj(pf, ap));
	if (pf->type == 'x')
		return (conv_x(pf, ap));
	if (pf->type == 'p')
		return (conv_p(pf, ap));
	if (pf->type == 'u')
		return (conv_u(pf, ap));
	if (pf->type == 'd' || pf->type == 'i')
		return (conv_d_i(pf, ap));
	return (0);
}

int			ft_printf(const char *str, ...)
{
	t_varpf	pf;
	va_list ap;

	pf.p = 0;
	pf.i = 0;
	va_start(ap, str);
	while (str[pf.i])
	{
		if (str[pf.i] == '%')
		{
			pf.j = pf.i++ + 1;
			while (!(checktype(str[pf.i])))
				pf.i++;
			if (checktype(str[pf.i]))
				pf.p += ccv(cpf((char*)&str[pf.j], ip(&pf), str[pf.i], ap), ap);
		}
		else
		{
			ft_putchar(str[pf.i]);
			pf.p++;
		}
		pf.i++;
	}
	va_end(ap);
	return (pf.p);
}
