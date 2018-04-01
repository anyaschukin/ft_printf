#include "ft_printf.h"

int main()
{
	ft_printf("%U", 42);
	ft_printf("%U", ULONG_MAX / 2);
	ft_printf("%U", ULONG_MAX);
	return (0);
}

