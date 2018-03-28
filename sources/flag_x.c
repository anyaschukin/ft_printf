/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:14:20 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/28 14:39:00 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

uintmax_t   length_x(va_list *ap, t_print *arg)
{
	if (arg->length == 1 && arg->format[arg->i] != 'U'
			&& arg->format[arg->i] != 'O')
		return ((unsigned int)(va_arg(*ap, unsigned long long)));
	else if (arg->length == 2 && arg->format[arg->i] != 'U'
			&& arg->format[arg->i] != 'O')
		return ((long long)((unsigned char)va_arg(*ap, int)));
	else if (arg->length == 3 && arg->format[arg->i] != 'U'
			&& arg->format[arg->i] != 'O')
		return (((unsigned long long)(unsigned short int)va_arg(*ap, int)));
	else if (arg->length == 6)
		return ((unsigned long long)va_arg(*ap, unsigned long long));
	else if (arg->length == 7)
		return ((unsigned long long)va_arg(*ap, size_t));
	else if (arg->length == 4)
		return ((uintmax_t)va_arg(*ap, uintmax_t));
	else
		return ((unsigned long)va_arg(*ap, uintmax_t));
}

/*
static uintmax_t	length_x(va_list *ap, t_print *ap)
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
}*/

void	flag_x(va_list *ap, t_print *arg)
{
	intmax_t	nb;
	intmax_t	len;
	t_out	out;

	nb = length_x(ap, arg);
	if (nb == 0 && arg->precision_field == 1)
	{
		out.value = "";
		arg->ishash = 0;
	}
	else
		out.value = ft_utoa_base(nb, 16);
	len = ft_strlen(out.value);
	if (!(out.string = (char*)malloc(sizeof(char) * len + 1)))
		error_exit(ERROR, 1);
	out.string = ft_strcpy(out.string, out.value);
	if (*out.value != '0')
		out.string = combine(arg, &out, len);
	arg->ret += ft_strlen(out.string);
//	!ft_strchr(out.string, 'X') ? out.string[1] = 'x' : 0;
	if (arg->ishash == 1 && nb != 0 && (out.string[1] == '0') && (!ft_strchr(out.string, 'x') || !ft_strchr(out.string, 'X')))
		out.string[1] = 'x';
	arg->converter == 'x' ? ft_strtolower(out.string) : ft_strtoupper(out.string);
	ft_putstr(out.string);
	ft_strdel(&out.string);
}
