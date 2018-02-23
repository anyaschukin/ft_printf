/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:56:29 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/22 15:08:43 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// this code is temporary nonsense

size_t	ft_check_errors(const char *format, t_print *arg)
{
	char *cpy;
	size_t i;

	cpy = (char *) format;
	if (cpy[i] == 1)
	{
		arg->precision = 1;
	}
	return (i);
}
