/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:40:39 by aschukin          #+#    #+#             */
/*   Updated: 2018/01/15 16:47:50 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The strdup() function allocates sufficient memory for a copy
** of the string s1, does the copy, and returns a pointer to it.
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		n;
	char	*s2;

	i = 0;
	n = ft_strlen(s1);
	if (!(s2 = malloc((n + 1) * sizeof(char))))
		return (NULL);
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
