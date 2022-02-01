/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:16:09 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/01 17:41:03 by carlnysten       ###   ########.fr       */
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
	char	*arg;

	(void) dir;
	arg = va_arg(*ap, char *);
	if (arg == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(arg);
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

	if (dir->length == H)
		str = ft_itoa(va_arg(*ap, short int));
	else if (dir->length == HH)
		str = ft_itoa(va_arg(*ap, signed char));
	else if (dir->length == L)
		str = ft_itoa(va_arg(*ap, long int));
	else if (dir->length == LL)
		str = ft_itoa(va_arg(*ap, long long int));
	else
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
	if (dir->length == H)
		str = itooctal(va_arg(*ap, unsigned short int), prefix);
	else if (dir->length == HH)
		str = itooctal(va_arg(*ap, unsigned char), prefix);
	else if (dir->length == L)
		str = itooctal(va_arg(*ap, unsigned long int), prefix);
	else if (dir->length == LL)
		str = itooctal(va_arg(*ap, unsigned long long int), prefix);
	else
		str = itooctal(va_arg(*ap, unsigned int), prefix);
	if (!str)
		exit(1);
	return (str);
}

char	*as_unsigned(t_dir *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	if (dir->length == H)
		str = utoa(va_arg(*ap, unsigned short int));
	else if (dir->length == HH)
		str = utoa(va_arg(*ap, unsigned char));
	else if (dir->length == L)
		str = utoa(va_arg(*ap, unsigned long int));
	else if (dir->length == LL)
		str = utoa(va_arg(*ap, unsigned long long int));
	else
		str = utoa(va_arg(*ap, unsigned int));
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

	if (dir->length == H)
		arg = va_arg(*ap, unsigned short int);
	else if (dir->length == HH)
		arg = va_arg(*ap, unsigned char);
	else if (dir->length == L)
		arg = va_arg(*ap, unsigned long int);
	else if (dir->length == LL)
		arg = va_arg(*ap, unsigned long long int);
	else
		arg = va_arg(*ap, unsigned int);
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
