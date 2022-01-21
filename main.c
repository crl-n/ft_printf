#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	char	str[] = "abc";

	ft_printf("%x\n", 5);
	ft_printf("%d\n", 5);
	ft_printf("%i\n", 5);
	ft_printf("%o\n", 5);
	ft_printf("%b\n", 5);
	ft_printf("%s\n", str);
	ft_printf("%p\n", str);
	printf("%p\n", str);
	return (0);
}
