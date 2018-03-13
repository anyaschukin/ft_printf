/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:00:58 by aschukin          #+#    #+#             */
/*   Updated: 2018/03/13 19:47:24 by aschukin         ###   ########.fr       */
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

#define RED "\E[31m"
#define GRE "\E[32m"
#define YEL "\E[33m"
#define WHI "\E[37m"
#define EOC "\E[0m"

int	main(void)
{
	int		or, mr;
	char	**test;

	test = malloc(sizeof(char*));
	or = 0;
	mr = 0;
	printf("\033[1;37m======== %%d ========\033[0m\n");

/*
** d TESTS
*/
/*
	mr = ft_printf("MINE>\t[%d]\n", 650);
	or = printf("ORIG>\t[%d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%d]\n", -650);
	or = printf("ORIG>\t[%d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+d]\n", 650);
	or = printf("ORIG>\t[%+d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+1d]\n", 650);
	or = printf("ORIG>\t[%+1d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE5>\t[%+10d]\n", 123);
	or = printf("ORIG5>\t[%+10d]\n", 123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+10d]\n", -650);
	or = printf("ORIG>\t[%+10d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%10d]\n", 650);
	or = printf("ORIG>\t[%10d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-10d]\n", 650);
	or = printf("ORIG>\t[%-10d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-5d]\n", 650);
	or = printf("ORIG>\t[%-5d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE10>\t[% d]\n", 650);
	or = printf("ORIG10>\t[% d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% 5d]\n", 650);
	or = printf("ORIG>\t[% 5d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% d]\n", -650);
	or = printf("ORIG>\t[% d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[% 5d]\n", -650);
	or = printf("ORIG>\t[% 5d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%05d]\n", -650);
	or = printf("ORIG>\t[%05d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE15>\t[%s %+08d %s]\n", RED, -650, EOC);
	or = printf("ORIG15>\t[%s %+08d %s]\n", RED, -650, EOC);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-05d]\n", -650);
	or = printf("ORIG>\t[%-05d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+-05d]\n", -650);
	or = printf("ORIG>\t[%+-05d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+-09d]\n", -650);
	or = printf("ORIG>\t[%+-09d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+09d]\n", 650);
	or = printf("ORIG>\t[%+09d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE20>\t[%+-1d]\n", -650);
	or = printf("ORIG20>\t[%+-1d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+01d]\n", -650);
	or = printf("ORIG>\t[%+01d]\n", -650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%'d]\n", 65000);
	or = printf("ORIG>\t[%'d]\n", 65000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%'d]\n", 6500000);
	or = printf("ORIG>\t[%'d]\n", 6500000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+'d]\n", 65000);
	or = printf("ORIG>\t[%+'d]\n", 65000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE25>\t[%+4.15d]\n", 650);
	or = printf("ORIG25>\t[%+4.15d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+15.5d]\n", 42);
	or = printf("ORIG>\t[%+15.5d]\n", 42);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+0.5d]\n", 650);
	or = printf("ORIG>\t[%+0.5d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-0.5d]\n", 650);
	or = printf("ORIG>\t[%-0.5d]\n", 650);
	ft_print_result(mr, or, __LINE__);
	
	mr = ft_printf("MINE>\t[%0d]\n", 650);
	or = printf("ORIG>\t[%0d]\n", 650);
	ft_print_result(mr, or, __LINE__);
	
	mr = ft_printf("MINE30>\t[%.0d]\n", 650);
	or = printf("ORIG30>\t[%.0d]\n", 650);
	ft_print_result(mr, or, __LINE__);
	
	mr = ft_printf("MINE>\t[% .5d]\n", 650);
	or = printf("ORIG>\t[% .5d]\n", 650);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.5d]\n", 650);
	or = printf("ORIG>\t[%.5d]\n", 650);

	mr = ft_printf("MINE>\t[%.14d]\n", 650);
	or = printf("ORIG>\t[%.14d]\n", 650);

	mr = ft_printf("MINE>\t[%4d]\n", 650);
	or = printf("ORIG>\t[%4d]\n", 650);
	
	mr = ft_printf("MINE>\t[%14d]\n", 650);
	mr = ft_printf("MINE>\t[%14d]\n", 650);

*/

/*
**  u TESTS
*/ 
/*
	mr = ft_printf("MINE>\t[%u]\n", 123);
	or = printf("ORIG>\t[%u]\n", 123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-u]\n", 123);
	or = printf("ORIG>\t[%-u]\n", 123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+u]\n", 123);
	or = printf("ORIG>\t[%+u]\n", 123);
	ft_print_result(mr, or, __LINE__);mr = ft_printf("MINE>\t[%0u]\n", 123);
	
	mr = ft_printf("MINE>\t[%+0u]\n", 123);
	or = printf("ORIG>\t[%0u]\n", 123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE5>\t[%5u]\n", -123);
	or = printf("ORIG5>\t[%5u]\n", -123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%0.5u]\n", 123);
	or = printf("ORIG>\t[%0.5u]\n", 123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%5.10u]\n", 123456789);
	or = printf("ORIG>\t[%5.10u]\n", 123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-0.5u]\n", -123456789);
	or = printf("ORIG>\t[%-0.5u]\n", -123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+05.10u]\n", 123);
	or = printf("ORIG>\t[%+05.10u]\n", 123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE10>\t[%h5u]\n", 123456789123456);
	or = printf("ORIG10>\t[%h5u]\n", 123456789123456);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.5u]\n", 123);
	or = printf("ORIG>\t[%.5u]\n", 123);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.0u]\n", 123);
	or = printf("ORIG>\t[%.0u]\n", 123);
	ft_print_result(mr, or, __LINE__);
*/

/*
**  o TESTS
*/ 

/*
	mr = ft_printf("MINE>\t[%o]\n", 1000);
	or = printf("ORIG>\t[%o]\n", 1000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%o]\n", -123456789);
	or = printf("ORIG>\t[%o]\n", -123456789);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#o]\n", 0);
	or = printf("ORIG>\t[%#o]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#o]\n", 1000);
	or = printf("ORIG>\t[%#o]\n", 1000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE5>\t[%#+o]\n", -896);
	or = printf("ORIG5>\t[%#+o]\n", -896);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%hho]\n", (unsigned char)-12);
	or = printf("ORIG>\t[%hho]\n", (unsigned char)-12);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%ho]\n", (unsigned short)1475);
	or = printf("ORIG>\t[%ho]\n", (unsigned short)1475);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%lo]\n", (unsigned long)258);
	or = printf("ORIG>\t[%lo]\n", (unsigned long)258);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%llo]\n", (unsigned long long)-127);
	or = printf("ORIG>\t[%llo]\n", (unsigned long long)-127);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE10>\t[%.2o]\n", 0);
	or = printf("ORIG10>\t[%.2o]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.2o]\n", 120);
	or = printf("ORIG>\t[%.2o]\n", 120);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.0o]\n", 12012);
	or = printf("ORIG>\t[%.0o]\n", 12012);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%1o]\n", 0);
	or = printf("ORIG>\t[%1o]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%01o]\n", 0);
	or = printf("ORIG>\t[%01o]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE15>\t[%03o]\n", 0);
	or = printf("ORIG15>\t[%03o]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%6o]\n", 01423);
	or = printf("ORIG>\t[%6o]\n", 01423);
	ft_print_result(mr, or, __LINE__);
	
	mr = ft_printf("MINE>\t[%#-2o]\n", 874);
	or = printf("ORIG>\t[%#-2o]\n", 874);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%-8.30o]\n", 120);
	or = printf("ORIG>\t[%-8.30o]\n", 120);
	ft_print_result(mr, or, __LINE__);

*/
/*
** x TESTS
*/
/*
	mr = ft_printf("MINE>\t[%x]\n", 0);
	or = printf("ORIG>\t[%x]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%x]\n", 0xa0ffff);
	or = printf("ORIG>\t[%x]\n", 0xa0ffff);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%x]\n", -12345678);
	or = printf("ORIG>\t[%x]\n", -12345678);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#X]\n", 0);
	or = printf("ORIG>\t[%#X]\n", 0);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE5>\t[%#x]\n", 0x78aa);
	or = printf("ORIG5>\t[%#x]\n", 0x78aa);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%#x]\n", 0xff7744);
	or = printf("ORIG>\t[%#x]\n", 0xff7744);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.x]\n", 12);
	or = printf("ORIG>\t[%.x]\n", 12);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.0X]\n", 0xaabbcc);
	or = printf("ORIG>\t[%.0X]\n", 0xaabbcc);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%.2X]\n", 0x11aabbcc);
	or = printf("ORIG>\t[%.2X]\n", 0x11aabbcc);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE10>\t[% x]\n", 0x1234abcd);
	or = printf("ORIG10>\t[% x]\n", 0x1234abcd);
	ft_print_result(mr, or, __LINE__);
*/
	mr = ft_printf("MINE>\t[%.10x]\n", 0x1234abcd);
	or = printf("ORIG>\t[%.10x]\n", 0x1234abcd);
	ft_print_result(mr, or, __LINE__);
/*
	mr = ft_printf("MINE>\t[% x]\n", -650);
	or = printf("ORIG>\t[% x]\n", -650);
	ft_print_result(mr, or, __LINE__);
*/
	mr = ft_printf("MINE>\t[% .5x]\n", 0x78);
	or = printf("ORIG>\t[% .5x]\n", 0x78);
	ft_print_result(mr, or, __LINE__);
/*
	mr = ft_printf("MINE>\t[%05x]\n", 0xa43);
	or = printf("ORIG>\t[%05x]\n", 0xa43);
	ft_print_result(mr, or, __LINE__);
*/
	mr = ft_printf("MINE15>\t[%s %8X %s]\n", RED, 0xa3, EOC);
	or = printf("ORIG15>\t[%s %8X %s]\n", RED, 0xa3, EOC);
	ft_print_result(mr, or, __LINE__);
/*
	mr = ft_printf("MINE>\t[%-5x]\n", 0xdd);
	or = printf("ORIG>\t[%-5x]\n", 0xdd);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%011X]\n", 0xdd66);
	or = printf("ORIG>\t[%011X]\n", 0xdd66);
	ft_print_result(mr, or, __LINE__);
*/
	mr = ft_printf("MINE>\t[%01hhx]\n", 0xaabb);
	or = printf("ORIG>\t[%01hhx]\n", 0xaabb);
	ft_print_result(mr, or, __LINE__);
/*
	mr = ft_printf("MINE>\t[%#7.5X%0006.2x and %lX]\n", 0xab, 0x876, 0xff11ff11ff1);
	or = printf("ORIG>\t[%#7.5X%0006.2x and %lX]\n", 0xab, 0x876, 0xff11ff11ff1);
	ft_print_result(mr, or, __LINE__);
*/
	mr = ft_printf("MINE20>\t[%0##0.4X %#4.2x oh boy]\n", 0x037a, 0x9e);
	or = printf("ORIG20>\t[%0##0.4X %#4.2x oh boy]\n", 0x037a, 0x9e);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[yikes %#.4X can you handle %#012x]\n", 0xaef, 0xe);
	or = printf("ORIG>\t[yikes %#.4X can you handle %#012x]\n", 0xaef, 0xe);
	ft_print_result(mr, or, __LINE__);
/*
	mr = ft_printf("MINE>\t[%hhx]\n", (unsigned char)-10);
	or = printf("ORIG>\t[%hhx]\n", (unsigned char)-10);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%hX]\n", (unsigned short)40);
	or = printf("ORIG>\t[%hX]\n", (unsigned short)40);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%lx]\n", (unsigned long)-178965423);
	or = printf("ORIG>\t[%lx]\n", (unsigned long)-178965423);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE25>\t[%zx]\n", 65423000000);
	or = printf("ORIG25>\t[%zx]\n", 65423000000);
	ft_print_result(mr, or, __LINE__);

	mr = ft_printf("MINE>\t[%+15.5x]\n", 42);
	or = printf("ORIG>\t[%+15.5x]\n", 42);
	ft_print_result(mr, or, __LINE__);
*/
	mr = ft_printf("MINE>\t[%-0.5x]\n", 650);
	or = printf("ORIG>\t[%-0.5x]\n", 650);
	ft_print_result(mr, or, __LINE__);
/*	
	mr = ft_printf("MINE>\t[%0x]\n", 650);
	or = printf("ORIG>\t[%0x]\n", 650);
	ft_print_result(mr, or, __LINE__);
	
	mr = ft_printf("MINE30>\t[%.0x]\n", 650);
	or = printf("ORIG30>\t[%.0x]\n", 650);
	ft_print_result(mr, or, __LINE__);
*/

	return(0);
}
