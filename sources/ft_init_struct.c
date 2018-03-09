/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 19:50:18 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/09 13:33:51 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_init_struct(t_print *arg)
{
	size_t i;
	
	i = 0;
	arg->isdash = 0;
	arg->isplus = 0;
	arg->iszero = 0;
	arg->isspace = 0;
	arg->ishash = 0;
	arg->width_field = 0;
	arg->width = 0;
	arg->precision_field = 0;
	arg->precision = 0;
	arg->ispositive = 0;
	arg->isnegative = 0;
	return (i);
}
