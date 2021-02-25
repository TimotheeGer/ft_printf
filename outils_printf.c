/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:03:25 by tigerber          #+#    #+#             */
/*   Updated: 2021/02/25 14:53:37 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

varpf	*initiapf(varpf *pf)
{
	pf->indic = 0;
	pf->large = 0;
	pf->dot = -1;
	pf->type = 0;
	pf->base = "0123456789";
	pf->nega = 0;
	return (pf);
}

int		checktype(char c)
{//printf("=====testchectype====\n");
	return (c == 'i' || c == 'd' || c == 's' || c == 'c' ||
		 c == 'u' || c == 'p' || c == 'x' || c == 'X');
}

varpf	*checkpf(char *str, varpf *pf, char conv, va_list ap)
{	
	int i;

	i = 0;
	pf->type = conv;
	if (str[i] == '-')
	{
		pf->indic = -1;
		i++;
	}
	if (ft_isdigit(str[i]) || str[i] == '*')
	{
		if (str[i] == '*')
		{
			if((pf->large = va_arg(ap, int)) < 0)
			{
				pf->large *= -1;
				pf->indic = -1;
			}
		}
		else
			pf->large = ft_atoi(&str[i]);
	}
	while (ft_isdigit(str[i]))
		i++; 
	if (str[i++] == '.')
	{
		if (ft_isdigit(str[i]) || str[i] == '*')
		{
			if (str[i] == '*')
				pf->dot = va_arg(ap, int);
			else
				pf->dot = ft_atoi(&str[i]);
		}
	}
	return (pf);
}

int		checkconv(varpf *pf, va_list ap)
{
	if (pf->type == 's')
	{
		return (conv_s(pf, ap));
	}
	if (pf->type == 'c')
	{
		return (conv_c(pf, ap));
	}
	if (pf->type == 'X')
	{
		return (conv_x_maj(pf, ap));
	}
	if (pf->type == 'x')
	{
		return (conv_x(pf, ap));
	}
	if (pf->type == 'p')
	{
		return (conv_p(pf, ap));
	}
	if (pf->type == 'u')
	{
		return (conv_u(pf, ap));
	}
	if (pf->type == 'd' || pf->type == 'i')
	{
		return (conv_d_i(pf, ap));
	}
	return (0);
}