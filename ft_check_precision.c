/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:38:45 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/13 16:51:02 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_check_precision(char *format, va_list *ap, t_print *arg)
{
	int ret;
	char *cpy;

	ret = 0;
	cpy = (char *)format; // cast to prevent const char warnings
	if (*cpy == '.')
	{
		arg->precision_field = 1;
		cpy++;
		while(*cpy && ft_strchr("012345689", *cpy) != NULL)
		{
			
			// could do a strcat for each digit of cpy that's a number
			// then to an atoi and save in arg->precision
			// but is there a more elegant way?
		}
//		while (ft_isdigit(*format))
//		{
//			
//			arg->precision = va_arg(*ap, int);
//			(*format)++;
//		}
	}
}
