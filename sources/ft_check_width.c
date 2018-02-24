/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:40:15 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/24 14:21:30 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <limits.h>

size_t	ft_check_width(char *format, t_print *arg, size_t i)
{
	int	multi;
	int	save;
	int tmp;

	multi = 1;
	save = i;
	tmp = 0;
//	cpy = (char *)format; // cast to prevent const char warnings
	if (format[i] <= '0' || format[i] >= '9')
		return (i);
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	arg->width_field = 1;
	while (i > save)
	{
		tmp++;
		arg->width = arg->width + (format[--i] - 48) * multi;
		multi *= 10;
	}
	i += tmp;
	if (arg->width > INT_MAX || arg->width <= 0)
		arg->width = 0;
	return (i);
}
