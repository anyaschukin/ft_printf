/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:40:15 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/14 17:40:50 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <limits.h>

size_t	ft_check_width(char *format, va_list *ap, t_print *arg)
{
	char *cpy;
	long long i;
	size_t ret;

	i = 0;
	ret = i;
	cpy = (char *)format; // cast to prevent const char warnings
	cpy[i] = '.' ? arg->width_field = 1 : 0;
	cpy[i] = '.' ? i++ : 0;
	while (cpy[i] >= '0' && cpy[i] <= '9')
	{
		arg->width = arg->width * 10 + (cpy[i] - 48);
		i++;
	}
	if (arg->width > INT_MAX || arg->width <= 0)
	{
		arg->width_field = 0;
		arg->width = 0;
	}
	return (ret);
}
