/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 09:53:20 by aschukin          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

static char	*apply_precision(t_print *arg, t_out *out, intmax_t len)
{
	char		*add;
	intmax_t	tmp;

	tmp = arg->precision - len;
	if (arg->precision > len)
	{
		if(!(add = (char*)malloc(sizeof(char) * tmp + 1)))
			error_exit(ERROR, 1);
		add[tmp] = '\0';
		ft_memset(add, '0', tmp);
		if(!(out->string = ft_strjoin_free(add, out->string, 3)))
			error_exit(ERROR, 1);
	}
	return (out->string);
}

static char	*apply_plus_space_hash(t_print *arg, t_out *out, intmax_t len)
{
	char		*temp;
	intmax_t	tmp;

	if (arg->isplus == 1 && arg->ispositive == 1)
		out->string = ft_strjoin_free("+", out->string, 2);
	else if (arg->isspace == 1 && !(arg->isnegative == 1))
		out->string = ft_strjoin_free(" ", out->string, 2);
	return (out->string);
}

static char	*apply_width(t_print *arg, t_out *out, intmax_t len)
{
	char		*add;
	intmax_t	tmp;

	tmp = arg->width - len;
	if (arg->width > len)
	{
		if(!(add = (char*)malloc(sizeof(char) * tmp + 1)))
			error_exit(ERROR, 1);
		add[tmp] = '\0';
		ft_memset(add, ' ', tmp);
		if(!(out->string = ft_strjoin_free(add, out->string, 3)))
			error_exit(ERROR, 1);
	}
	return (out->string);
}

static char	*apply_zero_dash(t_print *arg, t_out *out)
{
	char		*add;
	intmax_t	len;
	intmax_t	vlen;
	intmax_t	move;

	len = ft_strlen(out->string);
	vlen = ft_strlen(out->value);
	if (arg->iszero == 1 && arg->width > vlen)
	{
		arg->isnegative ? arg->width++ : 0;
		ft_memset(out->string, '0', arg->width - vlen);
		if (arg->isplus && arg->ispositive == 1)
			*out->string = '+';
		else if (arg->isnegative == 1)
			*out->string = '-';
	}
	else if (arg->isdash == 1)
	{
		move = vlen - len;
		ft_strrotate(out->string, len, move);
	}
	return (out->string);
}

char	*combine(t_print *arg, t_out *out, intmax_t len)
{
	arg->precision_field == 1 ? apply_precision(arg, out, len) : 0;
	(arg->isplus == 1 || arg->isspace == 1) ? apply_plus_space_hash(arg, out, len) : 0;
	arg->width_field == 1 ? apply_width(arg, out, ft_strlen(out->string)) : 0;
	(arg->isdash == 1 || arg->iszero == 1) ? apply_zero_dash(arg, out) : 0;
	return (out->string);
}

// NEED TO CLEAN UP LEN VARIABLES





