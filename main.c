#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	printf("{%.*s}", 5, "42");
	ft_printf("{%.*s}", 5, "42");
	return (0);
}
