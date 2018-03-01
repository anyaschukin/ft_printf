/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_capx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 14:07:27 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/25 17:12:30 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// temorary function, everything within brackets is nonsense

void	flag_capx(va_list *ap, t_print *arg)
{
	wchar_t *str;

	str = va_arg(*ap, wchar_t *);
	ft_putwstr(str);
}
