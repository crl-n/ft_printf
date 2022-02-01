/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:57:05 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/01 19:31:17 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * There can be zero or more of the flags: #0- +'
 */

void	set_flag(const char **format, t_dir *dir, t_stage *stage)
{
	char	c;

	c = **format;
	if (c == '#')
		dir->flags = dir->flags | ALT;
	else if (c == '0')
		dir->flags = dir->flags | ZERO;
	else if (c == '-')
		dir->flags = dir->flags | MINUS;
	else if (c == ' ')
		dir->flags = dir->flags | SPACE;
	else if (c == '+')
		dir->flags = dir->flags | PLUS;
	*format = *format + 1;
	*stage = FLAG;
}

/*
 * Valid conversion specifiers: diouxX, csp, f (and b as a bonus)
 */

void	set_conversion(const char format, t_dir *dir)
{
	if (format == 'c')
		dir->conversion = CHAR;
	else if (format == 's')
		dir->conversion = STRING;
	else if (format == 'p')
		dir->conversion = POINTER;
	else if (format == 'd')
		dir->conversion = DECIMAL;
	else if (format == 'i')
		dir->conversion = INTEGER;
	else if (format == 'o')
		dir->conversion = OCTAL;
	else if (format == 'u')
		dir->conversion = UNSIGNED;
	else if (format == 'x')
		dir->conversion = HEX_LOWER;
	else if (format == 'X')
		dir->conversion = HEX_UPPER;
	else if (format == 'f')
		dir->conversion = FLOAT;
	else if (format == 'b')
		dir->conversion = BIT;
	else if (format == '%')
		dir->conversion = PERCENTAGE;
}

void	set_width(const char **format, t_dir *dir, t_stage *stage)
{
	int	width;

	width = ft_atoi(*format);
	if (width == 0)
		return ;
	dir->width = width;
	*format = *format + ft_intlen(dir->width);
	*stage = WIDTH;
}

void	set_precision(const char **format, t_dir *dir)
{
	dir->precision = ft_atoi(*format + 1);
	*format = *format + ft_intlen(dir->precision);
}

void	set_length(const char *format, t_dir *dir)
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
