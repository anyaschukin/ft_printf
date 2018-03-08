/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:40:15 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/06 20:08:41 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

size_t	ft_check_width(t_print *arg)
{
	int	multi;
	int	save;
	int tmp;

	multi = 1;
	save = arg->i;
	tmp = 0;
	if (arg->format[arg->i] < '0' || arg->format[arg->i] > '9')
		return (arg->i);
	while (arg->format[arg->i] >= '0' && arg->format[arg->i] <= '9')
		arg->i++;
	arg->width_field = 1;
	while (arg->i > save)
	{
		tmp++;
		arg->i--;
		arg->width = arg->width + (arg->format[arg->i] - 48) * multi;
		multi *= 10;
	}
	arg->i += tmp;
	if (arg->width > INT_MAX || arg->width <= 0)
		arg->width = 0;
	return (arg->i);
}
