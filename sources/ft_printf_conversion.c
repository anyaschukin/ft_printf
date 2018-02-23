/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:48:07 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/23 17:57:32 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

size_t	ft_printf_conversion(char *format, va_list *ap, t_print *arg, size_t i)
{
//	int ret;
	
	*format == 'c' ? flag_c(format, ap, arg) : 0;
	*format == 'C' ? flag_c(format, ap, arg) : 0;
	format[i] == 'd' ? flag_d(format, ap, arg, i) : 0;
	*format == 'D' ? flag_d(format, ap, arg, i) : 0;
//	*format == 'i' ? flag_i(format, ap, arg) : 0;
	*format == 'o' ? flag_o(format, ap, arg) : 0;
	*format == 'O' ? flag_o(format, ap, arg) : 0;
	*format == 'p' ? flag_p(format, ap, arg) : 0;
	*format == 's' ? flag_s(format, ap, arg) : 0;
	*format == 'S' ? flag_s(format, ap, arg) : 0;
	*format == 'u' ? flag_u(format, ap, arg) : 0;
	*format == 'U' ? flag_u(format, ap, arg) : 0;
	*format == 'x' ? flag_x(format, ap, arg) : 0;
	*format == 'X' ? flag_x(format, ap, arg) : 0;
	i++;
	return (i);
}


/*
t_funct g_flagtab[]=
{
	{&flag_c, 'c'},
	{&flag_c, 'C'},
	{&flag_d, 'd'},
	{&flag_d, 'D'},
	{&flag_d, 'i'},
	{&flag_o, 'o'},
	{&flag_o, 'O'},
	{&flag_p, 'p'},
	{&flag_s, 's'},
	{&flag_s, 'S'},
	{&flag_u, 'u'},
	{&flag_u, 'u'},
	{&flag_x, 'x'},
	{&flag_capx, 'X'},
	{NULL, -1}
};


size_t	ft_printf_conversion(char *format, va_list *ap, t_print *arg, size_t i)
{
	int x;

	x = 0;
	while (g_flagtab[x].flag != -1)
	{
		if (g_flagtab[x].flag == *format)
			 g_flagtab[x].ptrfunct(format, ap, arg);
		x++;
	}
	i++;
	return (i);
}
*/
