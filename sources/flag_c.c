/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:02:06 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/14 17:16:34 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

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

	if (arg->length == 5 || arg->converter == 'C')
	{
		w = va_arg(*ap, wchar_t);
		out.value = ft_unicode(w);
		len = ft_strwlen(out.value);
	}
	else
	{
		c = (unsigned char)va_arg(*ap, int);
		out.value = ft_strnew(c);
		len = ft_strlen(out.value);
	}
	if(!(out.string = (char*)malloc(sizeof(char) * len + 1)))
		error_exit(ERROR, 1);
	out.string = ft_strcpy(out.string, out.value);
	out.string = combine(arg, &out, len);
	arg->ret += ft_strlen(out.string);
	ft_putstr(out.string);
	ft_strdel(&out.string);
}
