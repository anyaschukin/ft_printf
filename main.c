/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:44:28 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/23 17:54:00 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*c;
	int		i;

	c = "What did you do to my unicorn?! \n";
	i = 123;
	ft_printf("ft_printf: %+d\n", i);
	printf("printf: %+d\n", i);
	return (0);
}
