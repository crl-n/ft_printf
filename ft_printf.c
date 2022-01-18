/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:29:44 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/18 17:24:43 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h> // remove

/*
 * There can be zero or more of the flags: #0- +'
 */

void	set_flag(const char *format)
{
	if (*format == '#')
		
}

/*
 * Valid conversion specifiers: diouxX, csp, f
 */

void	set_conversion(const char *format)
{
	if (*format == 'c')
		return (NULL);
	if (*format == 's')
		return (arg);
	if (*format == 'p')
		return (ptoa((unsigned long) arg));
	if (*format == 'c')
		return (NULL);
	return (NULL);
}

/*
 * The format string follows this formula:
 *
 * 		%[flag][width][.precision][length]specifier
 */

char	*parse_format(const char *format, char *arg)
{
	format++;
	while (is_flag(*format))
		set_flag(*format++);
	if (is_numeric(*format))
		set_width(*format); // format needs to be forwarded as many steps as there are digits
	if (is_precision(*format))
		set_precision(*format); // format nees to be forwarded as many steps as there are digits + 1
	while (is_length)
		set_length(*format++);
	set_conversion(*format);
}


char	*convert(const char *format, char *arg)
{
	return (parse_format(format, arg));
}

/*
*	The prototype for the standard printf is:
*			int	printf(const char * restrict format, ...);
*	Should restrict be omitted like in libft?
*/

int	ft_printf(const char *format, ...)
{
	char		*arg;
	const char	*start;
	va_list		ap;
	int			ret;

	ret = 0;
	start = format;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			write(1, start, (size_t)(format - start)); // Risk of casting negative value?
			arg = convert(format, va_arg(ap, char *));
			write(1, arg, strlen(arg)); // Change to ft_strlen
			format += 2;
			start = format;
			continue ;
		}
		format++;
	}
	write(1, start, (size_t)(format - start));
	va_end(ap);
	return (ret);
}
