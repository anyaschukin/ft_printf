/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:10:53 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/25 18:34:26 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

void	flag_u(va_list *ap, t_print *arg)
{
	unsigned long long nb;

	nb = va_arg(*ap, unsigned int);
	ft_ulength_conversion(nb, arg); //-> cast your argument due to the length modifier (uintmax)
	ft_putnbr(*ft_utoa_base(nb, 10));
}
