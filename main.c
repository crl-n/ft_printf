#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("ul" "%lhh|2147483647");
	printf("\n");
	printf("ul" "%lhh|2147483647");
	return (0);
}
