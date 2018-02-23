/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulength_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 15:21:43 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/21 18:30:26 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

uintmax_t	ft_ulength_conversion(uintmax_t nb, t_print *arg)
{
	if (arg->length == 1)
		nb = nb;
	else if (arg->length == 2)
		nb = (unsigned char)nb;
	else if (arg->length == 3)
		nb = (unsigned short)nb;
	else if (arg->length == 4)
		nb = (uintmax_t)nb;
	else if (arg->length == 5)
		nb = (unsigned long)nb;
	else if (arg->length == 6)
		nb = (unsigned long long)nb;
	else if (arg->length == 7)
		nb = (size_t)nb;
	return (nb);
}
