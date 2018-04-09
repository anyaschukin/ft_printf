/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:56:29 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/09 15:02:47 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_check_errors(t_print *arg)
{
	if (arg->isspace == 1 && ft_strchr("cCsSuUxXp%", arg->format[arg->i]))
		arg->isspace = 0;
	if (arg->isspace == 1 && arg->isplus == 1)
		arg->isspace = 0;
	if (arg->ishash == 1 && ft_strchr("cCdipsu", arg->format[arg->i]))
		arg->ishash = 0;
	if (arg->iszero == 1 && arg->isdash == 1)
		arg->iszero = 0;
	if (arg->iszero == 1 && arg->precision_field == 1 && ft_strchr("diou", arg->format[arg->i]))
		arg->iszero = 0;
	if (arg->precision_field == 1 && ft_strchr("cC", arg->format[arg->i]))
		arg->precision_field = 0;
	if (arg->length == 1 && ft_strchr("cCpsS", arg->format[arg->i]))
		return (-1);
	if (arg->format[arg->i] == '\'')
		arg->i++;
	return (arg->i);
}
