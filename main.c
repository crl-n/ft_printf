#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	int	a;
	int	b;

	a = ft_printf("%0123p\n", 123);
	b = printf("%0123p\n", 123);
	printf("%d, %d", a, b);
	//ft_printf("%#b\n", 5);
	return (0);
}
