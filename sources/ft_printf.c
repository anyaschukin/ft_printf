/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:32:11 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/24 17:18:47 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static size_t	ft_printf_parse(char **format, va_list *ap, t_print *arg, size_t i)
{
//	(*format)++;
	if (format == '\0')
		return (-1);
	ft_init_struct(arg);
	i = (ft_check_flags(*format, arg, i));
	i = (ft_check_width(*format, arg, i));
	i = (ft_check_precision(*format, arg, i));
	i = (ft_check_length(*format, arg, i));
	i = (ft_check_errors(*format, arg, i));
//		return (-1);
	i = ft_printf_conversion(*format, ap, arg, i);
	return (i);
}

static size_t	ft_check_printf(const char *format, va_list *ap)
{
	char buf[BUFF_SIZE];
	t_print arg;
	size_t	i;

	i = 0;
	ft_bzero(&arg, sizeof(arg));
	ft_memset(buf, 0, BUFF_SIZE - 1);
	while(format[i])
	{
		if (format[i] == '%')
		{
			i++;
			//ft_printf_buffer(format, buf); // put memset in here?
			i = ft_printf_parse((char **)&format, ap, &arg, i);
			printf("\n 4 precision_field = %d\n", arg.precision_field);
		}
		else
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	ft_print_struct(&arg);
	return (i);
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
