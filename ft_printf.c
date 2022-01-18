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

int	is_flag(const char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+' || c == '\'')
		return (1);
	return (0);
}

/*
 * There can be zero or more of the flags: #0- +'
 */

void	set_flag(const char c, t_directive *dir)
{
	if (c == '#')
		dir->flags = dir->flags | ALT;
	if (c == '0')
		dir->flags = dir->flags | ZERO;
	if (c == '-')
		dir->flags = dir->flags | MINUS;
	if (c == ' ')
		dir->flags = dir->flags | SPACE;
	if (c == '+')
		dir->flags = dir->flags | PLUS;
	if (c == '\'')
		dir->flags = dir->flags | SEP;
}

int	is_conversion(const char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'o' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'f')
		return (1);
	return (0);
}

/*
 * Valid conversion specifiers: diouxX, csp, f
 */

void	set_conversion(const char format, t_directive *dir)
{
	if (format == 'c')
		dir->conversion = CHAR;
	if (format == 's')
		dir->conversion = STRING;
	if (format == 'p')
		dir->conversion = POINTER;
	if (format == 'd')
		dir->conversion = DIGIT;
	if (format == 'i')
		dir->conversion = INTEGER;
	if (format == 'o')
		dir->conversion = OCTAL;
	if (format == 'u')
		dir->conversion = UNSIGNED;
	if (format == 'x')
		dir->conversion = HEX_LOWER;
	if (format == 'X')
		dir->conversion = HEX_UPPER;
	if (format == 'f')
		dir->conversion = HEX_UPPER;
}

/*
 * The format string follows this formula:
 *
 * 		%[flag][width][.precision][length]specifier
 *
 * parse_format() parses the format string and extracts the contained directive.
 */

void	parse_format(const char *format, char *arg, t_directive *dir)
{
	(void) arg;
	format++;
	while (is_flag(*format))
		set_flag(*format++, dir);
	/*
	if (is_numeric(*format))
		set_width(*format, dir); // format needs to be forwarded as many steps as there are digits
	if (is_precision(*format))
		set_precision(*format, dir); // format nees to be forwarded as many steps as there are digits + 1
	while (is_length)
		set_length(*format++, dir);
	*/
	if (is_conversion(*format))
		set_conversion(*format, dir);
}

char	*convert(const char *format, char *arg)
{
	t_directive	dir;

	bzero(&dir, sizeof (t_directive));
	parse_format(format, arg, &dir);
	return ("missing string");
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
	while (*format) // If there is an invalid format printf doesn't print anything --> parse format before any write
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
