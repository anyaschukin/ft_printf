/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:14:20 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/05 17:48:44 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

static uintmax_t   length_x(va_list *ap, t_print *arg)
{
	if (arg->length == 2 && arg->format[arg->i] != 'U'
			&& arg->format[arg->i] != 'X' && arg->format[arg->i] != 'O')
		return ((unsigned long long)((unsigned char)va_arg(*ap, int)));
	else if (arg->length == 3 && arg->format[arg->i] != 'U'
			&& arg->format[arg->i] != 'X' && arg->format[arg->i] != 'O')
		return ((unsigned long long)((unsigned short int)va_arg(*ap, int)));
	else if (arg->length == 5 || arg->format[arg->i] == 'U'
			|| arg->format[arg->i] == 'X' || arg->format[arg->i] != 'O')
		return ((unsigned long long)va_arg(*ap, unsigned long));
	else if (arg->length == 6)
		return ((unsigned long long)va_arg(*ap, unsigned long long));
	else if (arg->length == 4)
		return ((uintmax_t)va_arg(*ap, uintmax_t));
	else if (arg->length == 7)
		return ((unsigned long long)va_arg(*ap, size_t));
	else
		return ((unsigned long long)(va_arg(*ap, unsigned int)));
}

void	flag_x(va_list *ap, t_print *arg)
{
	unsigned long long nb;

	nb = length_x(ap, arg);
	ft_putnbr(*ft_utoa_base(nb, 16));
}
