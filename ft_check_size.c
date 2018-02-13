/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:39:49 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/11 18:40:02 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_size(char c)
{
	return (c == 'l' || c == 'h' || c == 'j' || c == 'z')
}


int	ft_check_size(const char *format, t_print *arg)
{
	int i;

	while (is_size(format[i]))
	{
		format[i] == 'h' ? enum = 1 : 0; // figure out how to work enum
		format[i] == 'j' ? enum = 1 : 0;
		format[i] == 'l' ? enum = 1 : 0;
		format[i] == 't' ? enum = 1 : 0;
		format[i] == 'w' ? enum = 1 : 0;
		format[i] == 'z' ? enum = 1 : 0;
		i++;
	}
	return (i);
}
