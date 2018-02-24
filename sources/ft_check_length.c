/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:39:49 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/24 17:54:49 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	what_length(char c)
{
	return (c == 'h' || c == 'j' || c == 'l'|| c == 'z');
}

size_t	ft_check_length(const char *format, t_print *arg, size_t i)
{
	while (what_length(format[i]))
	{
		format[i] == 'h' ? arg->length = h : 0;
		format[i] == 'j' ? arg->length = j : 0;
		format[i] == 'l' ? arg->length = l : 0;
		format[i] == 'z' ? arg->length = z : 0;
		if (format[i] == 'h' && format[i + 1] == 'h')
		{
			arg->length = hh;
			i++;
		}
		if (format[i] == 'l' && format[i + 1] == 'l')
		{
			arg->length = ll;
			i++;
		}
		i++;
	}
	return (i);
}
