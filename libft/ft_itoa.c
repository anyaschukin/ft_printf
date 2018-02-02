/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:08:54 by aschukin          #+#    #+#             */
/*   Updated: 2017/11/27 19:32:17 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Itoa converts an integer into a string.
** int num is the integer we want to convert.
** char *str is where we'll store it.
** line 47: i is initialized as last character index of str
*/

#include "libft.h"

char	*ft_itoa(int num)
{
	char	*str;
	int		count;
	int		i;

	count = ft_count(num);
	if (!(str = (char *)malloc((count + 1) * sizeof(char))))
		return (NULL);
	i = count - 1;
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		str[i] = '0' + (num % 10);
		num = num / 10;
		i--;
	}
	str[count] = '\0';
	return (str);
}
