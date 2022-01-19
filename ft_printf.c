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

int	is_flag(const char c) // bonus flags missing
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+' || c == '\'')
		return (1);
	return (0);
}

/*
 * There can be zero or more of the flags: #0- +'
 */

void	set_flag(const char c, t_directive *dir) // bonus flags missing
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
		|| c == 'x' || c == 'X' || c == 'f' || c == 'b')
		return (1);
	return (0);
}

/*
 * Valid conversion specifiers: diouxX, csp, f and b
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
		dir->conversion = FLOAT;
	if (format == 'b')
		dir->conversion = BIT;
}

void	set_width(const char *format, t_directive *dir)
{
	dir->width = ft_atoi(format);
}

int	is_precision(const char c)
{
	if (c == '.')
		return (1);
	return (0);
}

void	set_precision(const char *format, t_directive *dir)
{
	dir->precision = ft_atoi(format + 1);
}

int	is_length(const char c)
{
	if (c == 'l' || c == 'h')
		return (1);
	return (0);
}

void	set_length(const char *format, t_directive *dir)
{
	if (*format == 'l' && *(format + 1) == 'l')
		dir->length = LL;
	if (*format == 'h' && *(format + 1) == 'h')
		dir->length = HH;
	if (*format == 'l')
		dir->length = L;
	if (*format == 'h')
		dir->length = H;
}

t_directive	*new_directive(void)
{
	t_directive	*dir;

	dir = (t_directive *) malloc(sizeof (t_directive));
	if (!dir)
		return (NULL);
	ft_bzero(dir, sizeof (t_directive));
	return (dir);
}

/*
 * The format string follows this formula:
 *
 * 		%[flag][width][.precision][length]specifier
 *
 * parse_format() parses the format string and extracts the contained directive.
 */

//TODO: test with width AND precision
void	parse_format(const char *format, t_list **dir_list)
{
	t_directive	*dir;

	dir = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			dir = new_directive();
			while (*format)
			{
				if (is_flag(*format))
					set_flag(*format, dir);
				if (ft_isdigit(*format)) // RIGHTERNMOST number is used unless it is 0
					set_width(format, dir); // format needs to be forwarded as many steps as there are digits
				if (is_precision(*format))
					set_precision(format, dir); // format needs to be forwarded as many steps as there are digits + 1
				if (is_length(*format))
					set_length(format, dir);
				if (is_conversion(*format))
					set_conversion(*format, dir);
				format++;
			}
			ft_lstadd_back(dir_list, ft_lstnew((void *)dir, sizeof (t_directive *)));
		}
		format++;
	}
}

/*
char	*convert(const char *format, char *arg)
{
	t_directive	dir;

	bzero(&dir, sizeof (t_directive));
	parse_format(format, arg, &dir);
	return ("missing string");
}
*/

/*
*	The prototype for the standard printf is:
*			int	printf(const char * restrict format, ...);
*	Should restrict be omitted like in libft?
*/

int	ft_printf(const char *format, ...)
{
	//char		*arg;
	//const char	*start;
	va_list		ap;
	int			ret;
	t_list		*dir_list;

	ret = 0;
	//start = format;
	dir_list = NULL;
	parse_format(format, &dir_list);
	va_start(ap, format);
	/*
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
	*/
	return (ret);
}
