/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:02:06 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/25 16:28:28 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

void	flag_c(va_list *ap, t_print *arg)
{
	wchar_t c;

	if (arg->length == 5  && arg->format[arg->i] == 'C')
	{
		c = (unsigned char) va_arg(*ap, int);
		ft_putwchar(c);
	}
	else
	{
		c = (unsigned char) va_arg(*ap, int);
		ft_putchar(c);
	}
}
