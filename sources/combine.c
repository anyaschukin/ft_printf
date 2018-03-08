/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 09:53:20 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/08 19:51:27 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static char	*apply_precision(t_print *arg, t_out *out, int len)
{
	char		*add;
	intmax_t	tmp;

	tmp = arg->precision - len;
	if (arg->precision > len)
	{
		if(!(add = (char*)malloc(sizeof(char) * tmp + 1)))
			error_exit(ERROR, 1);
		ft_memset(add, '0', tmp);
		if(!(out->string = ft_strjoin_free(add, out->string, 3)))
			error_exit(ERROR, 1);
	}
	return (out->string);
}

static char	*apply_plus_space_hash(t_print *arg, t_out *out, int len)
{
	char		*add;
	intmax_t	tmp;

	if (arg->isplus == 1) // && nb > 0
		ft_strjoin_free("+", out->string, 2);
	else if (arg->isspace == 1)
		ft_strjoin_free(" ", out->string, 2);
//(arg->isspace == 1 && !(arg->isplus == 1)) ? strjoinfree(" ", out->string, 2) : 0;
	//	arg->isplus == 1 ? ft_memset() : 0;
	return (out->string);
}

static char	*apply_width(t_print *arg, t_out *out, int len)
{
	char		*add;
	intmax_t	tmp;

//	arg->isplus == 1 ? len-- : 0;
	tmp = arg->width - len;
	if (arg->width > len)
	{
		if(!(add = (char*)malloc(sizeof(char) * tmp)))
			error_exit(ERROR, 1);
//		(arg->isplus == 1 && nb > 0)? ft_memset(add, +, tmp) : 0;
		ft_memset(add, ' ', tmp);
		if(!(out->string = ft_strjoin_free(add, out->string, 3)))
			error_exit(ERROR, 1);
	}
	return (out->string);
}

//static void	apply_dash(t_print *arg)

char	*combine(t_print *arg, t_out *out, int len)
{
	arg->precision_field == 1 ? apply_precision(arg, out, len) : 0;
	(arg->isplus == 1 || arg->isspace == 1) ? apply_plus_space_hash(arg, out, len) : 0;
	arg->width_field == 1 ? apply_width(arg, out, ft_strlen(out->string)) : 0;
	return (out->string);
}







