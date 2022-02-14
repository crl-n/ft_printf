#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	ft_printf("%0*i", -7, -54);
	printf("\n");
	printf("%0*i", -7, -54);
	return (0);
}
