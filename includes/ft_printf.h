/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:19:35 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/23 16:25:13 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>

# define BUFF_SIZE 1

typedef struct s_print
{
	unsigned int isdash : 1;
	unsigned int isplus : 1;
	unsigned int iszero : 1;
	unsigned int isspace : 1;
	unsigned int ishash : 1;

	unsigned int width_field;
	unsigned int width;

	unsigned int precision_field;
	unsigned int precision;

	char converter;

	enum
	{
		none,
		hh,
		h,
		j,
		l,
		ll,
		z,
	} length;

	size_t index;
	char buf[BUFF_SIZE];
}				t_print;

/*
** ft_printf Functions
*/
size_t		ft_printf(const char *format, ...);
size_t		ft_printf_conversion(char *format, va_list *ap, t_print *arg, size_t i);
size_t	ft_init_struct(t_print *arg);
size_t	ft_check_flags(char *format, t_print *arg, size_t i);
size_t	ft_check_width(char *format, t_print *arg, size_t i);
size_t	ft_check_precision(char *format, t_print *arg);
size_t	ft_check_length(const char *format, t_print *arg);
size_t	ft_check_errors(const char *format, t_print *arg);
intmax_t	ft_length_conversion(intmax_t nb, t_print *arg);
uintmax_t	ft_ulength_conversion(uintmax_t nb, t_print *arg);

//int	ft_old_printf_conversion(char *format, va_list *ap, t_print arg);
void	ft_print_struct(t_print *arg);

/*
** Conversion Character Functions
*/


/*
typedef struct s_funct
{
		int (*ptrfunct)(char *, va_list *, t_print *);
		char flag;
}	t_funct;
*/

int	flag_c(char *format, va_list *ap, t_print *arg);
int	flag_d(char *format, va_list *ap, t_print *arg, size_t i);
int	flag_i(char *format, va_list *ap, t_print *arg);
int	flag_o(char *format, va_list *ap, t_print *arg);
int	flag_p(char *format, va_list *ap, t_print *arg);
int	flag_s(char *format, va_list *ap, t_print *arg);
int	flag_u(char *format, va_list *ap, t_print *arg);
int	flag_x(char *format, va_list *ap, t_print *arg);

int	flag_capx(char *format, va_list *ap, t_print *arg);


#endif
