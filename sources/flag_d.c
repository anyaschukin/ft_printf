/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:58:38 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/01 18:25:26 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>


static intmax_t	length_d(va_list *ap, t_print *arg)
{
	if (arg->length == 2 && arg->format[arg->i] != 'D')
		return ((long long)((signed char)va_arg(*ap, int)));
	else if (arg->length == 3 && arg->format[arg->i] != 'D')
		return ((long long)((short int)va_arg(*ap, int)));
	else if (arg->length == 5 || arg->format[arg->i] == 'D')
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

void	flag_d(va_list *ap, t_print *arg)
{
	long long	nb;
	size_t		len;
	int			ret; // add to i for final ret

	nb = length_d(ap, arg);
	len = ft_count(nb);
/*	if (arg->isdash == 1)
	{
		(arg->isplus = 1 && nb > 0)? write(1, "+", 1) : 0;
		ft_putnbr(nb); 
	}*/
	while ((arg->precision > len) && arg->precision-- > 0)
	{
		arg->iszero = 1? write (1, "0", 1) : write(1, " ", 1);
	}
	if (arg->isplus == 1 && nb > 0)
	{
		write(1, "+", 1);
	}
	ft_putnbr(nb);
	while ((arg->width > len) && arg->width-- > 0)
	{
		arg->iszero = 1? write(1, "0", 1) : write(1, " ", 1);
	}
//	ret += ft_strlen(nb);
//ft_putnbr(nb);
}
