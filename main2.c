/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:38:07 by aschukin          #+#    #+#             */
/*   Updated: 2018/02/26 17:03:18 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "limits.h"
#include "stdint.h"
#include "locale.h"

int	main()
{
	int		a;
	int		b;
	void	*ptr;
	int		ret;
	int		comp;
	wchar_t c;
	int		*ptrint;
	int		*ftrint;
	c = '\0';
	ret = 0;
	comp = 0 ;
	a = 0;
	b = 0;
	ptr = &c;
	ptrint = &a;
	ftrint = &b;

	setlocale(LC_ALL, "");
	//*ret += ft_printf("1	23456%n789", ftrint);
	//ft_putchar('\n');
	// comp += printf("123456%n789", ptrint);
	//ret += ft_printf("% hZ");
	//ft_putchar('\n');
	//comp += printf("% hZ");
	//ret += ft_printf("{%4.15s}", "42 is the answer");
	//ft_putchar('\n');
	//comp += printf("{%4.15s}", "42 is the answer");
	//ret += ft_printf("{%04.1S}", L"Jambon");
	//ft_putchar('\n');
	//comp += printf("{%04.1S}", L"Jambon");
	//ft_putchar('\n');
	//ret += ft_printf("%2.9p", 1234);
	//ft_putchar('\n');
	//comp +=printf("%2.9p", 1234);
	//ret += ft_printf("123%n\nptrint = %d\n", ptri	nt, *ptrint);
	//ft_putchar('\n');
	//ret += printf("123%n\nptrint = %d\n", ptrint, *ptrint);
	//ret += ft_printf("%u", 12);
	//ft_putchar('\n');
	//comp += printf("%u", 12);
	//printf("\nret = %d\ncomp = %d\n", ret, comp);
	//ft_putchar('\n');

	//FLAG_d
	//ret += ft_printf("1 @moulitest: %.d %.0d\n", 0, 0);
	//comp += printf("1 @moulitest: %.d %.	0d\n", 0, 0);
	//ret += ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);
	//comp += printf("@moulitest: %5.d %5.0d\n", 0, 0);
	//ft_printf("%d", 1);
	//ret += ft_printf("the %d\n", 1);
	//comp += printf("the %d\n", 1);
	//ret += ft_printf("%d is one\n", 1);
	//comp += printf("%d is one\n", 1);
	//ft_printf("%d", 1);
	//ft_printf("%d", 4242);
	//ft_printf("%d", 4242);
	//ft_printf("%d", 2147483647);
	//ret+= ft_printf("10 %d\n", 2147483648);
	//comp += printf("10 %d\n", 2147483648);
	//ft_printf("%d", 2147483648);
	//ret += ft_printf("%d\n", 2147483649);
	//comp += printf("%d\n", 2147483649);
	//ft_printf("% d", 42);
	//ret += ft_printf("% d\n", -42);
	//comp += printf("% d\n", -42);
	//ft_printf("%+d", 42);
	//ft_printf("%+d", 42);
	//ret += ft_printf("%+d\n", 0);
	//comp += printf("%+d\n", 0);
	//ret += ft_printf("%+lld\n", 4242424242424242424242);
	//comp += printf("%+lld\n", 4242424242424242424242);
	//ft_printf("% +d", 42);
	//ft_printf("% +d", 42);
	//ft_printf("%+ d", 42);
	//ft_printf("%+ d", 42);
	//ft_printf("%  +d", 42);
	//ft_printf("%  +d", 42);
	//ft_printf("%+  d", 42);
	//ft_printf("%+  d", 42);
	//ft_printf("%+  d", 42);
	//ft_printf("%+  d",42);
	//ret += ft_printf("% ++d\n", 42);
	//comp += printf("% ++d\n", 42);
	//ft_printf("% ++d", 42);
	//ft_printf("%++ d", 42);
	//ft_printf("30 %++ d", 42);
	//ft_printf("%0d", 42);
	//ft_printf("%00d", 42);
	//ft_printf("%5d", 42);
	//ft_printf("%05d", 42);
	//ret += ft_printf("%0+5d\n", 42);
	//comp += printf("%0+5d\n", 42);
	//ft_printf("%5d", 42);
	//ft_printf("%05d", 42);
	//ft_printf("%0+5d", 42);
	//ft_printf("%5d", 42);
	//ft_printf("40 %05d", 42);
	//ft_printf("%5d", 42);
	//ft_printf("%05d", 42);
	//ret += ft_printf("%hd\n", 32767);
	//comp += printf("%hd\n", 32767);
	//ret += ft_printf("%hd\n", -32768);
	//comp += printf("%hd\n", -32768);
	//ret += ft_printf("%hd\n", 32768);
	//comp += printf("%hd\n", 32768);
	//ret += ft_printf("%hd\n", -32769);
	//comp += printf("%hd\n", -32769);
	//ret += ft_printf("%hhd\n", 127);
	//comp += printf("%hhd\n", 127);
	//ret += ft_printf("%hhd\n", 128);
	//comp += printf("%hhd\n", 128);
	//ret += ft_printf("%hhd\n", 129);
	//comp += printf("%hhd\n", 129);
	//ret += ft_printf("%ld\n", 2147483647);
	//comp += printf("%ld\n", 2147483647);
	//ret += ft_printf("%ld\n", 2147483648);
	//comp += printf("%ld\n", 2147483648);
	//ret += ft_printf("%ld\n", 2147483649);
	//comp += printf("%ld\n", 2147483649);
	//ret += ft_printf("%lld\n", 9223372036854775807);
	//comp += printf("%lld\n", 9223372036854775807);
	//ret = ft_printf("%lld\n",9223372036854775808);
	//comp = printf("%lld\n", 9223372036854775808);
	//ret += ft_printf("%jd\n", 9223372036854775807);
	//comp += printf("%jd\n", 9223372036854775807);
	//ret += ft_printf("%jd\n", -9223372036854775808);
	//comp += printf("%jd\n", -9223372036854775808);
	//ret += ft_printf("%jd\n", 9223372036854775808);
	//comp += printf("%jd\n", 9223372036854775808);
	//ret += ft_printf("%zd\n", 4294967295);
	//comp += printf("%zd\n", 4294967295);
	//ret += ft_printf("%zd\n", 4294967296);
	//comp += printf("%zd\n", 4294967296);
	//ret+= ft_printf("%zd\n", 0);
	//comp += printf("%zd\n", 0);
	//ret +=ft_printf("%zd\n", 1);
	//comp += printf("%zd\n", 1);
	//ft_printf("%d", 1);
	//ft_printf("%d %d", 1, 2);
	//ft_printf("%d %d %d", 1, 2, 33);
	//ft_printf("%d %d %d %d", 1, 2, 33, 42);
	//ft_printf("%d %d %d %d gg!", 1, 2, 33, 42, 0);
	//ret += ft_printf("%4.15d\n", 42);
	//comp += printf("%4.15d\n", 42);
	//ft_printf("%.2d", 4242);
	//ft_printf("80 %.10d", 4242);
	//ft_printf("%10.5d", 4242);
	//ft_printf("%10.5d", 4242);
	//ft_printf("% 10.5d", 4242);
	//ft_printf("%+10.5d", 4242);
	//ft_printf("%+10.5d", 4242);
	//ft_printf("%03.2d", 0);
	//ft_printf("%03.2d", 1);
	//ft_printf("%03.2d", 1);
	//ft_printf("@moulitest: %.10d", 42);
	//ft_printf("%.d %.	0d", 42, 43);
	//ret += ft_printf("%.d %.0d\n", 0, 0);
	//comp += p	rintf("%.d %.0d\n", 0, 0);
	//ret += ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);
	//comp += printf("@moulitest: %5.d %5.0d\n", 0, 0);
	//comp += printf("%5u\n", 4294967295);
	//ret += ft_printf("%lu\n", -42);
	//comp += printf("%lu\n", -42);
	//
	//FLAG_O
	//
	//ret += ft_printf("%lx\n", 4294967297);
	//comp+= printf("%lx\n", 4294967297);
	//ret += ft_printf("%#.o %#.0o\n", 0, 0);
	//comp += printf("%#.o %#.0o\n", 0, 0);
	//ret += ft_printf("%-5.10o\n", 2500);
	//comp += printf("%-5.10o\n", 2500);
	//
	//FLAG_X
	//
	//ret += ft_printf("%#x\n", 0);
	//comp += printf("%#x\n", 0);
	//ret += ft_printf("%#.o %#.0o\n", 0, 0);
	//comp += printf("%#.o %#.0o\n", 0, 0);
	//ret += ft_printf("%-5.10X\n", 2500);
	//comp += printf("%-5.10X\n", 2500);
	//ret += ft_printf("%X\n", 2500);
	//comp += printf("%X\n", 2500);
	//ret += ft_printf("%#.x %#.0x\n", 0, 0);
	//comp += printf("%#.x %#.0x\n", 0, 0);
	
	//ret += ft_printf("%hD\n", 65535);
	//comp += printf("%hD\n", USHRT_MAX);
	//
	//ret += ft_printf("%hD\n", 65535);
	//comp += printf("%hD\n", USHRT_MAX);
	//printf("\nret = %d\ncomp = %d\n", ret, comp);
	//printf("\nftrint = %d\nptrint = %d\n", *ftrint, *ptrint);
	//printf("\nptrint = %d\n", *p	trint);
}
