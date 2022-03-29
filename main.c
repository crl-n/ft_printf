#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

#define SRCLINE strstr(src_code[__LINE__], "TEST")

#define TEST(fmt, ...) printf("%-30sOrig: {", SRCLINE);\
					   printf("}{%d}\n", printf(fmt, ##__VA_ARGS__));\
					   printf("%-30sYour: {", "");\
					   fflush(stdout);\
					   printf("}{%d}\n", ft_printf(fmt, ##__VA_ARGS__))

#define LABELS printf("\033[1m%-30s%13s\n\033[0m", "Format", "Output / Return")

static const char	filename[] = "main.c";

int	main(void)
{
	FILE	*file = fopen(filename, "r");
	char	*src_code[256];
	char	*line = NULL;
	size_t	linecap = 0;
	int		i = 1;

	if (!file)
	{
		perror("ERROR: Couldn't open file.");
		exit(1);
	}

	while (getline(&line, &linecap, file) > 0)
	{
		char	*semicolon;
		src_code[i] = line;

		semicolon = strrchr(src_code[i], ';');
		if (semicolon)
			*semicolon = '\0';
		i++;
		if (i == 256)
		{
			perror("Error: Source code array ran out of space.");
			fclose(file);
			exit(1);
		}
		line = NULL;
	}

	fclose(file);


	LABELS;
	TEST("%s", "Hello");
	TEST("%010f", 0.0 / 0.0);


	//int	ret;
	//ret = ft_printf("%.0f\n", 99.5);
	//printf("ret %d\n", ret);
	//ret = printf("%.0f\n", 99.5);
	//printf("ret %d\n", ret);
	//ret = ft_printf("%.1f\n", 1.35);
	//printf("ret %d\n", ret);
	//ret = printf("%.1f\n", 1.35);
	//printf("ret %d\n", ret);
	//ret = ft_printf("%.2f\n", 1.355);
	//printf("ret %d\n", ret);
	//ret = printf("%.2f\n", 1.355);
	//printf("ret %d\n", ret);
	//ret = ft_printf("%.2f\n", 1.345);
	//printf("ret %d\n", ret);
	//ret = printf("%.2f\n", 1.345);
	//printf("ret %d\n", ret);
	//ret = ft_printf("%.2f\n", 1.365);
	//printf("ret %d\n", ret);
	//ret = printf("%.2f\n", 1.365);
	//printf("ret %d\n", ret);
	//ret = ft_printf("%.0f\n", 1.5);
	//printf("ret %d\n", ret);
	//ret = printf("%.0f\n", 1.5);
	//printf("ret %d\n", ret);
	//ret = ft_printf("%f\n", 0.0 / 0.0);
	//printf("ret %d\n", ret);
	//ret = printf("%f\n", 0.0 / 0.0);
	//printf("ret %d\n", ret);
	//ret = ft_printf("%+#0f\n", 0.0 / 0.0);
	//printf("ret %d\n", ret);
	//ret = printf("%+#0f\n", 0.0 / 0.0);
	//printf("ret %d\n", ret);
	//ret = ft_printf("%10.1f\n", 0.0 / 0.0);
	//printf("ret %d\n", ret);
	//ret = printf("%10.1f\n", 0.0 / 0.0);
	//printf("ret %d\n", ret);
	//ret = ft_printf("% f\n", 0.0 / 0.0);
	//printf("ret %d\n", ret);
	//ret = printf("% f\n", 0.0 / 0.0);
	//printf("ret %d\n", ret);
	//ret = ft_printf("%010f\n", 0.0 / 0.0);
	//printf("ret %d\n", ret);
	//ret = printf("%010f\n", 0.0 / 0.0);
	//printf("ret %d\n", ret);
	return (0);
}
