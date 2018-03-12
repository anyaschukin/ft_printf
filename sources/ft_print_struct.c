/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:41:53 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/10 21:06:32 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	ft_print_struct(t_print *arg)
{
	printf("\n");
	printf("Dash: %u\n", arg->isdash);
	printf("Plus: %u\n", arg->isplus);
	printf("Zero: %u\n", arg->iszero);
	printf("Space: %u\n", arg->isspace);
	printf("Hash: %u\n", arg->ishash);
	printf("Positive: %u\n", arg->ispositive);
	printf("Negative: %u\n", arg->isnegative);
	printf("Width Field: %u\n", arg->width_field);
	printf("Width: %u\n", arg->width);
	printf("Precision Field: %d\n", arg->precision_field);
	printf("Precision: %d\n", arg->precision);
	printf("Length: %d\n", arg->length);
	printf("i: %d\n", arg->i);
	printf("Origial format: %s\n", arg->format);
}
