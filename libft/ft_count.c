/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:31:15 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/06 15:56:29 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count(long long num)
{
	size_t count;

	count = 0;
	if (num <= 0)
	{
		num = -num;
		count++;
	}
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}
