/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 11:52:36 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/01 18:10:50 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	c;
	char	*str;
	int		d;

	c = 'a';
	str = "What did you do to my unicorn?! \n";
	d = 650;
	ft_printf("ft_printf: %+10d\n", d);
//printf("printf: %+10d\n", d);
	return (0);
}
