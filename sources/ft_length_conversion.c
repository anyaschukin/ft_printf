/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:17:59 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/21 18:29:55 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t	ft_length_conversion(intmax_t nb, t_print *arg)
{
	if (arg->length == 1)
		return (nb);
	else if (arg->length == 2)
		nb = (char)nb;
	else if (arg->length == 3)
		nb = (short)nb;
	else if (arg->length == 4)
		nb = (intmax_t)nb;
	else if (arg->length == 5)
		nb = (long)nb;
	else if (arg->length == 6)
		nb = (long long)nb;
	else if (arg->length == 7)
		nb = (size_t)nb;
	return (nb);
}
