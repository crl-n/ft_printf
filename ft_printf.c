/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:29:44 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/08 09:55:52 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../libft/libft.h"

static const t_converter	g_dispatch_table[12] = {
	output_char,
	output_string,
	output_pointer,
	output_decimal,
	output_decimal,
	output_octal,
	output_unsigned,
	output_hex,
	output_hex,
	output_float,
	output_bit,
	output_percentage
};

/*	dispatch_dir() sends each directive to its corresponding handler */

static void	dispatch_dir(t_dir *dir, va_list *ap, int *ret)
{
	g_dispatch_table[dir->conversion](dir, ap, ret);
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
