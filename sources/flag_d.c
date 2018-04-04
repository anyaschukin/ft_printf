/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:58:38 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/04 21:05:53 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

intmax_t    length_d(va_list *ap, t_print *arg)
{
	if (arg->length == 2 && arg->format[arg->i] != 'D')
		return ((long long)((signed char)va_arg(*ap, int)));
	else if (arg->length == 1 && arg->format[arg->i] != 'D')
		return ((int)(va_arg(*ap, int)));
	else if (arg->length == 3 && arg->format[arg->i] != 'D')
		return ((long long)((short int)va_arg(*ap, int)));
	else if (arg->length == 6)
		return ((long long)va_arg(*ap, long long));
	else if (arg->length == 4)
		return ((intmax_t)va_arg(*ap, intmax_t));
	else if (arg->length == 7)
		return ((long long)va_arg(*ap, size_t));
	else
		return ((long long)va_arg(*ap, intmax_t));
}

void	flag_d(va_list *ap, t_print *arg)
{
	intmax_t	nb;
	intmax_t	len;
	char		*n;
	char		*m;
	t_out		out;

	nb = length_d(ap, arg);
	out.value = (nb == 0 && !arg->isplus && (arg->precision_field == 1 && arg->precision == 0) && arg->length == 1) ? ft_strdup("\0") : ft_itoa(nb);
	(nb >= 0) ? (arg->ispositive = 1) \
		   : (arg->isnegative = 1);
	len = ft_count(nb);
	out.string = ft_strdup(out.value);
	out.string = combine(arg, &out, len);
	if (arg->isnegative && arg->precision && ft_strchr(out.string, '0'))
	{
		n = ft_strchr(out.string, '-');
		m = ft_strchr(out.string, '0');
		*m = '-';
		*n = '0';
	}
	arg->ret += ft_strlen(out.string);
	ft_putstr(out.string);
	ft_strdel(out.value);
	ft_strdel(out.string);
}
