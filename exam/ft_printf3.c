/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:54:52 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/09 13:51:15 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// x s d largeur.precision
#include <unistd.h>
#include <stdarg.h>
#include <libc.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return ;
}

void	ft_printpad(char c, int len)
{
	while (len--)
		ft_putchar(c);
	return ;
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_count(int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int		ft_count_exa(unsigned nb)
{
	int i;

	i = 0;
	if (nb  == 0)
		return (1);
	while (nb)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putnbr_base(long nb, char *base)
{
	if (nb >= (long)ft_strlen(base))
	{
		ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putnbr_base(nb % ft_strlen(base), base);
	}
	else
		ft_putchar(base[nb]);
}

int		ft_atoi(char *str)
{
	int res;
	int i;
	
	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + (str[i] - 48);
		i++;
	}
	return (res);
}

typedef struct 	s_varpf
{
	int  i;
	int  j;
	int  large;
	int  dot;
	char type;
	int  len;
	int  print;
	int	 size;
}				varpf;

varpf	*ft_initipf(varpf *pf)
{
	pf->large = 0;
	pf->dot = -1;
	pf->len = 0;
	pf->print = 0;
	return(pf);
}

int		checktype(char c)
{
	return (c == 'd' || c == 'x' || c == 's');
}

varpf		*ft_checkconv(varpf *pf, char *str, char type)
{
	int i;

	i = 0;
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

int		conv_x(varpf *pf, va_list ap)
{
	unsigned  nb;

	nb = (unsigned)va_arg(ap, int);
	if (pf->dot == 0 && nb == 0)
		pf->len = 0;
	else
	pf->len = ft_count_exa(nb);
	if (nb >= 0)
	{
		if (pf->large > ft_max(pf->len, pf->dot))
			ft_printpad(' ', pf->large - (ft_max(pf->len, pf->dot)));
		if (pf->dot > pf->len)
			ft_printpad('0', pf->dot - pf->len);
		if (!((nb == 0) && (pf->dot == 0)))
			ft_putnbr_base(nb, "0123456789abcdef");
	}
	return (ft_max(pf->large, ft_max(pf->dot, pf->len)));
}

int		conv_d(varpf *pf, va_list ap)
{
	//printf("large = %d\n", pf->large);
	long nb;
	
	nb = (long)va_arg(ap, int);
	if (pf->dot == 0 && nb == 0)
		pf->len = 0;
	else
		pf->len = ft_count(nb);
	if (nb < 0)
	{
		pf->len = ft_count(nb * -1) + 1;
		if (pf->large > ft_max(pf->len, pf->dot))
			ft_printpad(' ', pf->large - (ft_max(pf->len, pf->dot +1)));
		ft_putchar('-');
		if (pf->dot > pf->len -1)
			ft_printpad('0', pf->dot +1 - pf->len);
		ft_putnbr_base(nb * -1, "0123456789");
		return (ft_max(pf->large, ft_max(pf->dot + 1, pf->len)));
	}
	if (nb >= 0)
	{
		if (pf->large > ft_max(pf->len, pf->dot))
			ft_printpad(' ', pf->large - (ft_max(pf->len, pf->dot)));
		if (pf->dot > pf->len)
			ft_printpad('0', pf->dot - pf->len);
		if (!((nb == 0) && (pf->dot == 0)))
			ft_putnbr_base(nb, "0123456789");
	} 
	return (ft_max(pf->large, ft_max(pf->dot, pf->len)));
}

int		conv_s(varpf *pf, va_list ap)
{
	int i;
	char *str;

	str = va_arg(ap, char*);
	if (str == NULL)
		str = "(null)";
	i = 0;
	pf->len = ft_strlen(str);
	if (pf->dot < pf->len && pf->dot != -1)
		pf->len = pf->dot;
	if (pf->large > pf->len)
		ft_printpad(' ', pf->large - pf->len);
	if (pf->dot != -1 && pf->dot <= pf->len)
	{
		while (i < pf->dot)
			ft_putchar(str[i++]);
	}
	else
		ft_putstr(str);
	return (ft_max(pf->large, pf->len));
}

int		ft_conv(varpf *pf, va_list ap)
{
	if (pf->type == 'd')
		return (conv_d(pf, ap));
	 if (pf->type == 'x')
		return (conv_x(pf, ap));
	if (pf->type == 's')
		return (conv_s(pf, ap));
	return (0);
}

int		ft_printf(const char *str, ...)
{
	
	varpf	pf;
	va_list	ap;
	va_start(ap, str);
	pf.i = 0;
	pf.print = 0;
	while (str[pf.i])
	{
		if(str[pf.i] == '%')
		{
			pf.j = pf.i + 1;
			while ((!(checktype(str[pf.i]))) && str[pf.i])
				pf.i++;
			if (str[pf.i] == '\0')
				pf.i = pf.j - 1;
			if (checktype(str[pf.i]))
			{
				pf.print = pf.print + ft_conv(ft_checkconv(ft_initipf(&pf), (char*)&str[pf.j], str[pf.i]), ap);
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