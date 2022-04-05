/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:25:32 by carlnysten        #+#    #+#             */
/*   Updated: 2022/04/05 22:56:30 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	set_flag(t_fmt *fmt, const char c)
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

static void	set_width(t_fmt *fmt, const char **format)
{
	fmt->width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
}

static void	set_precision(t_fmt *fmt, const char **format)
{
	(*format)++;
	fmt->precision = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
}

static void	set_length(t_fmt *fmt, const char **format)
{
	if (**format == 'l' && *(*format + 1) == 'l')
	{
		fmt->length = ll;
		*format += 2;
	}
	else if (**format == 'h' && *(*format + 1) == 'h')
	{
		fmt->length = hh;
		*format += 2;
	}
	else if (**format == 'l')
	{
		fmt->length = l;
		*format += 1;
	}
	else if (**format == 'h')
	{
		fmt->length = h;
		*format += 1;
	}
	else if (**format == 'L')
	{
		fmt->length = L;
		*format += 1;
	}
}

static void	set_conversion(t_fmt *fmt, const char format)
{
	if (format == 'c')
		fmt->conversion = character;
	else if (format == 's')
		fmt->conversion = string;
	else if (format == 'p')
		fmt->conversion = pointer;
	else if (format == 'd')
		fmt->conversion = decimal;
	else if (format == 'i')
		fmt->conversion = integer;
	else if (format == 'o')
		fmt->conversion = octal;
	else if (format == 'u')
		fmt->conversion = uinteger;
	else if (format == 'x')
		fmt->conversion = hex_lower;
	else if (format == 'X')
		fmt->conversion = hex_upper;
	else if (format == 'f')
		fmt->conversion = floating;
	else if (format == 'b')
		fmt->conversion = bit;
	else if (format == '%')
		fmt->conversion = percentage;
}

t_fmt	get_fmt(const char *format)
{
	t_fmt	fmt;

	ft_bzero(&fmt, sizeof (t_fmt));
	while (is_flag(*format))
	{
		set_flag(&fmt, *format);
		format++;
	}
	if (is_width(*format))
		set_width(&fmt, &format);
	if (is_precision(*format))
		set_precision(&fmt, &format);
	if (is_length(*format))
		set_length(&fmt, &format);
	set_conversion(&fmt, *format);
	return (fmt);
}
