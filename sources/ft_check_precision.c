/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:38:45 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/24 16:13:09 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <limits.h>
//
#include <stdio.h>

size_t	ft_check_precision(char *format, t_print *arg, size_t i)
{
	int		multi;
	int		save;
	int		tmp;

	multi = 1;
	tmp = 0;
//	cpy = (char *)format; // cast to prevent const char warnings
	format[i] == '.' ? arg->precision_field = 1 : 0;
	if (format[i] == '.')
		i++;
	save = i;
//	if (!(ft_isdigit(cpy[i])))
//		arg->precision_field = 0;
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	while (i > save)
	{
		tmp++;
		arg->precision = arg->precision + (format[--i] - 48) * multi;
		multi *= 10;
	}
	i += tmp;
	if (arg->precision > INT_MAX || arg->precision <= 0)
	{
		arg->precision_field = -1;
		arg->precision = 0;
	}
	return (i);
}
