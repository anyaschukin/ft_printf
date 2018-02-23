/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_capx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:07:27 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/22 19:57:45 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// temorary function, everything within brackets is nonsense

int	flag_capx(char *format, va_list *ap, t_print *arg)
{
	char *str;
	int ret;

	str = va_arg(*ap, char *);
	ft_putwstr(str);
	return (ret);
}
