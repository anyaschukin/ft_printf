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
	if (arg->converter == 'S' || arg->converter == 's')
	{
		while ((out->string[arg->precision] & 0xC0) == 0x80) // shifting back to the code point range, and putting a '\0' at the code point range, so that half the character doesn't get printed
			arg->precision--;
		arg->precision > arg->width ? out->string[arg->precision] = '\0' : 0;
		arg->precision < len ? ft_strclr(out->string + arg->precision) : 0;
	}
	if (arg->precision >= len && arg->converter != 's')
	{
		arg->isnegative ? tmp += 1 : 0;
		if (!(add = (char*)malloc(sizeof(char) * tmp + 1)))
			error_exit(ERROR, 1);
		add[tmp] = '\0';
		ft_memset(add, '0', tmp);
		if (!(out->string = ft_strjoin_free(add, out->string, 3)))
			error_exit(ERROR, 1);
		(arg->precision > arg->width && arg->isdash) ? arg->isdash = 0 : 0;
	}
	return (out->string);
}

static char	*apply_plus_space_hash(t_print *arg, t_out *out)
{
	//char		*temp;
	//intmax_t	tmp;

	if (arg->ishash == 1)
	{
		if (arg->converter == 'o')
		{
			if (!(out->string = ft_strjoin_free("0", out->string, 2)))
				error_exit(ERROR, 1);
		}
		if (arg->converter == 'x' || arg->converter == 'X')
		{
			if (!(out->string = ft_strjoin_free("0x", out->string, 2)))
				error_exit(ERROR, 1);
		}
	}
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

	(arg->converter == 'c' && ft_strcmp("\0", out->value) == 0) ? len = 1 : 0;
	tmp = arg->width - len;
	if (arg->converter == 'p' && arg->width_field == 1 && arg->iszero == 1) 
		tmp -= 2;
	if (arg->width > len)
	{
		add = ft_strnew(tmp);
		add[tmp] = '\0';
		ft_memset(add, ' ', tmp);
		if (arg->precision > 1 && arg->isdash && (arg->converter != 'c'))
 		{
			if (!(out->string = ft_strjoin_free(out->string, add, 3)))
				error_exit(ERROR, 1);
			arg->isdash = 0;
		}
		else
		{
			if (!(out->string = ft_strjoin_free(add, out->string, 3)))
				error_exit(ERROR, 1);
		}
	}
	return (out->string);
}

static char	*apply_zero_dash(t_print *arg, t_out *out)
{
	intmax_t	len;
	intmax_t	vlen;
	intmax_t	move;

	len = ft_strlen(out->string);
	if (arg->converter == 'C' || arg->converter == 'S')
		vlen = ft_strwlen(out->value);
	else
		vlen = ft_strlen(out->value);
	if (arg->iszero == 1 && arg->width > vlen)
	{
		arg->isnegative ? arg->width++ : 0;
		arg->converter == 'p' ? vlen += 2 : 0;
		ft_memset(out->string, '0', arg->width - vlen);
		if (arg->isplus && arg->ispositive == 1)
			*out->string = '+';
		else if (arg->isnegative == 1)
			*out->string = '-';
	}
	else if (arg->isdash == 1)
	{
		(arg->converter != 'p' && (ft_strchr(out->string, 'X') || ft_strchr(out->string, 'x'))) ? vlen += 2 : 0;
		(arg->converter == 'o' && arg->ishash == 1) ? vlen += 1 : 0;
		move = vlen - len;
		ft_strrotate(out->string, len, move);
	}
	return (out->string);
}

char	*combine(t_print *arg, t_out *out, intmax_t len)
{
	arg->precision_field == 1 ? apply_precision(arg, out, len) : 0;
	apply_plus_space_hash(arg, out);
	arg->width_field == 1 ? apply_width(arg, out, ft_strlen(out->string)) : 0;
	(arg->isdash == 1 || arg->iszero == 1) ? apply_zero_dash(arg, out) : 0;
	return (out->string);
}

// NEED TO CLEAN UP LEN VARIABLES





