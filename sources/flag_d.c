/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:58:38 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/26 17:55:17 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>


static intmax_t	length_d(char *format, va_list *ap, t_print *arg, size_t i)
{
	if (arg->length == 2 && format[i] != 'D')
		return ((long long)((signed char)va_arg(*ap, int)));
	else if (arg->length == 3 && format[i] != 'D')
		return ((long long)((short int)va_arg(*ap, int)));
	else if (arg->length == 5 || format[i] == 'D')
		return ((long long)va_arg(*ap, long));
	else if (arg->length == 6)
		return ((long long)va_arg(*ap, long long));
	else if (arg->length == 4)
		return ((intmax_t)va_arg(*ap, intmax_t));
	else if (arg->length == 7)
		return ((long long)va_arg(*ap, size_t));
	else
		return (va_arg(*ap, int));
}

void	flag_d(char *format, va_list *ap, t_print *arg, size_t i)
{
	long long	nb;
	int			ret; // add to i for final ret

	nb = length_d(format, ap, arg, i);
	if (arg->isplus == 1 && nb > 0)
	{
		write(1, "+", 1);
		ret++;
	}
	while ((arg->width > nb) && arg->width-- > 0)
	{
		arg->iszero = 1? write(1, "0", 1) : write(1, " ", 1);
		ret++;
	}
//	ret += ft_strlen(nb);
	ft_putnbr(nb);
}
