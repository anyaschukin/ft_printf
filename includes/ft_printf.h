/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:19:35 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/01 16:54:28 by aschukin         ###   ########.fr       */
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
	int	i;
	const char *format;
	// need padding?
	enum
	{
		none, // 1
		hh,   // 2
		h,    // 3
		j,    // 4
		l,    // 5
		ll,   // 6
		z,    // 7
	} length;

	size_t index;
	char buf[BUFF_SIZE];
}				t_print;

/*
** ft_printf Functions
*/

size_t		ft_printf(const char *format, ...);
size_t		ft_printf_conversion(va_list *ap, t_print *arg);
size_t	ft_init_struct(t_print *arg);
size_t	ft_check_flags(t_print *arg);
size_t	ft_check_width(t_print *arg);
size_t	ft_check_precision(t_print *arg);
size_t	ft_check_length(t_print *arg);
size_t	ft_check_errors(t_print *arg);
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

void	flag_c(va_list *ap, t_print *arg);
void	flag_d(va_list *ap, t_print *arg);
void	flag_i(va_list *ap, t_print *arg);
void	flag_o(va_list *ap, t_print *arg);
void	flag_p(va_list *ap, t_print *arg);
void	flag_s(va_list *ap, t_print *arg);
void	flag_u(va_list *ap, t_print *arg);
void	flag_x(va_list *ap, t_print *arg);

void	flag_capx(va_list *ap, t_print *arg);


/*
**
*/

void	ft_putwchar(wchar_t c);
void	ft_putwstr(wchar_t *wstr);



#endif
