/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 17:48:07 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/16 17:46:16 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

t_funct f_tab[]=
{
	{&flag_c, 'c'},
	{&flag_d, 'd'},
	{&flag_o, 'o'},
	{&flag_p, 'p'},
	{&flag_s, 's'},
	{&flag_u, 'u'},
	{&flag_x, 'x'},
	{&flag_cap_C, 'C'},
	{&flag_cap_D, 'D'},
	{&flag_cap_O, 'O'},
	{&flag_cap_S, 'S'},
	{&flag_cap_U, 'U'},
	{&flag_cap_X, 'X'},
	{NULL, -1}
};


int	ft_printf_conversion(char *format, va_list *ap, t_print arg)
{
	int i;
	int ret;

	i = 0;
	while (f_tab[i] != -1)
	{
		if (f_tab[i].flag == *format)
			ret = f_tab[i]; // launch the pointer function!
		i++;
	}
	return (ret);
}

/*

int	ft_printf_conversion(char *format, va_list *ap, t_print arg)
{
	int ret;
	
	*format == 'c' ? flag_c(format, ap, arg) : 0;
	*format == 'd' ? flag_d(format, ap, arg) : 0;
	*format == 'i' ? flag_i(format, ap, arg) : 0;
	*format == 'o' ? flag_o(format, ap, arg) : 0;
	*format == 'p' ? flag_p(format, ap, arg) : 0;
	*format == 's' ? flag_s(format, ap, arg) : 0;
	*format == 'u' ? flag_u(format, ap, arg) : 0;
	*format == 'x' ? flag_x(format, ap, arg) : 0;
	*format == 'C' ? flag_cap_C(format, ap, arg) : 0;
	*format == 'D' ? flag_cap_D(format, ap, arg) : 0;
	*format == 'O' ? flag_cap_O(format, ap, arg) : 0;
	*format == 'S' ? flag_cap_S(format, ap, arg) : 0;
	*format == 'U' ? flag_cap_U(format, ap, arg) : 0;
	*format == 'S' ? flag_cap_X(format, ap, arg) : 0;
	ret++;
	return (ret);
}

*/
