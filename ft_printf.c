/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:29:44 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/19 19:20:40 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h> // remove
#include "../libft/libft.h"


t_directive	*new_directive(void)
{
	t_directive	*dir;

	dir = (t_directive *) malloc(sizeof (t_directive));
	if (!dir)
		return (NULL);
	ft_bzero(dir, sizeof (t_directive));
	return (dir);
}


char	*convert(const char *format, t_directive *dir, void *arg)
{
	static t_converter	*dispatch_table[10];
	char	*str;

	str = NULL;
	if (!dispatch_table[0])
	{
		dispatch_table[0] = as_char;
		dispatch_table[1] = as_str;
		dispatch_table[2] = as_ptr;
		dispatch_table[3] = as_decimal;
		dispatch_table[4] = as_octal;
		dispatch_table[5] = as_unsigned;
		dispatch_table[6] = as_hex_low;
		dispatch_table[7] = as_hex_upp;
		dispatch_table[8] = as_float;
		dispatch_table[9] = as_bit;
	}
	str = dispatch_table[dir->conversion](dir, arg);
	free(dir);
	return (str);
}

/*
*	The prototype for the standard printf is:
*			int	printf(const char * restrict format, ...);
*	Should restrict be omitted like in libft?
*/

int	ft_printf(const char *format, ...)
{
	char		*arg; // specifier used in two different contexts (char *, void *)
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
			if (*(format + 1) == '%')
			{
				write(1, "%", 1);
				format += 2;
				continue ;
			}
			write(1, start, (size_t)(format - start));
			arg = convert(format, ft_lstpop_left(&dir_list), va_arg(ap, void *));
			write(1, arg, ft_strlen(arg));
			format += 2; // Accurate increment amount needed
			start = format;
			continue ;
		}
		format++;
	}
	write(1, start, (size_t)(format - start));
	va_end(ap);
	return (ret);
}
