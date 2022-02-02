/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:16:09 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/02 11:13:43 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "../libft/libft.h"

char	*as_decimal(t_dir *dir, va_list *ap)
{
	char	*str;

	if (dir->length == HH)
		str = itoa((signed char) va_arg(*ap, int), dir);
	else if (dir->length == H)
		str = itoa((signed short int) va_arg(*ap, int), dir);
	else if (dir->length == L)
		str = itoa(va_arg(*ap, long int), dir);
	else if (dir->length == LL)
		str = itoa(va_arg(*ap, long long int), dir);
	else
		str = itoa(va_arg(*ap, int), dir);
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
	if (dir->length == HH)
		str = itooctal((unsigned char) va_arg(*ap, unsigned int), prefix, dir);
	else if (dir->length == H)
		str = itooctal((unsigned short int) va_arg(*ap, unsigned int), prefix, dir);
	else if (dir->length == L)
		str = itooctal(va_arg(*ap, unsigned long int), prefix, dir);
	else if (dir->length == LL)
		str = itooctal(va_arg(*ap, unsigned long long int), prefix, dir);
	else
		str = itooctal(va_arg(*ap, unsigned int), prefix, dir);
	if (!str)
		exit(1);
	return (str);
}

char	*as_unsigned(t_dir *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	if (dir->length == HH)
		str = utoa((unsigned char) va_arg(*ap, unsigned int));
	else if (dir->length == H)
		str = utoa((unsigned short int) va_arg(*ap, unsigned int));
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
	char			*str;
	int				letter_case;
	int				prefix;
	unsigned long	arg;

	if (dir->length == HH)
		arg = (unsigned char) va_arg(*ap, unsigned int);
	else if (dir->length == H)
		arg = (unsigned short int) va_arg(*ap, unsigned int);
	else if (dir->length == L)
		arg = va_arg(*ap, unsigned long int);
	else if (dir->length == LL)
		arg = va_arg(*ap, unsigned long long int);
	else
		arg = va_arg(*ap, unsigned int);
	letter_case = LOWERCASE;
	if (dir->conversion == HEX_UPPER)
		letter_case = UPPERCASE;
	prefix = FALSE;
	if ((dir->flags & ALT) == ALT && arg != 0)
		prefix = TRUE;
	str = itohex(arg, letter_case, prefix, dir);
	if (!str)
		exit(1);
	return (str);
}
