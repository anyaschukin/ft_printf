/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:10:53 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/15 15:26:31 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	flag_u(char *format, va_list *ap, t_print arg)
{
	unsigned long long nb;

	nb = va_arg(*ap, unsigned int);
	// ft_check_errors  to parse for errors?
	// ft_ulength_conversion(uintmax_t nb, t_print *arg) -> cast your argument due to the length modifier
	ft_putnbr(*ft_utoa_base(nb, 10));
}
