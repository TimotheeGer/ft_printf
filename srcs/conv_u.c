/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:45:40 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/05 12:02:15 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					conv_u(t_varpf *pf, va_list ap)
{
	unsigned int	nb;
	int				ret_len;

	ret_len = 0;
	nb = va_arg(ap, unsigned int);
	pf->count = countnum((long)nb);
	if (nb == 0)
		return (ft_is_zero_new(nb, pf, ret_len));
	if (nb > 0)
		return (ft_is_posi(nb, pf, ret_len));
	return (0);
}
