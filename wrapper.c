/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:16:09 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/23 18:30:21 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "../libft/libft.h"

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

char	*as_string(t_directive *dir, void *arg)
{
	char	*str;

	(void) dir;
	str = ft_strdup((char *) arg);
	if (!str)
		exit(1);
	return (str);
}

char	*as_pointer(t_directive *dir, void *arg)
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
	int		prefix;
	
	if ((dir->flags & ALT) == ALT)
		prefix = TRUE;
	else
		prefix = FALSE;
	str = itooctal((long) arg, prefix);
	if (!str)
		exit(1);
	return (str);
}

char	*as_unsigned(t_directive *dir, void *arg)
{
	char	*str;

	(void) dir;
	str = utoa((long) arg);
	if (!str)
		exit(1);
	return (str);
}

char	*as_hex(t_directive *dir, void *arg)
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
	str = itohex((long) arg, letter_case, prefix);
	if (!str)
		exit(1);
	return (str);
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
