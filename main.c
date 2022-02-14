#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	ft_printf("%12f", 1.234);
	printf("\n");
	printf("%12f", 1.234);
	return (0);
}
