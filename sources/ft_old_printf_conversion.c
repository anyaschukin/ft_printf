/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_old_printf_conversion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:19:35 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/21 18:30:01 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int	ft_old_printf_conversion(char *format, va_list *ap, t_print arg)
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
