/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:29:59 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/07 18:10:12 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_ubase(uintmax_t num, int base)
{
	unsigned long long	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / base;
		i++;
	}
	return (i);
}

char	*ft_utoa_base(uintmax_t num, int base)
{
	char				*str;
	unsigned long long	count;
	unsigned long long	i;

	count = ft_count_ubase(num, base);
	if (!(str = ft_strnew(count)))
		return (NULL);
	i = count - 1;
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		if ((num % base) <= 9)
			str[i] = (num % base) + '0';
		else
			str[i] = (num % base) + 'A' - 10;
		num = num / base;
		i--;
	}
	free(str);
	return (str);
}

int	main()
{
	unsigned long long num;
	int base;

	num = 0xffffffffffffffff; // this is the max of an unsigned long long
	base = 8;
	printf("%s\n", ft_utoa_base(num, base));
	return (0);
}
