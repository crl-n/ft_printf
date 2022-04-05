/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:29:44 by cnysten           #+#    #+#             */
/*   Updated: 2022/04/05 17:30:46 by cnysten          ###   ########.fr       */
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

static void	dispatch(const char *format, va_list *ap)
{
	/*
	if (dir->width_from_arg)
	{
		if (!dir->width_set)
		{
			dir->width = va_arg(*ap, int);
			if (dir->width < 0)
			{
				dir->width = -dir->width;
				dir->minus_flag = true;
				dir->zero_flag = false;
			}
		}
		else
			va_arg(*ap, int);
	}
	if (dir->precision_from_arg)
	{
		dir->precision = va_arg(*ap, int);
		if (dir->precision < 0)
			dir->precision = -1;
	}
	*/
	g_dispatch_table[dir->conversion](format, ap, ret);
}

static char	*format_output(const char *format, va_list *ap)
{
	const char	*start;

	start = format;
	while (*format)
	{
		if (*format == '%')
		{
			ft_memcpy(output, start, (size_t)(format - start));
			dispatch(format, ap, ret);
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
