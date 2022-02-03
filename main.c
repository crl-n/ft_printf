#include "ft_printf.h"
#include <stdio.h>
#include <string.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	//char	str[] = "abc";

	ft_printf("@moulitest: %.d %.0d", 0, 0);
	ft_printf("% 10.5d", 4242);
	ft_printf("%lld", -9223372036854775808);
	ft_printf("%lld", -9223372036854775807);
	ft_printf("%lu", 4294967296);
	ft_printf("%lu", 4294967295);
	ft_printf("%lu", 4294967297);
	puts("\n");

	/*
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

	ft_printf("%p\n", 0);
	ft_printf("%#x\n", 1);
	ft_printf("%#x\n", 0);
	printf("%p\n", 0);
	printf("%#x\n", 1);
	printf("%#x\n", 0);
	puts("\n");

	ft_printf("%#15x\n", 5);
	printf("%#15x\n", 5);
	puts("\n");

	ft_printf("% 15i\n", 5);
	printf("% 15i\n", 5);
	puts("\n");

	ft_printf("%+ 15i\n", 5);
	printf("%+ 15i\n", 5);
	puts("\n");

	ft_printf("%+ 15i\n", -5);
	printf("%+ 15i\n", -5);
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
	*/

	return (0);
}
