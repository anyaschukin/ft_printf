/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:39:49 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/21 18:29:37 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	what_length(char c)
{
	return (c == 'h' || c == 'j' || c == 'l' || c == 'L' || \
			c == 't' || c == 'w' || c == 'z');
}

size_t	ft_check_length(const char *format, t_print *arg)
{
	int i;

	i = 0;
	while (what_length(format[i]))
	{
		format[i] == 'h' ? arg->length = 1 : 0;
		format[i] == 'j' ? arg->length = 1 : 0;
		format[i] == 'l' ? arg->length = 1 : 0;
		format[i] == 'L' ? arg->length = 1 : 0;
		format[i] == 't' ? arg->length = 1 : 0;
		format[i] == 't' ? arg->length = 1 : 0;
		format[i] == 'w' ? arg->length = 1 : 0;
		format[i] == 'z' ? arg->length = 1 : 0;
		i++;
	}
	return (i);
}
