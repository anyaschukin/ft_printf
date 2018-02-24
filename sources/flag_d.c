/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:58:38 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/24 12:33:25 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void	flag_d(char *format, va_list *ap, t_print *arg)
{
	unsigned long long nb;

	nb = va_arg(*ap, int);
	ft_putnbr(nb);
}
