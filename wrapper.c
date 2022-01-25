/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:16:09 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/25 14:33:57 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "../libft/libft.h"

char	*as_char(t_directive *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	str = ft_strnew(1);
	if (!str)
		exit(1);
	str[0] = va_arg(*ap, char);
	return (str);
}

char	*as_string(t_directive *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	str = ft_strdup(va_arg(*ap, char *));
	if (!str)
		exit(1);
	return (str);
}

char	*as_pointer(t_directive *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	str = ptoa(va_arg(*ap, void *));
	if (!str)
		exit(1);
	return (str);
}

char	*as_decimal(t_directive *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	str = ft_itoa(va_arg(*ap, long));
	if (!str)
		exit(1);
	return (str);
}

char	*as_octal(t_directive *dir, va_list *ap)
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

char	*as_unsigned(t_directive *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	str = utoa(va_arg(*ap, long));
	if (!str)
		exit(1);
	return (str);
}

char	*as_hex(t_directive *dir, va_list *ap)
{
	char	*str;
	int		letter_case;
	int		prefix;

	if (dir->conversion == HEX_LOWER)
		letter_case = LOWERCASE;
	else
		letter_case = UPPERCASE;
	if ((dir->flags & ALT) == ALT)
		prefix = TRUE;
	else
		prefix = FALSE;
	str = itohex(va_arg(*ap, unsigned long), letter_case, prefix);
	if (!str)
		exit(1);
	return (str);
}

char	*as_float(t_directive *dir, va_list *ap)
{
	char	*str;

	str = ftoa(va_arg(*ap, double), dir->precision);
	if (!str)
		exit(1);
	return (str);
}

char	*as_bit(t_directive *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	str = ft_itoa_base(va_arg(*ap, long), 2);
	if (!str)
		exit(1);
	return (str);
}
