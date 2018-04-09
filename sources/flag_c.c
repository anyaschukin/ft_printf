/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:02:06 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/09 16:09:11 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_c(va_list *ap, t_print *arg)
{
	wchar_t		w;
	char		c;
	intmax_t	len;
	t_out		out;

	if (arg->converter != 'c' && arg->converter != 'C' && arg->converter != '%' && arg->converter != 'R')
	{
		if (!(c = va_arg(*ap, intmax_t)))
			c = '\0';
		out.value = ft_strnew(1);
		out.value[0] = arg->converter;
		arg->converter = 'c';
	}
	else if (arg->converter == 'R')
		out.value = ft_strdup("R");
	else if (arg->length == 5 || arg->converter == 'C')
	{
		w = va_arg(*ap, wchar_t);
		out.value = ft_unicode(w);
		if (out.value == NULL)
			out.value = ft_strdup(("(null)"));
	}
	else
	{
		if (!(c = va_arg(*ap, intmax_t)))
			c = '\0';
		out.value = ft_strnew(1);
		out.value[0] = c;
	}
	len = ft_strwlen(out.value);
	out.string = ft_strdup(out.value);
	out.string = combine(arg, &out, len);
	arg->ret += ft_strlen(out.string);
	len == 0 ? arg->ret += 1 : 0;
	len == 0 ? ft_putnstr(out.string) : 0;
	len > 0 ? ft_putstr(out.string) : 0;
	ft_strdel(out.value);
	ft_strdel(out.string);
}
