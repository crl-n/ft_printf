/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:29:44 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/01 17:35:02 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../libft/libft.h"

static void	justify(t_dir *dir, size_t n, int *ret)
{
	char	c;
	char	*str;

	str = ft_strnew(n);
	if (!str)
		exit(1);
	if ((dir->flags & ZERO) == ZERO)
		c = '0';
	else
		c = ' ';
	if ((dir->flags & SPACE) == SPACE)
		n--;
	ft_memset((void *)str, c, n);
	write(1, str, n);
	*ret += n;
	free(str);
}

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

static void	put_arg(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	size_t	len;

	str = convert(dir, ap);
	len = ft_strlen(str);
	if ((dir->conversion == DECIMAL || dir->conversion == INTEGER) && str[0] == '-')
		dir->negative = 1;
	if ((dir->flags & SPACE) == SPACE && ((dir->flags & PLUS) == 0 || dir->negative == 1)
		&& (dir->conversion == DECIMAL || dir->conversion == INTEGER || dir->conversion == FLOAT))
	{
		write(1, " ", 1);
		*ret += 1;
	}
	if (dir->width > (int)len && (dir->flags & MINUS) != MINUS)
		justify(dir, dir->width - len, ret);
	if (dir->negative == 0 && (dir->flags & PLUS) == PLUS)
	{
		write(1, "+", 1);
		*ret += 1;
	}
	write(1, str, len);
	*ret += len;
	if (dir->width > (int)len && (dir->flags & MINUS) == MINUS)
		justify(dir, dir->width - len, ret);
	free(str);
	free(dir);
}

/*
*	The prototype for the standard printf is:
*			int	printf(const char * restrict format, ...);
*/

/* TODO Make width work with % */

int	ft_printf(const char *format, ...)
{
	const char	*start;
	va_list		ap;
	int			ret;
	t_list		*dir_list;

	ret = 0;
	start = format;
	dir_list = NULL;
	if (parse_format(format, &dir_list) < 0)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			write(1, start, (size_t)(format - start - 1));
			ret += (format - start - 1);
			put_arg(ft_lstpop_left(&dir_list), &ap, &ret);
			while (!is_conversion(*format))
				format++;
			start = format + 1;
		}
		format++;
	}
	write(1, start, (size_t)(format - start));
	ret += (format - start);
	va_end(ap);
	return (ret);
}
