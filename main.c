/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 11:52:36 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/26 13:25:24 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	c;
	char	*str;
	long	x;

	c = 'a';
	str = "What did you do to my unicorn?! \n";
	x = 123456;
	ft_printf("ft_printf: %15.10ld\n", x);
	printf("printf: %15.10ld\n", x);
	return (0);
}
