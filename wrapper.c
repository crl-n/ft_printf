#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"

char	*as_char(t_directive *dir, void *arg)
{
	char	*str;

	(void) dir;
	str = ft_strnew(1);
	if (!str)
		exit(1);
	str[0] = *(char *)arg;
	return (str);
}

char	*as_str(t_directive *dir, void *arg)
{
	char	*str;

	(void) dir;
	str = ft_strdup((char *) arg);
	if (!str)
		exit(1);
	return (str);
}

char	*as_ptr(t_directive *dir, void *arg)
{
	char	*str;

	(void) dir;
	str = ptoa((unsigned long) arg);
	if (!str)
		exit(1);
	return (str);
}

char	*as_decimal(t_directive *dir, void *arg)
{
	char	*str;

	(void) dir;
	str = ft_itoa((long) arg);
	if (!str)
		exit(1);
	return (str);
}

char	*as_octal(t_directive *dir, void *arg)
{
	char	*str;

	(void) dir;
	str = ft_itoa_base((long) arg, 8);
	if (!str)
		exit(1);
	return (str);
}

char	*as_unsigned(t_directive *dir, void *arg)
{
	(void) dir;
	(void) arg;
	return (NULL);
}

char	*as_hex_lower(t_directive *dir, void *arg)
{
	char	*str;

	(void) dir;
	str = ft_itoa_base((long) arg, 16);
	if (!str)
		exit(1);
	return (str);
}

char	*as_hex_upper(t_directive *dir, void *arg)
{
	(void) dir;
	(void) arg;
	return (NULL);
}

char	*as_float(t_directive *dir, void *arg)
{
	(void) dir;
	(void) arg;
	return (NULL);
}

char	*as_bit(t_directive *dir, void *arg)
{
	char	*str;

	(void) dir;
	str = ft_itoa_base((long) arg, 2);
	if (!str)
		exit(1);
	return (str);
}
