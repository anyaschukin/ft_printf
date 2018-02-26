/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:48:07 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/26 17:55:14 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

size_t	ft_printf_conversion(char *format, va_list *ap, t_print *arg, size_t i)
{
	format[i] == 'c' ? flag_c(format, ap, arg, i) : 0;
	format[i] == 'C' ? flag_c(format, ap, arg, i) : 0;
	format[i] == 'd' ? flag_d(format, ap, arg, i) : 0;
	format[i] == 'D' ? flag_d(format, ap, arg, i) : 0;
	format[i] == 'i' ? flag_d(format, ap, arg, i) : 0;
	format[i] == 'o' ? flag_o(format, ap, arg, i) : 0;
	format[i] == 'O' ? flag_o(format, ap, arg, i) : 0;
	format[i] == 'p' ? flag_p(format, ap, arg, i) : 0;
	format[i] == 's' ? flag_s(format, ap, arg, i) : 0;
	format[i] == 'S' ? flag_s(format, ap, arg, i) : 0;
	format[i] == 'u' ? flag_u(format, ap, arg, i) : 0;
	format[i] == 'U' ? flag_u(format, ap, arg, i) : 0;
	format[i] == 'x' ? flag_x(format, ap, arg, i) : 0;
	format[i] == 'X' ? flag_x(format, ap, arg, i) : 0;
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
