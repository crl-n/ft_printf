/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:29:44 by cnysten           #+#    #+#             */
/*   Updated: 2022/04/05 22:47:44 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

static const t_converter	g_dispatch_table[13] = {
	output_none,
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

static void	format_argument(const char *format, va_list *ap, t_str *output)
{
	t_fmt	fmt;

	fmt = get_fmt(format);
	g_dispatch_table[fmt.conversion](output, fmt, ap);
}

static t_str	*format_output(const char *format, va_list *ap)
{
	const char	*start;
	t_str		*output;

	output = new_str(ft_strlen(format));
	if (!output)
		exit(0);
	start = format;
	while (*format)
	{
		if (*format == '%')
		{
			append(output, start, (size_t)(format - start));
			format_argument(format, ap, output);
			while (!is_conversion(*format))
				format++;
			start = format + 1;
		}
		format++;
	}
	append(output, start, (size_t)(format - start));
	return (output);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	t_str	*output;

	ret = 0;
	va_start(ap, format);
	output = format_output(format, &ap);
	ret = write(1, output->data, ft_strlen(output->data));
	va_end(ap);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;
	t_str	*output;

	ret = 0;
	va_start(ap, format);
	output = format_output(format, &ap);
	ret = write(fd, output->data, ft_strlen(output->data));
	va_end(ap);
	return (ret);
}

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	ap;
	int		ret;
	t_str	*output;

	ret = 0;
	va_start(ap, format);
	output = format_output(format, &ap);
	ret = ft_strlen(output->data);
	ft_memcpy(str, output->data, ret);
	va_end(ap);
	return (ret);
}
