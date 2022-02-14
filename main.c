#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	printf("%08.5u", 34);
	printf("\n");
	ft_printf("%08.5u", 34);
	return (0);
}
