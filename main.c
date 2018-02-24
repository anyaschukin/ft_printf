/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 11:52:36 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/24 16:47:27 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*c;
	int		x;

	c = "What did you do to my unicorn?! \n";
	x = 123456;
	ft_printf("ft_printf: %+2.11d\n", x);
	//printf("printf: %2.11hd\n", x);
	return (0);
}
