/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:32:11 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/08 17:12:48 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static size_t	ft_printf_parse(va_list *ap, t_print *arg)
{
	//	(*format)++;
	while (!(ft_strchr("cCdDioOpsSuUxX", arg->format[arg->i])) && arg->format[arg->i] != '\0')
	{
		ft_check_flags(arg);
		ft_check_width(arg);
		ft_check_precision(arg);
		ft_check_length(arg);
		ft_check_errors(arg);
//		(*format)++;
	}
	ft_printf_conversion(ap, arg);
	return (arg->i);
}

static size_t	ft_check_printf(const char *format, va_list *ap)
{
	char buf[BUFF_SIZE];
	t_print arg;

	arg.i = 0;
	arg.format = format;
//	ft_bzero(&arg, sizeof(arg));
//	ft_memset(buf, 0, BUFF_SIZE - 1);
	while(arg.format[arg.i])
	{
		if (arg.format[arg.i] == '%')
		{
			arg.i++;
			ft_init_struct(&arg);
			ft_printf_parse( ap, &arg); // have this return the len of what I printed
		// if (ret == -1 || ret == '\0')
		//		break;     >> this way, if there is an error mid-parsing OR you reach the end of the string, break!
		}
		else
		{
			//ft_printf_buffer(format, buf); // put memset in here?
//			ft_putchar('B');
			ft_putchar(arg.format[arg.i]);
			arg.i++; // also increment len every time I print something
		}
	}
//	ft_print_struct(&arg);
	return (arg.i);
}

// (char **)&format

size_t	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	ret;

	va_start(ap, format);
	ret = ft_check_printf(format, &ap);
	va_end(ap);
	return (ret);
}



/*static void	ft_printf_buffer(const char *format, char *buf)
{
	int i;

	i = 0;
	while (*format != '%')
	{
		*buf++ = *format++;
		i++;
		if (i == BUFF_SIZE)
		{
			ft_putstr(buf);
			buf = ft_strnew(BUFF_SIZE);
			i = 0;
		}
		ft_putstr(buf);
		*buf = '\0';
	}
}*/
