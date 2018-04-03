/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:32:11 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/03 18:44:12 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static size_t	ft_printf_parse(va_list *ap, t_print *arg)
{
//	while (!(ft_strchr("cCdDioOpsSuUxX%", arg->format[arg->i])) && arg->format[arg->i] != '\0')
	while (ft_strchr("-+0 #0123456789.hljz", arg->format[arg->i]) && arg->format[arg->i] != '\0')
	{
		ft_check_flags(arg);
		ft_check_width(arg);
		ft_check_precision(arg);
		ft_check_length(arg);
		ft_check_errors(arg);
	}
	if (ft_strchr("cCdDioOpsSuUxX%RZ", arg->format[arg->i]))
		ft_printf_conversion(ap, arg);
	return (arg->i);
}

static size_t	ft_check_printf(const char *format, va_list *ap)
{
	t_print arg;
	t_out out;

	arg.i = 0;
	arg.ret = 0;
	arg.format = format;
	while(arg.format[arg.i])
	{
		if (arg.format[arg.i] == '%')
		{
			arg.i++;
			if (arg.format[arg.i] == '\0')
				return (arg.ret);
			ft_init_struct(&arg, &out);
			ft_printf_parse(ap, &arg); // have this return the len of what I printed
	//	if (arg.format[arg.i] == '\0' || arg.ret == -1 || arg.ret == '\0')
	//		break;
		//	ft_init_struct(&arg);
		}
		else
		{
			ft_putchar(arg.format[arg.i]);
			arg.i++;
			arg.ret++;
		}
	}
//	ft_print_struct(&arg);
	return (arg.ret);
}


size_t	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	ret;

	va_start(ap, format);
	ret = ft_check_printf(format, &ap);
	va_end(ap);
	return (ret);
}
