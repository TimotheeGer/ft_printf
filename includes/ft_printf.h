/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:55:06 by tigerber          #+#    #+#             */
/*   Updated: 2021/03/05 12:47:35 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct			s_pf
{
	int			a;
	int			i;
	int			j;
	int			indic;
	int			large;
	int			dot;
	char		type;
	int			p;
	int			nega;
	int			len;
	int			count;
}						t_varpf;

int						checktype(char c);
int						ft_strlen(const char *s);
void					print_pad(char c, int len);
int						max(int a, int b);
int						countnum_exa(long long n);
int						countnum(long n);
void					ft_putchar(char c);
void					ft_putstr(char *s);
void					ft_putnbr_base(long nb, char *base);
void					ft_putnbr(long n);
int						ft_isdigit(int c);
int						ft_atoi(char *nptr);
t_varpf					*ip(t_varpf *pf);
t_varpf					*cpf(char *str, t_varpf *pf, char conv, va_list ap);
int						ft_is_zero_new(long long nb, t_varpf *pf, int ret_len);
int						ft_is_nega(long long nb, t_varpf *pf, int ret_len);
int						ft_is_posi(long long nb, t_varpf *pf, int ret_len);
int						conv_pc(t_varpf *pf);
int						conv_s(t_varpf *pf, va_list ap);
int						conv_c(t_varpf *pf, va_list ap);
int						conv_x_maj(t_varpf *pf, va_list ap);
int						conv_x(t_varpf *pf, va_list ap);
int						conv_p(t_varpf *pf, va_list ap);
int						conv_d_i(t_varpf *pf, va_list ap);
int						conv_u(t_varpf *pf, va_list ap);
int						ccv(t_varpf *pf, va_list ap);
int						ft_printf(const char *str, ...);

#endif
