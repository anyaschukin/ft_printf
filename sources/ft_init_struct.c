/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:50:18 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/01 21:04:17 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init_pstruct(t_print *arg)
{
	arg->converter = 0;
	arg->isdash = 0;
	arg->isplus = 0;
	arg->iszero = 0;
	arg->isspace = 0;
	arg->ishash = 0;
	arg->ispercent = 0;
	arg->width_field = 0;
	arg->width = 0;
	arg->precision_field = -1;
	arg->precision = 0;
	arg->length = 1;
	arg->ispositive = 0;
	arg->isnegative = 0;
}

void	ft_init_ostruct(t_out *out)
{
	out->string = NULL;
	out->value = NULL;
	out->vlen = 0;
}

void	ft_init_struct(t_print *arg, t_out *out)
{
	ft_init_pstruct(arg);
	ft_init_ostruct(out);
}
