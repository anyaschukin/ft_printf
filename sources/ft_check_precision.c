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

size_t	ft_check_precision(t_print *arg)
{
	int		multi;
	int		save;
	int		tmp;

	multi = 1;
	tmp = 0;
//	cpy = (char *)format; // cast to prevent const char warnings
	arg->format[arg->i] == '.' ? arg->precision_field = 1 : 0;
	if (arg->format[arg->i] == '.')
		arg->i++;
	save = arg->i;
//	if (!(ft_isdigit(cpy[i])))
//		arg->precision_field = 0;
	while (arg->format[arg->i] >= '0' && arg->format[arg->i] <= '9')
		arg->i++;
	while (arg->i > save)
	{
		tmp++;
		arg->i--;
		arg->precision = arg->precision + (arg->format[arg->i] - 48) * multi;
		multi *= 10;
	}
	arg->i += tmp;
	if (arg->precision > INT_MAX || arg->precision <= 0)
	{
		arg->precision_field = -1;
		arg->precision = 0;
	}
	return (arg->i);
}
