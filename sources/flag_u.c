/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:10:53 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/31 17:42:26 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

static uintmax_t	length_u(va_list *ap, t_print *arg)
{
	if (arg->length == 2 && arg->format[arg->i] != 'U')
		return ((unsigned char)va_arg(*ap, uintmax_t));
	else if (arg->length == 3 && arg->format[arg->i] != 'U')
		return ((unsigned short int)va_arg(*ap, uintmax_t));
	else if (arg->length == 5 || arg->format[arg->i] == 'U')
		return ((unsigned long)va_arg(*ap, uintmax_t));
	else if (arg->length == 6)
		return ((unsigned long long)va_arg(*ap, uintmax_t));
	else if (arg->length == 4)
		return ((uintmax_t)va_arg(*ap, uintmax_t));
	else if (arg->length == 7)
		return ((unsigned long long)va_arg(*ap, size_t));
	else
		return ((unsigned int)va_arg(*ap, uintmax_t));
	//	return (va_arg(*ap, uintmax_t));
}

void	flag_u(va_list *ap, t_print *arg)
{
	unsigned long long	nb;
	intmax_t			len;
	t_out				out;

	nb = length_u(ap, arg);
	len = ft_count(nb);
	out.value = ft_utoa_base(nb, 10);
	if(!(out.string = (char*)malloc(sizeof(char) * len + 1)))
		error_exit(ERROR, 1);
	out.string = ft_strcpy(out.string, out.value);
	out.string = combine(arg, &out, len);
	arg->ret += ft_strlen(out.string);
	ft_putstr(out.string);
	ft_strdel(&out.string);
}
