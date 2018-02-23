/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:14:20 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/22 19:58:29 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int	flag_x(char *format, va_list *ap, t_print *arg)
{
	unsigned long long nb;
	int ret;

	nb = va_arg(*ap, unsigned long long);
	ft_putnbr(*ft_utoa_base(nb, 16));
	return (ret);
}
