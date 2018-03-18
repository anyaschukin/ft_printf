/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:39:49 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/18 21:14:54 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	what_length(char c)
{
	return (c == 'h' || c == 'j' || c == 'l'|| c == 'z');
}

size_t	ft_check_length(t_print *arg)
{
	while (what_length(arg->format[arg->i]))
	{
		arg->format[arg->i] == 'h' ? arg->length = h : 0;
		arg->format[arg->i] == 'j' ? arg->length = j : 0;
		arg->format[arg->i] == 'l' ? arg->length = l : 0;
		arg->format[arg->i] == 'z' ? arg->length = z : 0;
		if (arg->format[arg->i] == 'h' && arg->format[arg->i + 1] == 'h')
		{
			arg->length = 2;
			arg->i++;
		}
		if (arg->format[arg->i] == 'l' && arg->format[arg->i + 1] == 'l')
		{
			arg->length = 6;
			arg->i++;
		}
		arg->i++;
	}
	return (arg->i);
}
