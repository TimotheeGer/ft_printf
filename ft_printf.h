/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:55:06 by tigerber          #+#    #+#             */
/*   Updated: 2021/02/25 15:54:32 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define   FT_PRINTF_H

#include <libc.h>
#include <stdarg.h>

typedef struct	pf
{
	int		i;
	int		j;
	int		indic;
	int		large;
	int		dot;
	char	type;
	char	*base;
	int		print;
	int		nega;
}				varpf;

int		    checktype(char c);
int			ft_strlen(const char *s);
int			countnum_exa(long n);
int			countnum(long n);
void		ft_putchar(char c);
void		ft_putstr(char *s);
void		ft_putnbr_base(long nb, char *base);
void		ft_putnbr(long n);
int         ft_isdigit(int c);
int         ft_atoi(char *nptr);
varpf	    *initiapf(varpf *pf);
varpf	    *checkpf(char *str, varpf *pf, char conv, va_list ap);
int     	ft_if_one_exa_maj(long i, int j, int dot, int nega);
int     	ft_if_two_exa_maj(long i, int j, int dot, int large, int indic);
int     	ft_if_three_exa_maj(long i, int j, int dot, int large, int indic);
int     	ft_if_one_exa_min(long i, int j, int dot, int nega);
int     	ft_if_two_exa_min(long i, int j, int dot, int large, int indic);
int     	ft_if_three_exa_min(long i, int j, int dot, int large, int indic);
int     	ft_if_one(long i, int j, int dot, int nega);
int     	ft_if_two(long i, int j, int dot, int large, int indic);
int     	ft_if_three(long i, int j, int dot, int large, int indic);
int     	ft_if_two_nega(long i, int j, int dot, int large, int indic);
int     	ft_if_three_nega(long i, int j, int dot, int large, int indic);
int			ft_is_zero(long i, int dot, int large);
int     	conv_s(varpf *pf, va_list ap);
int     	conv_c(varpf *pf, va_list ap);
int     	conv_x_maj(varpf *pf, va_list ap);
int     	conv_x(varpf *pf, va_list ap);
int     	conv_p(varpf *pf, va_list ap);
int			conv_d_i(varpf *pf, va_list ap);
int			conv_u(varpf *pf, va_list ap);
int			checkconv(varpf *pf, va_list ap);
int		    ft_printf(const char *str, ...);


#endif
