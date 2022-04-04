/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:29:44 by cnysten           #+#    #+#             */
/*   Updated: 2022/04/04 16:33:08 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

static void	die(void)
{
	//TODO
}

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

static void	dispatch_dir(t_dir *dir, va_list *ap, int *ret)
{
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
	g_dispatch_table[dir->conversion](dir, ap, ret);
	free(dir);
}

static void	print_formatted(const char *format,
								t_list **dir_list,
								va_list *ap,
								int *ret)
{
	const char	*start;
	t_dir		*dir;

	start = format;
	while (*format)
	{
		if (*format == '%')
		{
			*ret += write(1, start, (size_t)(format - start));
			dir = ft_lstpop_left(dir_list);
			if (dir->conversion)
			{
				format++;
				while (!is_conversion(*format))
					format++;
				start = format + 1;
			}
			else
				start = format + 1;
			dispatch_dir(dir, ap, ret);
		}
		format++;
	}
	*ret += write(1, start, (size_t)(format - start));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	t_list	*dir_list;

	ret = 0;
	dir_list = NULL;
	parse_format(format, &dir_list);
	va_start(ap, format);
	print_formatted(format, &dir_list, &ap, &ret);
	va_end(ap);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;
	t_list	*dir_list;

	ret = 0;
	dir_list = NULL;
	parse_format(format, &dir_list);
	va_start(ap, format);
	print_formatted(format, &dir_list, &ap, &ret);
	va_end(ap);
	return (ret);
}

int	ft_sprintf(char *str, const char *format, ...)
{
	va_list	ap;
	int		ret;
	t_list	*dir_list;

	ret = 0;
	dir_list = NULL;
	parse_format(format, &dir_list);
	va_start(ap, format);
	print_formatted(format, &dir_list, &ap, &ret);
	va_end(ap);
	return (ret);
}
