/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:06:02 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/25 17:11:10 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

void	flag_s(va_list *ap, t_print *arg)
{
	wchar_t *str;

	if (arg->length == 5  && arg->format[arg->i] == 'S')
	{
		str = va_arg(*ap, wchar_t *);
		ft_putwstr(str);
	}
	else
	{
		str = va_arg(*ap, wchar_t *);
		ft_putstr((char *)str);
	}
}
