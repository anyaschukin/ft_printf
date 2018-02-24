/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:56:29 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/24 18:50:56 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_check_errors(const char *format, t_print *arg, size_t i)
{
	if (arg->ishash == 1 && (format[i] == 'c' || format[i] == 'd' \
			|| format[i] == 'i' || format[i] == 'p' || format[i]  == 's' \
			|| format[i] == 'u'))
		arg->ishash = 0;

/*
** Zero error checks
*/

	if (arg->iszero == 1 && (format[i] == 'd' || format[i] == 'i' \
			|| format[i] == 'o' || format[i] == 'u' || format[i] == 'x' \
			|| format [i] == 'X'))
		arg->iszero = 0;
	if (arg->iszero == 1 && arg->isdash == 1)
		arg->iszero = 0;
	if (arg->iszero == 1 && arg->precision_field == 1 && (format[i] == 'd' \
			|| format[i] == 'i' || format[i] == 'o' || format[i] == 'u' \
			|| format[i] == 'x' || format[i] == 'X'))
		arg->iszero = 0;
	if (arg->isspace == 1 && arg->isplus == 1)
		arg->isspace = 0;

/*
** Length error checks
*/

	if (arg->length == 1 && (format[i] == 'c' || format[i] == 'C' \
			|| format[i] == 'p' || format[i] == 's' || format[i] == 'S'))
		return (-1); // what do I want it to return here?

	/*	flag_err
	width_err
	precision_err
	length_err
*/
	
	
	return (i);
}
