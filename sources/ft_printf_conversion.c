/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:48:07 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/01 16:52:21 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

size_t	ft_printf_conversion(va_list *ap, t_print *arg)
{
	arg->format[arg->i] == 'C' ? flag_c(ap, arg) : 0;
	arg->format[arg->i] == 'c' ? flag_c(ap, arg) : 0;
	arg->format[arg->i] == 'd' ? flag_d(ap, arg) : 0;
	arg->format[arg->i] == 'D' ? flag_d(ap, arg) : 0;
	arg->format[arg->i] == 'i' ? flag_d(ap, arg) : 0;
	arg->format[arg->i] == 'o' ? flag_o(ap, arg) : 0;
	arg->format[arg->i] == 'O' ? flag_o(ap, arg) : 0;
	arg->format[arg->i] == 'p' ? flag_p(ap, arg) : 0;
	arg->format[arg->i] == 's' ? flag_s(ap, arg) : 0;
	arg->format[arg->i] == 'S' ? flag_s(ap, arg) : 0;
	arg->format[arg->i] == 'u' ? flag_u(ap, arg) : 0;
	arg->format[arg->i] == 'U' ? flag_u(ap, arg) : 0;
	arg->format[arg->i] == 'x' ? flag_x(ap, arg) : 0;
	arg->format[arg->i] == 'X' ? flag_x(ap, arg) : 0;
	arg->i++;
	return (arg->i);
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
