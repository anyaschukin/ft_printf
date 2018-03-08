/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:58:38 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/08 14:33:19 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>


static intmax_t	length_d(va_list *ap, t_print *arg)
{
	if (arg->length == 2 && arg->format[arg->i] != 'D')
		return ((long long)((signed char)va_arg(*ap, int)));
	else if (arg->length == 3 && arg->format[arg->i] != 'D')
		return ((long long)((short int)va_arg(*ap, int)));
	else if (arg->length == 5 || arg->format[arg->i] == 'D')
		return ((long long)va_arg(*ap, long));
	else if (arg->length == 6)
		return ((long long)va_arg(*ap, long long));
	else if (arg->length == 4)
		return ((intmax_t)va_arg(*ap, intmax_t));
	else if (arg->length == 7)
		return ((long long)va_arg(*ap, size_t));
	else
		return (va_arg(*ap, int));
}

void	flag_d(va_list *ap, t_print *arg)
{
	long long	nb;
	size_t		len;
	int			ret; // add to i for final ret

	nb = length_d(ap, arg);
	len = ft_count(nb);

/*
** Revised/shortened
*/

	if (arg->precision_field == 1)
		while (arg->precision > len && arg->precision-- > 0)
			arg->iszero == 1? write (1, "0", 1) : write(1, " ", 1);
	arg->isplus == 1 ? len++ : 0;
	(arg->isplus == 1 && nb > 0) ? write(1, "+", 1) : 0;
	ft_putnbr(nb);
	if (arg->width_field == 1)
		while (arg->width > len && arg->width-- > 0)
			arg->iszero == 1? write(1, "0", 1) : write(1, " ", 1);


/*
** This version worked mostly
*/

	if (arg->isdash == 1)
	{
		(arg->isplus == 1 && nb > 0)? write(1, "+", 1) : 0;
		arg->isplus == 1 ? len++ : 0;
		ft_putnbr(nb);
	//	while ((arg->precision-- > len || arg->width-- > len) && arg->width-- > 0)
		while (arg->width-- >= len)
			write(1, " ", 1);
		return ;
	}
	else if (arg->precision_field == 1 && arg->width_field == 1 &&  arg->precision > arg->width)
	{
		(arg->isplus == 1 && nb > 0) ? write(1, "+", 1) : 0;
		while(arg->precision-- > len)
			write(1, "0",1);
		ft_putnbr(nb);
		return ;
	}
	else if (arg->precision_field == 1 && arg->width_field == 1 && arg->width > arg->precision)
	{
		while (arg->width-- > arg->precision)
			write (1, " ", 1);
			len--;
		len++;
		(arg->isplus == 1 && nb > 0)? write(1, "+", 1) : 0;
		while (arg->precision-- > len)
			write (1, "0", 1);
		ft_putnbr(nb);
		return ;
	}
	else if (arg->width_field == 1)
	{
		(arg->isplus == 1 && nb > 0) ? len++ : 0;
		while (arg->width-- > len)
			arg->iszero == 1 ? write(1, "0", 1) : write(1, " ", 1);
		(arg->isplus == 1 && nb > 0) ? write(1, "+", 1) : 0;
		ft_putnbr(nb);
		return ;
	}
	else if (arg->precision_field == 1)
	{
		arg->isspace == 1? write(1, " ", 1) : 0;
		while (arg->precision > len && arg->precision-- > 0)
			arg->iszero == 1? write(1, "0", 1) : write(1, " ", 1);
		(arg->isplus == 1 && nb > 0) ? write(1, "+", 1) : 0;
		ft_putnbr(nb);
		return ;
	}
	else
	(arg->isplus == 1 && nb > 0) ? write(1, "+", 1) : 0;
	arg->iszero == 1 ? write(1, "0", 1) : 0;
	ft_putnbr(nb);

}
