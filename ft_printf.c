/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:29:44 by cnysten           #+#    #+#             */
/*   Updated: 2022/04/05 20:43:33 by carlnysten       ###   ########.fr       */
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

static void	set_flag(t_fmt *fmt, char c)
{
	if (c == '#')
		fmt->alt = 1;
	if (c == '0')
		fmt->zero = 1;
	if (c == '-')
		fmt->dash = 1;
	if (c == ' ')
		fmt->space = 1;
	if (c == '+')
		fmt->plus = 1;
}

static void	dispatch(const char *format, va_list *ap, t_str *output)
{
	t_fmt	fmt;

	ft_bzero(&fmt, sizeof (t_fmt));
	while (is_flag(*format))
	{
		set_flag(&fmt, *format);
		format++;
	}
	if (is_width(*format))
		set_width(&fmt, &format)
	if (is_precision(*format))
		set_precision(&fmt, &format);
	if (is_length(*format))
		set_length(&fmt, &format);
	set_conversion(*format);
	g_dispatch_table[dir->conversion](output, fmt, ap);
}

static char	*format_output(const char *format, va_list *ap)
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
			dispatch(format, ap, output);
			while (!is_conversion(*format))
				format++;
			start = format + 1;
		}
		format++;
	}
	ft_memcpy(output, start, (size_t)(format - start));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	char	*output;

	ret = 0;
	va_start(ap, format);
	output = format_output(format, &ap);
	ret = write(1, output, ft_strlen(output));
	va_end(ap);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;
	char	*output;

	ret = 0;
	va_start(ap, format);
	output = format_output(format, &ap);
	ret = write(fd, output, ft_strlen(output));
	va_end(ap);
	return (ret);
}

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	ap;
	int		ret;
	char	*output;

	ret = 0;
	va_start(ap, format);
	output = format_output(format, &ap);
	ret = ft_strlen(output);
	ft_memcpy(str, output, ret);
	va_end(ap);
	return (ret);
}
