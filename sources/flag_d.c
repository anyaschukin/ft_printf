/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:58:38 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/09 18:20:33 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>


static intmax_t	length_d(va_list *ap, t_print *arg)
{
	if (arg->length == 2 && arg->format[arg->i] != 'D')
		return ((long long)((signed char)va_arg(*ap, int)));
	else if (arg->length == 3 && arg->format[arg->i] != 'D')
		return ((long long)((short int)va_arg(*ap, int)));
	else if (arg->length == 5 || arg->format[arg->i] == 'D')
		return ((long long)va_arg(*ap, long));
	else if (arg->length == 6)
		return ((long long)va_arg(*ap, long long));
	else if (arg->length == 4)
		return ((intmax_t)va_arg(*ap, intmax_t));
	else if (arg->length == 7)
		return ((long long)va_arg(*ap, size_t));
	else
		return (va_arg(*ap, int));
}

void	flag_d(va_list *ap, t_print *arg)
{
	long long	nb;
	intmax_t	len;
	t_out		out;

	nb = length_d(ap, arg);
	nb > 0 ? arg->ispositive = 1 : 0;
	nb < 0? arg->isnegative = 1 : 0;
	len = ft_strlen(ft_itoa(nb));
	out.value = ft_itoa(nb);
	if(!(out.string = (char*)malloc(sizeof(char) * len + 1)))
		error_exit(ERROR, 1);
//	out.string = ft_strcpy(out.string, ft_itoa(nb));
//	out.string[len] = '\0';
	out.string = combine(arg, &out, len);
	len = ft_strlen(out.string);
	ft_putstr(out.string);
	free(out.string);
	ft_bzero(out.string, len);
	// return (out.ret); return how many characters we've printed

}
