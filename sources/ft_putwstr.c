/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 16:32:37 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/25 17:16:02 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// YOU HAVE THE SAME FUNCTION (WRITTEN DIFFERENTLY) IN YOUR LIBFT!!

void	ft_putwstr(wchar_t *wstr)
{
	while (*wstr)
		ft_putwchar(*wstr++);
}
