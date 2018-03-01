/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:31:15 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/01 10:17:38 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count(size_t num)
{
	size_t count;

	count = 0;
	if (num <= 0)
	{
		count = count + 1;
	}
	while (num != 0)
	{
		count++;
		num = num / 10;
	}
	return (count);
}
