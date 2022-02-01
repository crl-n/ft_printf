/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:29:44 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/01 22:04:08 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
//#include <stdlib.h>
#include "../libft/libft.h"

char	*convert(t_dir *dir, va_list *ap)
{
	static t_converter	*dispatch_table[11];
	char				*str;

	if (!dispatch_table[0])
	{
		dispatch_table[CHAR] = as_char;
		dispatch_table[STRING] = as_string;
		dispatch_table[POINTER] = as_pointer;
		dispatch_table[DECIMAL] = as_decimal;
		dispatch_table[INTEGER] = as_decimal;
		dispatch_table[OCTAL] = as_octal;
		dispatch_table[UNSIGNED] = as_unsigned;
		dispatch_table[HEX_LOWER] = as_hex;
		dispatch_table[HEX_UPPER] = as_hex;
		dispatch_table[FLOAT] = as_float;
		dispatch_table[BIT] = as_bit;
	}
	if (dir->conversion == PERCENTAGE)
		return (ft_strdup("%"));
	str = dispatch_table[dir->conversion](dir, ap);
	return (str);
}

/*
*	The prototype for the standard printf is:
*			int	printf(const char * restrict format, ...);
*/

/* TODO Make width work with % */

static void	print_formatted(const char *format,
								t_list **dir_list,
								va_list *ap,
								int *ret)
{
	const char	*start;

	start = format;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			write(1, start, (size_t)(format - start - 1));
			*ret += (format - start - 1);
			put_arg(ft_lstpop_left(dir_list), ap, ret);
			while (!is_conversion(*format))
				format++;
			start = format + 1;
		}
		format++;
	}
	write(1, start, (size_t)(format - start));
	*ret += (format - start);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	t_list	*dir_list;

	ret = 0;
	dir_list = NULL;
	if (parse_format(format, &dir_list) < 0)
		return (-1);
	va_start(ap, format);
	print_formatted(format, &dir_list, &ap, &ret);
	va_end(ap);
	return (ret);
}
