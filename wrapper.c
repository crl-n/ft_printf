/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:16:09 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/27 21:49:55 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "../libft/libft.h"

char	*as_char(t_dir *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	str = ft_strnew(1);
	if (!str)
		exit(1);
	str[0] = va_arg(*ap, int);
	return (str);
}

char	*as_string(t_dir *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	str = ft_strdup(va_arg(*ap, char *));
	if (!str)
		exit(1);
	return (str);
}

char	*as_pointer(t_dir *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	str = itohex(va_arg(*ap, unsigned long), LOWERCASE, TRUE);
	if (!str)
		exit(1);
	return (str);
}

char	*as_decimal(t_dir *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	str = ft_itoa(va_arg(*ap, int));
	if (!str)
		exit(1);
	return (str);
}

char	*as_octal(t_dir *dir, va_list *ap)
{
	char	*str;
	int		prefix;

	if ((dir->flags & ALT) == ALT)
		prefix = TRUE;
	else
		prefix = FALSE;
	str = itooctal(va_arg(*ap, unsigned long), prefix);
	if (!str)
		exit(1);
	return (str);
}

char	*as_unsigned(t_dir *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	str = utoa(va_arg(*ap, unsigned long));
	if (!str)
		exit(1);
	return (str);
}

char	*as_hex(t_dir *dir, va_list *ap)
{
	char	*str;
	int		letter_case;
	int		prefix;
	unsigned long	arg;

	arg = va_arg(*ap, unsigned long);
	if (dir->conversion == HEX_LOWER)
		letter_case = LOWERCASE;
	else
		letter_case = UPPERCASE;
	if ((dir->flags & ALT) == ALT && arg != 0)
		prefix = TRUE;
	else
		prefix = FALSE;
	str = itohex(arg, letter_case, prefix);
	if (!str)
		exit(1);
	return (str);
}

char	*as_float(t_dir *dir, va_list *ap)
{
	char	*str;

	str = ftoa(va_arg(*ap, double), dir->precision);
	if (!str)
		exit(1);
	return (str);
}

char	*as_bit(t_dir *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	str = ft_itoa_base(va_arg(*ap, long), 2);
	if (!str)
		exit(1);
	return (str);
}
