/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:14:20 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/16 18:15:30 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

static uintmax_t	length_x(va_list *ap, t_print *arg)
{
	if (arg->length == 2 && arg->format[arg->i] != 'X')
		return ((unsigned char)va_arg(*ap, uintmax_t));
	else if (arg->length == 3 && arg->format[arg->i] != 'X')
		return ((unsigned short int)va_arg(*ap, uintmax_t));
	else if (arg->length == 5 || arg->format[arg->i] == 'X')
		return ((unsigned long)va_arg(*ap, uintmax_t));
	else if (arg->length == 6)
		return ((unsigned long long)va_arg(*ap, uintmax_t));
	else if (arg->length == 4)
		return ((uintmax_t)va_arg(*ap, uintmax_t));
	else if (arg->length == 7)
		return ((size_t)va_arg(*ap, uintmax_t));
	else
		return ((unsigned int)va_arg(*ap, uintmax_t));
}

void	flag_x(va_list *ap, t_print *arg)
{
	intmax_t	nb;
	intmax_t	len;
	t_out	out;

	nb = length_x(ap, arg);
//	arg->format[arg->i] == 'x' ? (arg->converter = 'x') : (arg->converter = 'X');
	out.value = ft_utoa_base(nb, 16);
	len = ft_strlen(out.value);
	if(!(out.string = (char*)malloc(sizeof(char) * len + 1)))
		error_exit(ERROR, 1);
	out.string = ft_strcpy(out.string, out.value);
	if (*out.value != '0')
		out.string = combine(arg, &out, len);
	arg->ret += ft_strlen(out.string);
	arg->converter == 'x' ? ft_strtolower(out.string) : ft_strtoupper(out.string);
	ft_putstr(out.string);
	ft_strdel(&out.string);
}
