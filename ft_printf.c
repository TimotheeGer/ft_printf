/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:14:55 by tigerber          #+#    #+#             */
/*   Updated: 2021/02/08 15:43:06 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <stdarg.h>

int		ft_printf(const char *str, ...)
{
	int i;
	unsigned long z;
	void *j;
	char c;
	char *s;
	
	va_list ap;

	i = 0;

	va_start(ap, str);

	printf("str = %s\n", str);

	i = va_arg(ap, int);
	printf("i = %d\n", i);

	i = va_arg(ap, int);
	printf("i = %d\n", i);

	c = va_arg(ap, int);
	printf("c = %c\n", c);

	z = (unsigned long)va_arg(ap, void*);
	printf("z = %lu\n", z);
	printf("z = %p\n", &z);

	va_end(ap);

	return (0);
}

int		main()
{
	int i;
	char c;
	char *s;

	i = 123456789;
	c = 'b';
	s = "123456789";

	//ft_printf("hello", i, j, c, &s);
	//printf("s = %p\n", &s);
	printf("test = [%-20.30d]", i);
	return (0);
}
