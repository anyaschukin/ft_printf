/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:38:45 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/13 16:51:02 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_check_precision(char *format, va_list *ap, t_print *arg)
{
	char *cpy;
	unsigned long long i;

	i = 0;
	cpy = (char *)format; // cast to prevent const char warnings
	cpy[i] = '.' ? arg->precision_field = 1 : 0;
	cpy[i] = '.' ? i++ : 0; 
	while (cpy[i] >= '0' && cpy[i] <= '9')
	{
		arg->precision = arg->precision * 10 + (cpy[i] - 48);
		i++;
	}
	if (arg->precision > INT_MAX || arg->precision < 0)
	{
		arg->precision_field = 0;
		arg->precision = 0;
	}
	return (n * sign);

