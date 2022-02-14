#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	printf("%.f %.f %.f", 0.5, 1.5, 2.5);
	return (0);
}
