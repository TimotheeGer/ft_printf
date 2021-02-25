/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:14:55 by tigerber          #+#    #+#             */
/*   Updated: 2021/02/25 15:37:06 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *str, ...)
{
	varpf pf;
	va_list ap;	

	pf.print = 0;
	pf.i = 0;
	va_start(ap, str);
	while (str[pf.i])
	{
		if (str[pf.i] == '%')
		{
			pf.j = pf.i + 1;
			while (!(checktype(str[pf.i])))
				pf.i++;
			if (checktype(str[pf.i]))
				pf.print += checkconv(checkpf((char*)&str[pf.j], initiapf(&pf), str[pf.i], ap),ap);
		}
		else
		{
			ft_putchar(str[pf.i]);
			pf.print++;
		}
		pf.i++;
	}
	va_end(ap);
	return (pf.print);
}

//int		main()
// {
	// varpf pf;
	// unsigned j = -42;
	// int *i;
	// int res = 0;
	// int res2 = 2;
	// int k = 42;
	// char c = 'b';
	// char *str = "bonjour";
	// 
	// i = &res2;
	// pf.indic = 'c';
	// pf.large = 12;
	// pf.dot = -1;
	// pf.type = 's';
	// (void)j;
	// ft_printf("hello", i, j, c, &s);
	// printf("s = %p\n", &s);
	// printf("test = [%c]\n", pf.indic);
	// printf("test = [%i]\n", pf.large);
	// printf("test = [%i]\n", pf.dot);
	// printf("test = [%c]\n", pf.type);
	// printf("====================================\n");
// 
	//  res2 = ft_printf("bonjour = [%10s] mercii\n", str);
	//  res = printf("bonjour = [%10s] mercii\n", str);
// 
	//  printf("res   = %d\n", res);
	//  printf("res2  = %d\n", res2);
// 
	// printf("res2 = %d\n", res2);
	// printf("test = [%c]\n", pf.indic);
	// printf("test = [%i]\n", pf.large);
	// printf("test = [%i]\n", pf.dot);
	// printf("test = [%c]\n", pf.type);
	// printf("====================================\n");
	// return (0);
// }
// 