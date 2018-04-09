/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:41:53 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/08 18:46:43 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	ft_print_struct(t_print *arg)
{
	printf("\n");
	printf("Dash: %u\n", DASH);
	printf("Plus: %u\n", PLUS);
	printf("Zero: %u\n", ZERO);
	printf("Space: %u\n", SPACE);
	printf("Hash: %u\n", HASH);
	printf("Positive: %u\n", arg->ispositive);
	printf("Negative: %u\n", arg->isnegative);
	printf("Width Field: %u\n", WFIELD);
	printf("Width: %u\n", WIDTH);
	printf("Precision Field: %d\n", PFIELD);
	printf("Precision: %d\n", PREC);
	printf("Length: %d\n", arg->length);
	printf("i: %d\n", arg->i);
	printf("Origial format: %s\n", arg->format);
}
