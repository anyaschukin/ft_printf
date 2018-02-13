/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 10:32:11 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/02 17:59:20 by aschukin         ###   ########.fr       */

/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static int	ft_printf_parse(char **format, va_list *ap, t_print *arg)
{
	int ret;

	ret = 0;
	(*format)++;
	if (format == '\0')
		return (-1);
	/*if (ft_check_flags(format, arg) == NULL)
		return (-1);
	if (ft_check_width(format, ap, arg) == NULL)
		return (-1);
	if (ft_check_precision(format, ap, arg) == NULL)
		return (-1);
	if (ft_check_size(format, arg) == NULL)
		return (-1);
	*/
	ret += ft_printf_conversion(*format, ap, *arg);
	return (ret);
	}

static void	ft_printf_buffer(const char *format, char *buf)
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
}

static int	ft_check_printf(const char *format, va_list *ap, int ret)
{
	char buf[BUFF_SIZE];
	t_print arg;

	ft_bzero(&arg, sizeof(arg));
	ft_memset(buf, 0, BUFF_SIZE - 1);
	while(*format)
	{
		if (*format == '%')
		{
			ft_printf_buffer(format, buf); // put memset in here?
			ret += ft_printf_parse((char **)&format, ap, &arg);
		}
		else
		{
			ret++;
			ft_putchar(*format);
		}
		format++;
	}
	return (ret);
}

// (char **)&format

int	ft_printf(const char *format, ...)
{
	int res; // result?
	va_list ap;

	va_start(ap, format);
	res = ft_check_printf(format, &ap, 0);
	va_end(ap);
	return (res);
}

int main(void)
{
	char *c;

	c = "What did you do to my unicorn?! \n";
	ft_printf("Printy: %s \n", c);
	printf("Printy: %s \n", c);
}
