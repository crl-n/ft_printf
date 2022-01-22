#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	char	str[] = "abc";

	ft_printf("%s\n", str);
	printf("%s\n", str);
	puts("\n");

	ft_printf("%p\n", str);
	printf("%p\n", str);
	puts("\n");

	ft_printf("%x\n", 156);
	printf("%x\n", 156);
	puts("\n");

	ft_printf("%X\n", 156);
	printf("%X\n", 156);
	puts("\n");

	ft_printf("%u\n", -5);
	printf("%u\n", -5);
	puts("\n");

	ft_printf("%o\n", -5);
	printf("%o\n", -5);
	puts("\n");

	ft_printf("% 15i\n", 5);
	printf("% 15i\n", 5);
	puts("\n");

	ft_printf("% 015i\n", 5);
	printf("% 015i\n", 5);
	puts("\n");

	ft_printf("%015i\n", 5);
	printf("%015i\n", 5);
	puts("\n");

	ft_printf("%#o\n", 5);
	printf("%#o\n", 5);
	puts("\n");

	return (0);
}
