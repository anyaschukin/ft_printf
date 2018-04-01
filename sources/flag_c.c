/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:02:06 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/01 15:19:02 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

/*static unsigned char	length_c(va_list *ap, t_print *arg)
{
	if (arg->length == 5 && arg->format[arg->i] == 'C')
		return((unsigned char)va_arg(*ap , int));
	else
		return ((unsigned char)va_arg(*ap, int));
}*/

void	flag_c(va_list *ap, t_print *arg)
{
	wchar_t		w;
	char		c;
	intmax_t	len;
	t_out		out;

	if (arg->converter == '%')
	{
		out.value = ft_strdup("%");
		c = 1;
		len = 1;
	}
	else if (arg->length == 5 || arg->converter == 'C')
	{
		w = va_arg(*ap, wchar_t);
		out.value = ft_unicode(w);
		out.value = NULL ? out.value = ft_strdup(("(null)")) : 0;
		len = ft_strwlen(out.value);
	}
	else
	{
		if (!(c = va_arg(*ap, intmax_t)))
			c = '\0';
		out.value = ft_strnew(c);
		out.value[0] = c;
	}
	if (!(out.string = (char*)malloc(sizeof(char) * len + 1)))
		error_exit(ERROR, 1);
	out.string = ft_strcpy(out.string, out.value);
	out.string = combine(arg, &out, len);
	arg->ret += ft_strlen(out.string);
	c == 0 ? arg->ret += 1 : 0;
	c == 0 ? ft_putnstr(out.string) : 0;
	c != 0 ? ft_putstr(out.string) : 0;
	ft_strdel(&out.value);
	ft_strdel(&out.string);
}
