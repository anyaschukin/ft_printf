/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:06:02 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/14 16:08:07 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	flag_s(char *format, va_list *ap, t_print arg)
{
	char *str;

	str = va_arg(*ap, char *);
	ft_putwstr(str);
}
