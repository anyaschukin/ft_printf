/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:39:14 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/14 17:43:29 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_flag(char c)
{
	return (c == '-' || c == '+' || c == '0' || c == ' ' || c == '#');
}

size_t	ft_check_flags(const char *format, t_print *arg)
{
	int i;
	
	while (is_flag(format[i]))
	{
		format[i] == '-' ? arg->isdash = 1 : 0;
		format[i] == '+' ? arg->isplus = 1 : 0;
		format[i] == '0' ? arg->iszero = 1 : 0;
		format[i] == ' ' ? arg->isspace = 1 : 0;
		format[i] == '#' ? arg->ishash = 1 : 0;
		i++;
	}
	return (i);
}
