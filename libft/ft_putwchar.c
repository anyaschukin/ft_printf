/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:23:28 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/12 10:26:45 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t c)
{
	if (c <= 0x7F) // 1 byte
	{
		ft_putchar(c);
	}
	else if (c <= 0x7FF) // 2 bytes
	{
		ft_putchar((c >> 6) + 0xC0); // 0xC0 is the code point range, and >> 6 shifts bits 6 places over
		ft_putchar((c & 0x3F) + 0x80); // 0x3F is the code point range, and 0x80 is the masking value
	}
	else if (c <= 0x7FFF) // 3 bytes
	{
	ft_putchar((c >> 12) + 0xE0);
	ft_putchar(((c >> 6) & 0x3F) + 0x80);
	ft_putchar((c & 0x3F) + 0x80);
	}
	else // 4 bytes (since UTF-32 is the biggest?)
	{
	ft_putchar((c >> 18) + 0xF0);
	ft_putchar(((c >> 12) & 0x3F) + 0x80);
	ft_putchar(((c >> 6) & 0x3F) + 0x80);
	ft_putchar((c & 0x3F) + 0x80);
	} // if you putchar 4 hex values in a row, the computer will understand it as one wchar_t character
}
