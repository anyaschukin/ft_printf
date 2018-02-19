/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:19:35 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/16 15:51:23 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define BUFF_SIZE 1

typedef struct s_print
{
	unsigned int isdash : 1;
	unsigned int isplus : 1;
	unsigned int iszero : 1;
	unsigned int isspace : 1;
	unsigned int ishash : 1;

	unsigned int width_field : 1;
	unsigned int width;

	unsigned int precision_field : 1;
	unsigned int precision;

	char converter;

	enum
	{
		none,
		hh,
		h,
		j,
		l,
		ll,
		z,
	} length;

	size_t index;
	char buf[BUFF_SIZE];
}				t_print;

/*
** ft_printf Functions
*/

int		ft_printf(const char *format, ...);
int		ft_printf_conversion(char *format, va_list *ap, t_print arg);
size_t	ft_check_flags(const char *format, t_print *arg);
size_t	ft_check_width(char *format, va_list *ap, t_print *arg);
size_t	ft_check_precision(char *format, va_list *ap, t_print *arg);
size_t	ft_check_length(const char *format, t_print *arg);
intmax_t	ft_length_conversion(intmax_t nb, t_print *arg);
uintmax_t	ft_ulength_conversion(uintmax_t nb, t_print *arg);


/*
** Conversion Character Functions
*/

typedef struct s_funct
{
		void (*ptrfunct)(char *, va_list *, t_print);
		char flag;
}	t_funct;

void	flag_c(char *format, va_list *ap, t_print arg);
void	flag_d(char *format, va_list *ap, t_print arg);
void	flag_i(char *format, va_list *ap, t_print arg);
void	flag_o(char *format, va_list *ap, t_print arg);
void	flag_p(char *format, va_list *ap, t_print arg);
void	flag_s(char *format, va_list *ap, t_print arg);
void	flag_u(char *format, va_list *ap, t_print arg);
void	flag_x(char *format, va_list *ap, t_print arg);

void	flag_cap_C(char *format, va_list *ap, t_print arg);
void	flag_cap_D(char *format, va_list *ap, t_print arg);
void	flag_cap_O(char *format, va_list *ap, t_print arg);
void	flag_cap_S(char *format, va_list *ap, t_print arg);
void	flag_cap_U(char *format, va_list *ap, t_print arg);
void	flag_cap_X(char *format, va_list *ap, t_print arg);


#endif
