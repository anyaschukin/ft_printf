/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:48:07 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/02 16:02:52 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf_conversion(char *format, va_list *ap, t_print arg)
{
	int nb;
	unsigned char c;
	char *str;

	if (*format == 'd' || *format == 'i')
	{
		nb = va_arg(*ap, int);
		ft_putnbr(nb);
	}
	if (*format == 'c')
	{
		c = (unsigned char) va_arg(*ap, int);
		ft_putchar(c);
	}
	if (*format == 's')
	{
		str = (unsigned char) va_arg(*ap, int);
		ft_putstr(str);
	}
	return (0);
}
