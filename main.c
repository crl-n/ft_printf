#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	ft_printf("%#.o, %#.0o", 0, 0);
	//ft_printf("%#.o", 42);
	return (0);
}
