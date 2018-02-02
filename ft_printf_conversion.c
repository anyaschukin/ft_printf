/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:48:07 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/02 18:00:13 by aschukin         ###   ########.fr       */
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
		ft_putchar(c);
	}
	if (*format == 's')
	{
		str = va_arg(*ap, char *);
		ft_putstr(str);
	}
	return (0);
}
