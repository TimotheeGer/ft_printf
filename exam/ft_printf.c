/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:25:31 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/09 13:50:47 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <unistd.h>
#include <stdarg.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void		ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return ;
}

void		printpad(char c, int len)
{
	int i = 0;

	while (i < len)
	{
		ft_putchar(c);
		i++;
	}
	return ;
}

int			ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}

int			ft_count(long nb)
{
	int i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int			ft_count_exa(unsigned nb)
{
	int i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int			ft_isdigit(char c)
{
	int i = 0;
	
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);	
}

int			ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void		ft_putnbr_base(long nb, char *base)
{
	if (nb >= (long)ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putnbr_base(nb % ft_strlen(base), base);	
	}
	else
		ft_putchar(base[nb]);
}

int			ft_atoi(char *str)
{
	int i = 0;
	int res = 0;
	
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + (str[i] - 48);
		i++;
	}
	return (res);
}

int		ft_checktype(char c)
{
	return (c == 'd' || c == 'x' || c == 's');
}

typedef struct 	s_varpf
{
	int i;
	int j;
	int large;
	int dot;
	int len;
	int print;
	char type;
}				varpf;

varpf	*initpf(varpf *pf)
{
	pf->large = 0;
	pf->dot = -1;
	pf->len = 0;
	return (pf);
}

int		conv_s(varpf *pf, va_list ap)
{
	char *str;
	int i = 0;
	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	pf->len = ft_strlen(str);
	if (pf->dot < pf->len && pf->dot != -1)
		pf->len = pf->dot;
	if (pf->large > pf->len)
		printpad(' ', pf->large - pf->len);
	if (pf->dot <= pf->len && pf->dot != -1)
	{
		while (i < pf->dot)
			ft_putchar(str[i++]);
	}
	else
		ft_putstr(str);
	return (ft_max(pf->large, pf->len));		
}

int		conv_x(varpf *pf, va_list ap)
{
	unsigned nb;
	nb = (unsigned)va_arg(ap, int);
	if (pf->dot == 0 && nb == 0)
		pf->len = 0;
	else
		pf->len = ft_count_exa(nb);
	if (nb >= 0)
	{
		if (pf->large > (ft_max(pf->len, pf->dot)))
			printpad(' ', pf->large - ft_max(pf->len, pf->dot));
		if (pf->dot > pf->len)
			printpad('0', pf->dot - pf->len);
		if (!(nb == 0 && pf->dot == 0))
			ft_putnbr_base(nb, "0123456789abcdef");
	}
	return (ft_max(pf->large, ft_max(pf->dot, pf->len)));	
}

int		conv_d(varpf *pf, va_list ap)
{
	long nb;
	nb = (long)va_arg(ap, int);
	if (pf->dot == 0 && nb == 0)
		pf->len = 0;
	else
		pf->len = ft_count(nb);
	if (nb < 0)
	{
		pf->len = ft_count(nb * -1) + 1;
		if (pf->large > (ft_max(pf->len, pf->dot)))
			printpad(' ', pf->large - ft_max(pf->len, pf->dot + 1));
		ft_putchar('-');
		if (pf->dot > pf->len - 1)
			printpad('0', pf->dot + 1 - pf->len);
		ft_putnbr_base(nb * -1, "0123456789");
		return (ft_max(pf->large, ft_max(pf->dot + 1, pf->len)));
	}
	if (nb >= 0)
	{
		if (pf->large > (ft_max(pf->len, pf->dot)))
			printpad(' ', pf->large - ft_max(pf->len, pf->dot));
		if (pf->dot > pf->len)
			printpad('0', pf->dot - pf->len);
		if (!(nb == 0 && pf->dot == 0))
			ft_putnbr_base(nb, "0123456789");
	}
	return (ft_max(pf->large, ft_max(pf->dot, pf->len)));
}

int		ft_checkconv(varpf *pf, va_list ap)
{
	if (pf->type  == 'd')
	{
		return (conv_d(pf, ap));
	}
	if (pf->type  == 'x')
	{
		return (conv_x(pf, ap));
	}
	if (pf->type  == 's')
	{
		return (conv_s(pf, ap));
	}
	return(0);
}

varpf	*ft_checkflag(varpf *pf, char *str, char type)
{
		int i = 0;
		
		pf->type = type;
		if (ft_isdigit(str[i]))
		{
			pf->large = ft_atoi(&str[i]);
		}
		while (ft_isdigit(str[i]))
			i++;
		if (str[i++] == '.')
		{
			if (ft_isdigit(str[i]))
				pf->dot = ft_atoi(&str[i]);
			else
				pf->dot = 0;
		}
		return (pf);
}

int		ft_printf(const char *str, ...)
{
	va_list ap;
	varpf pf;
	va_start(ap, str);
	pf.i = 0;
	pf.j = 0;
	pf.print = 0;

	while (str[pf.i])
	{
		if (str[pf.i] == '%')
		{
			pf.j = pf.i + 1;
			while ((!(ft_checktype(str[pf.i]))) && str[pf.i])
				pf.i++;
			if (str[pf.i] == '\0')
				pf.i = pf.j - 1;
			if (ft_checktype(str[pf.i]))
			{
				pf.print = pf.print + ft_checkconv(ft_checkflag(initpf(&pf), (char*)&str[pf.j], str[pf.i]), ap);
			}
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