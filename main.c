#include "ft_printf.h"
#include <stdio.h>

#define TEST(fmt, ...) printf("%-10sOrig: {", fmt); printf("}%20d\n", printf(fmt, ##__VA_ARGS__)); printf("%10sYour: {", ""); fflush(stdout); printf("}%20d\n", ft_printf(fmt, ##__VA_ARGS__))

int	main(void)
{
	printf("%-10s%13s%25s\n", "Format", "Output", "Return");
	TEST("%s", "Hello");
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
	//printf("%f\n", 0.0 / 0.0);
	//printf("%f\n", 1.3000001);
	//printf("%f\n", 1.3000002);
	//printf("%f\n", 1.3000003);
	//printf("%f\n", 1.3000004);
	//printf("%f\n", 1.3000005);
	//printf("%f\n", 1.3000006);
	//printf("%f\n", 1.3000009);
	//printf("%.1f\n", 1.251);
	//printf("%.1f\n", 1.3);
	//printf("%.1f\n", 1.4);
	//printf("%.1f\n", 1.5);
	//ft_printf("%f\n", -1.0/0);
	return (0);
}
