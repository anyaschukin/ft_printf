/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:56:29 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/27 16:08:17 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_check_errors(t_print *arg)
{

/*
** Space error checks
*/

	if (arg->isspace == 1 && ft_strchr("cCsSuUxXp%", arg->format[arg->i]))
		arg->isspace = 0;
	//		(arg->format[arg->i] == 'c' || arg->format[arg->i] == 'C' || arg->format[arg->i] == '%' || arg->format[arg->i] == 's' || arg->format[arg->i] == 'S' || arg->format[arg->i] == 'x' || arg->format[arg->i] == 'X' || arg->format[arg->i] == 'p'))
	if (arg->isspace == 1 && arg->isplus == 1)
		arg->isspace = 0;

/*
** Hash error checks
*/

	if (arg->ishash == 1 && (arg->format[arg->i] == 'c' || arg->format[arg->i] == 'C' || arg->format[arg->i] == 'd' \
			|| arg->format[arg->i] == 'i' || arg->format[arg->i] == 'p' || arg->format[arg->i]  == 's' \
			|| arg->format[arg->i] == 'u'))
		arg->ishash = 0;

/*
** Zero error checks
*/
	if (arg->iszero == 1 && ft_strchr("sS", arg->format[arg->i]))
		//!(arg->format[arg->i] == 'd' || arg->format[arg->i] == 'i' \
			|| arg->format[arg->i] == 'o' || arg->format[arg->i] == 'u' || arg->format[arg->i] == 'x' || arg->format[arg->i] == 'C'))
		arg->iszero = 0;
	if (arg->iszero == 1 && arg->isdash == 1)
		arg->iszero = 0;
	if (arg->iszero == 1 && arg->precision_field == 1 && (arg->format[arg->i] == 'd' \
			|| arg->format[arg->i] == 'i' || arg->format[arg->i] == 'o' || arg->format[arg->i] == 'u'))
		arg->iszero = 0;

/*
** Precision error checks
*/

//	if (arg->precision_field == 1)
//		arg->isdash = 0;
	if (arg->precision_field == 1 && (arg->format[arg->i] == 'c' || arg->format[arg->i] == 'C'))
		arg->precision_field = 0;
/*
** Length error checks
*/

	if (arg->length == 1 && (arg->format[arg->i] == 'c' || arg->format[arg->i] == 'C' \
			|| arg->format[arg->i] == 'p' || arg->format[arg->i] == 's' || arg->format[arg->i] == 'S'))
		return (-1); // what do I want it to return here?

	if (arg->format[arg->i] == '\'')
		arg->i++;
	/*	flag_err
	width_err
	precision_err
	length_err
*/

	return (arg->i);
}
