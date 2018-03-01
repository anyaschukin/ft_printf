/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:46:48 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/25 16:49:13 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_p(va_list *ap, t_print *arg)
{
	int		nb;
	int		len;
	char	*nbr;
	(void)arg;

	nb = va_arg(*ap, unsigned int);
	nbr = ft_utoa_base((unsigned int)nb, 16);
	//ft_putstr("0x");
	//ft_putstr(nbr	);
	len = (int)ft_strlen(nbr);
//	return (len);
}
