#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	ft_printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);
	return (0);
}
