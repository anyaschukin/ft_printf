/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:06:02 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/16 16:38:07 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

void	flag_s(va_list *ap, t_print *arg)
{
	wchar_t		*wstr;
	char		*str;
	intmax_t	len;
	t_out		out;

	if (arg->length == 5 || arg->format[arg->i] == 'S')
	{
		wstr = va_arg(*ap, wchar_t *);
		out.value = ft_strunicode(wstr);
		len = ft_strwlen(out.value);
//		ft_putnbr(len);
	}
	else
	{
		str = va_arg(*ap, char *);
		out.value = ft_strnew(str);
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
