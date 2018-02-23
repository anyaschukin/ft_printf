/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:02:06 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/22 19:57:25 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>

int	flag_c(char *format, va_list *ap, t_print *arg)
{
	wchar_t c;
	int		ret;

	ret = 0;
	c = (unsigned char) va_arg(*ap, int);
	ft_putwchar(c);
	return (ret);
}
