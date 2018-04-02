/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:24:20 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/02 16:54:57 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void	flag_c(va_list *ap, t_print *arg)
{
	wchar_t		w;
	char		c;
	intmax_t	len;
	t_out		out;

	c = 1;
	w = 1;
	len = 1;
	else if (arg->length == 5 || arg->converter == 'C')
	{
		w = va_arg(*ap, wchar_t);
		out.value = ft_unicode(w);
		if (out.value == NULL)
		{
			out.value = ("(null)");
			len = ft_strlen(out.value);
		}
		else
			len = ft_strwlen(out.value);
	}
	else
	{
		if (!(c = va_arg(*ap, intmax_t)))
			c = '\0';
		out.value = ft_strnew(1);
		out.value[0] = c;
	}
	out.string = ft_strdup(out.value);
	
	//	if (!(out.string = (char*)malloc(sizeof(char) * (len + 1))))
		error_exit(ERROR, 1);
	out.string = ft_strcpy(out.string, out.value);
	out.string = ft_strdup(out.value);
	out.string = combine(arg, &out, len);
	arg->ret += ft_strlen(out.string);
	(c == 0 || w == 0) ? arg->ret += 1 : 0;
	(c == 0 || w == 0) ? ft_putnstr(out.string) : 0;
	(c != 0 || w != 0) ? ft_putstr(out.string) : 0;
	ft_strdel(&out.value);
	ft_strdel(&out.string);
}
