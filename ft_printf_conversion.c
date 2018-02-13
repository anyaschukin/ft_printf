/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:48:07 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/12 13:50:22 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf_conversion(char *format, va_list *ap, t_print arg)
{
	unsigned long long nb;
	wchar_t c;
	char *str;

	if (*format == 'd' || *format == 'i')
	{
		if (nb < -2147483647 || nb > 2147483647)
			return (-1);
		else
		{
			nb = va_arg(*ap, int);
			ft_putnbr(nb);
		}
	}
	if (*format == 'c')
	{
		c = (unsigned char) va_arg(*ap, int);
		ft_putwchar(c);
	}
	if (*format == 's')
	{
		str = va_arg(*ap, char *);
		ft_putwstr(str);
	}
	if (*format == 'u')
	{
		nb = va_arg(*ap, unsigned int);
		ft_putnbr(*ft_utoa_base(nb, 10));
	}
	if (*format == 'x')
	{
		nb = va_arg(*ap, unsigned long long);
		ft_putnbr(*ft_utoa_base(nb, 16));
	}
	if (*format == 'p')
	{
	}
	return (0);
}
