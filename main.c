#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int	ft_printf(const char *format, ...);

int	main(void)
{

	ft_printf("abc %s ghi", "def");
	return (0);
}
