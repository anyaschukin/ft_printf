/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:38:45 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/22 14:54:37 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <limits.h>

size_t	ft_check_precision(char *format, t_print *arg, size_t i)
{
//	char		*cpy;
	size_t		ret;

//	i = 0;
//	ret = i;
//	cpy = (char *)format; // cast to prevent const char warnings
	format[i] = '.' ? arg->precision_field = 1 : 0;
//	format[i] = '.' ? i++ : 0;
	if (format[i] == '.')
		i++;
//	if (!(ft_isdigit(cpy[i])))
//		arg->precision_field = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		arg->precision = arg->precision * 10 + (format[i] - 48);
		i++;
	}
	if (arg->precision > INT_MAX || arg->precision <= 0)
	{
		arg->precision_field = 0;
		arg->precision = 0;
	}
	return (ret);
}
