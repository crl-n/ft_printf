/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:29:44 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/02 13:56:30 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../libft/libft.h"

/*	dispatch_dir() sends each directive to its corresponding handler */

static void	dispatch_dir(t_dir *dir, va_list *ap, int *ret)
{
	static t_converter	*dispatch_table[12];

	if (!dispatch_table[0])
	{
		dispatch_table[CHAR] = output_char;
		dispatch_table[STRING] = output_string;
		dispatch_table[POINTER] = output_pointer;
		dispatch_table[DECIMAL] = output_decimal;
		dispatch_table[INTEGER] = output_decimal;
		dispatch_table[OCTAL] = output_octal;
		dispatch_table[UNSIGNED] = output_unsigned;
		dispatch_table[HEX_LOWER] = output_hex;
		dispatch_table[HEX_UPPER] = output_hex;
		dispatch_table[FLOAT] = output_float;
		dispatch_table[BIT] = output_bit;
		dispatch_table[PERCENTAGE] = output_percentage;
	}
	dispatch_table[dir->conversion](dir, ap, ret);
	free(dir);
}

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
			dispatch_dir(ft_lstpop_left(dir_list), ap, ret);
			while (!is_conversion(*format))
				format++;
			start = format + 1;
		}
		format++;
	}
	write(1, start, (size_t)(format - start));
	*ret += (format - start);
}

/*
*	The prototype for the standard printf is:
*			int	printf(const char * restrict format, ...);
*
*	First the format string is parsed for directives. Then,
*	the format string is printed with formatted arguments.
*/

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
