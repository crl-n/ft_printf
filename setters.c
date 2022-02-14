/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:57:05 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/14 21:25:57 by carlnysten       ###   ########.fr       */
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
		dir->alt_flag = TRUE;
	else if (c == '0' && !dir->minus_flag)
		dir->zero_flag = TRUE;
	else if (c == '-')
	{
		dir->minus_flag = TRUE;
		if (dir->zero_flag)
			dir->zero_flag = FALSE;
	}
	else if (c == ' ')
		dir->space_flag = TRUE;
	else if (c == '+')
		dir->plus_flag = TRUE;
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

	if (**format == '*')
	{
		dir->width_from_arg = TRUE;
		*stage = WIDTH;
		return ;
	}
	width = ft_atoi(*format);
	if (width == 0)
		return ;
	dir->width = width;
	dir->width_set = TRUE;
	*stage = WIDTH;
	*format = *format + ft_intlen(dir->width);
}

void	set_precision(const char **format, t_dir *dir, t_stage *stage)
{
	if (*(*format + 1) == '*')
	{
		dir->precision_from_arg = TRUE;
		*format = *format + 2;
	}
	else
	{
		dir->precision = ft_atoi(*format + 1);
		*format = *format + ft_intlen(dir->precision);
	}
	*stage = PRECISION;
}

void	set_length(const char **format, t_dir *dir)
{
	if (**format == 'l' && *(*format + 1) == 'l')
	{
		dir->length = LL;
		*format += 2;
	}
	else if (**format == 'h' && *(*format + 1) == 'h')
	{
		dir->length = HH;
		*format += 2;
	}
	else if (**format == 'l')
	{
		dir->length = L;
		*format += 1;
	}
	else if (**format == 'h')
	{
		dir->length = H;
		*format += 1;
	}
	else if (**format == 'L')
	{
		dir->length = CAPITAL_L;
		*format += 1;
	}
}
