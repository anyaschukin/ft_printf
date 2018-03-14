/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:14:20 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/14 16:45:39 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

static uintmax_t	length_o(va_list *ap, t_print *arg)
{
	if (arg->length == 2 && arg->format[arg->i] != 'O')
		return ((unsigned char)va_arg(*ap, uintmax_t));
	else if (arg->length == 3 && arg->format[arg->i] != 'O')
		return ((unsigned short int)va_arg(*ap, uintmax_t));
	else if (arg->length == 5 || arg->format[arg->i] == 'O')
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

void	flag_o(va_list *ap, t_print *arg)
{
	intmax_t	nb;
	intmax_t	len;
	t_out	out;

	nb = length_o(ap, arg);
	len = ft_count(nb);
	out.value = ft_utoa_base(nb, 8);
	if(!(out.string = (char*)malloc(sizeof(char) * len + 1)))
		error_exit(ERROR, 1);
	out.string = ft_strcpy(out.string, out.value);
	out.string = combine(arg, &out, len);
	arg->ret += ft_strlen(out.string);
	ft_putstr(out.string);
	ft_strdel(&out.string);
}
