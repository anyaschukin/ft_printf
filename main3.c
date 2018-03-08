/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:00:58 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/08 19:26:47 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

#include <stdio.h> /* !!! */

typedef unsigned long long	ull;
typedef long long			ll;
typedef unsigned long		ul;

typedef enum	e_modifier
{
	NONE,
		HH,
		H,
		L,
		LL,
		J,
		T,
		Z
};

void	ft_print_result(int mr, int or, int line)
{
	static int c = 0;
	printf("\033[33m[%d]\033[0m MINE = %i - ORIG = %i", c, mr, or);
	if (mr == or)
		printf("\t\033[32m✔\033[0m");
	else
		printf("\t\033[31m✘ - (failed between lines %i and %i)\033[0m",
				line - 3, line);
	printf("\n---------------\n");
	c++;
}

int	main(void)
{
	int		or, mr;
	char	**test;

	test = malloc(sizeof(char*));
	or = 0;
	mr = 0;
	printf("\033[1;37m======== %%d ========\033[0m\n");

	mr = ft_printf("MINE>\t[%d]\n", 650);
	or = printf("ORIG>\t[%d]\n", 650);
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%d]\n", -650);
	or = printf("ORIG>\t[%d]\n", -650);
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+d]\n", 650);
	or = printf("ORIG>\t[%+d]\n", 650);
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+1d]\n", 650);
	or = printf("ORIG>\t[%+1d]\n", 650);
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+10d]\n", 650);
	or = printf("ORIG>\t[%+10d]\n", 650);
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+10d]\n", -650);
	or = printf("ORIG>\t[%+10d]\n", -650);
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%10d]\n", 650);
	or = printf("ORIG>\t[%10d]\n", 650);
//	ft_print_result(mr, or, __LINE__);

//	mr = ft_printf("MINE>\t[%-10d]\n", 650);
//	or = printf("ORIG>\t[%-10d]\n", 650);
//	ft_print_result(mr, or, __LINE__);

//	mr = ft_printf("MINE>\t[%-5d]\n", 650);
//	or = printf("ORIG>\t[%-5d]\n", 650);
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% d]\n", 650);
	or = printf("ORIG>\t[% d]\n", 650);
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% 5d]\n", 650);
	or = printf("ORIG>\t[% 5d]\n", 650);
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% d]\n", -650);
	or = printf("ORIG>\t[% d]\n", -650);
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% 5d]\n", -650);
	or = printf("ORIG>\t[% 5d]\n", -650);
//	ft_print_result(mr, or, __LINE__);

//	mr = ft_printf("MINE>\t[%05d]\n", -650);
//	or = printf("ORIG>\t[%05d]\n", -650);
//	ft_print_result(mr, or, __LINE__);

//	mr = ft_printf("MINE>\t[%+05d]\n", -650);
//	or = printf("ORIG>\t[%+05d]\n", -650);
//	ft_print_result(mr, or, __LINE__);

//	mr = ft_printf("MINE>\t[%-05d]\n", -650);
//	or = printf("ORIG>\t[%-05d]\n", -650);
//	ft_print_result(mr, or, __LINE__);

//	mr = ft_printf("MINE>\t[%+-05d]\n", -650);
//	or = printf("ORIG>\t[%+-05d]\n", -650);
//	ft_print_result(mr, or, __LINE__);

//	mr = ft_printf("MINE>\t[%+-09d]\n", -650);
//	or = printf("ORIG>\t[%+-09d]\n", -650);
//	ft_print_result(mr, or, __LINE__);

//	mr = ft_printf("MINE>\t[%+09d]\n", -650);
//	or = printf("ORIG>\t[%+09d]\n", -650);
//	ft_print_result(mr, or, __LINE__);

//	mr = ft_printf("MINE>\t[%+-1d]\n", -650);
//	or = printf("ORIG>\t[%+-1d]\n", -650);
//	ft_print_result(mr, or, __LINE__);

//	mr = ft_printf("MINE>\t[%+01d]\n", -650);
//	or = printf("ORIG>\t[%+01d]\n", -650);
//	ft_print_result(mr, or, __LINE__);

//	mr = ft_printf("MINE>\t[%'d]\n", 65000);
//	or = printf("ORIG>\t[%'d]\n", 65000);
//	ft_print_result(mr, or, __LINE__);

//	mr = ft_printf("MINE>\t[%'d]\n", 6500000);
//	or = printf("ORIG>\t[%'d]\n", 6500000);
//	ft_print_result(mr, or, __LINE__);

//	mr = ft_printf("MINE>\t[%+'d]\n", 65000);
//	or = printf("ORIG>\t[%+'d]\n", 65000);
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+4.15d]\n", 650);
	or = printf("ORIG>\t[%+4.15d]\n", 650);
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%15.5d]\n", 650);
	or = printf("ORIG>\t[%15.5d]\n", 650);
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+0.5d]\n", 650);
	or = printf("ORIG>\t[%+0.5d]\n", 650);
//	ft_print_result(mr, or, __LINE__);
	
//	mr = ft_printf("MINE>\t[%-0.5d]\n", 650);
//	or = printf("ORIG>\t[%-0.5d]\n", 650);
//	ft_print_result(mr, or, __LINE__);
	
	mr = ft_printf("MINE>\t[%0d]\n", 650);
	or = printf("ORIG>\t[%0d]\n", 650);
//	ft_print_result(mr, or, __LINE__);
	
	mr = ft_printf("MINE>\t[%.0d]\n", 650);
	or = printf("ORIG>\t[%.0d]\n", 650);
//	ft_print_result(mr, or, __LINE__);
	
	mr = ft_printf("MINE>\t[% .5d]\n", 650);
	or = printf("ORIG>\t[% .5d]\n", 650);
//	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.5d]\n", 650);
	or = printf("ORIG>\t[%.5d]\n", 650);

	mr = ft_printf("MINE>\t[%.14d]\n", 650);
	or = printf("ORIG>\t[%.14d]\n", 650);

	mr = ft_printf("MINE>\t[%4d]\n", 650);
	or = printf("ORIG>\t[%4d]\n", 650);
	
	mr = ft_printf("MINE>\t[%14d]\n", 650);
	mr = ft_printf("MINE>\t[%14d]\n", 650);
/*
*/

	return(0);
}
