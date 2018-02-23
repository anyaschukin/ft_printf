/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:40:15 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/23 15:47:07 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

size_t	ft_check_width(char *format, t_print *arg, size_t i)
{
	char	*cpy;
	int		multi;
	size_t	ret;

	ret = i;
	printf("two ");
	printf("%zu ", i);
//	cpy = (char *)format; // cast to prevent const char warnings
	if (format[i] <= '0' || format[i] >= '9')
		return (i);
	printf("three ");
	while (format[i] >= '0' || format[i] <= '9')
		i++;
	while (i > ret)
	{
		arg->width = arg->width + (format[--i] - 48) * multi;
		multi *= 10;
	}
	if (arg->width > INT_MAX || arg->width <= 0)
		arg->width = 0;
	return (i);
}
