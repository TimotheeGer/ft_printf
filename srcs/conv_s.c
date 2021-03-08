/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 11:47:26 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/05 12:02:07 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			conv_s(t_varpf *pf, va_list ap)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	j = ft_strlen(str);
	if (pf->dot < ft_strlen(str) && (pf->dot > 0))
		j = pf->dot;
	if (pf->dot == 0)
		j = 0;
	if (pf->indic != -1)
		print_pad(' ', pf->large - j);
	if (pf->dot < ft_strlen(str) && pf->dot > 0)
	{
		while (i < pf->dot)
			ft_putchar(str[i++]);
	}
	else if (pf->dot != 0)
		ft_putstr(str);
	if (pf->indic == -1)
		print_pad(' ', pf->large - j);
	return (max(pf->large, j));
}
