/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:19:35 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/02 14:32:55 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
		L,
		ll,
		t,
		w,
		z,
	} size;

	size_t index;
	char buf[BUFF_SIZE];
}				t_print;


/*
**	Conversion Character Functions
*/

/*

typedef struct s_funct
{
		char *(*ptrfunct)(va_list ap, char format);
		char spot;
}				t_funct;

t_funct g_tab[] =
{
	{&print_d, 'd'},
	{&print_i, 'i'},  // same function as for 'd', so you can just recycle that function
	{&print_u, 'u'},
	{&print_s, 's'},
	{&print_S, 'S'},
	{&print_c, 'c'},
	{&print_m, 'm'},
	{&print_b, 'b'},
	{&print_x, 'x'},
	{&print_X, 'X'},
	{&print_p, 'p'},
	{NULL, -1}
}

va_list       print_d(va_arg ap, int);
va_list       print_i(va_arg ap, int);
va_list       print_u(va_arg ap, int);
va_list       print_s(va_arg ap, char *);
va_list       print_S(va_arg ap, char *);
va_list       print_c(va_arg ap, int);
va_list       print_m(va_arg ap, int);
va_list       print_b(va_arg ap, int);
va_list       print_x(va_arg ap, int);
va_list       print_X(va_arg ap, int);
va_list       print_p(va_arg ap, int);


*/

/*
**	ft_printf Functions
**
*/

int ft_printf(const char *format, ...);
int ft_printf_conversion(char *format, va_list *ap, t_print arg);

#endif
