/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_address.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:12:33 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/21 18:30:09 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_flag_x(va_list *ap, t_print *arg)
{
	int		nb;
	int		len;
	char	*nbr;
	(void)arg;

	nb = va_arg(*ap, unsigned int);
	nbr = ft_utoa_base((unsigned int)nb, 16);
	//ft_putstr("0x");
	ft_putstr(nbr);
	len = ft_strlen(nbr);
	return (len);
}
