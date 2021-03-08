/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:03:25 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/05 12:03:54 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		checktype(char c)
{
	return (c == 'i' || c == 'd' || c == 's' || c == 'c' ||
			c == 'u' || c == 'p' || c == 'x' || c == 'X' || c == '%');
}

void	cpf_bis_one(char *str, int i, t_varpf *pf, va_list ap)
{
	if (str[i] == '*')
	{
		if ((pf->large = va_arg(ap, int)) < 0)
		{
			pf->large *= -1;
			pf->indic = -1;
		}
	}
	else
		pf->large = ft_atoi(&str[i]);
	return ;
}

void	cpf_bis_two(char *str, int i, t_varpf *pf, va_list ap)
{
	pf->dot = 0;
	if (ft_isdigit(str[i]) || str[i] == '*')
	{
		if (str[i] == '*')
		{
			if ((pf->dot = va_arg(ap, int)) < 0)
				pf->dot = -1;
		}
		else
			pf->dot = ft_atoi(&str[i]);
	}
	return ;
}

t_varpf	*cpf(char *str, t_varpf *pf, char conv, va_list ap)
{
	int i;

	i = 0;
	pf->type = conv;
	if (str[i] == '%')
		return (pf);
	while (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '0' && pf->indic == 0)
			pf->indic = 1;
		if (str[i] == '-')
			pf->indic = -1;
		i++;
	}
	if (ft_isdigit(str[i]) || str[i] == '*')
		cpf_bis_one(str, i, pf, ap);
	while (ft_isdigit(str[i]) || (str[i] == '*'))
		i++;
	if (str[i++] == '.')
		cpf_bis_two(str, i, pf, ap);
	return (pf);
}
