/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:39:14 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/14 16:59:47 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static int	is_flag(char c)
{
	return (c == '-' || c == '+' || c == '0' || c == ' ' || c == '#');
}

size_t	ft_check_flags(t_print *arg)
{
	while (is_flag(arg->format[arg->i]))
	{
		arg->format[arg->i] == '-' ? arg->isdash = 1 : 0;
		arg->format[arg->i] == '+' ? arg->isplus = 1 : 0;
		arg->format[arg->i] == '0' ? arg->iszero = 1 : 0;
		arg->format[arg->i] == ' ' ? arg->isspace = 1 : 0;
		arg->format[arg->i] == '#' ? arg->ishash = 1 : 0;
		arg->i++;
	}
	return (arg->i);
}
