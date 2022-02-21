/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:57:05 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/21 19:02:35 by cnysten          ###   ########.fr       */
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
		dir->alt_flag = true;
	else if (c == '0' && !dir->minus_flag)
		dir->zero_flag = true;
	else if (c == '-')
	{
		dir->minus_flag = true;
		if (dir->zero_flag)
			dir->zero_flag = false;
	}
	else if (c == ' ')
		dir->space_flag = true;
	else if (c == '+')
		dir->plus_flag = true;
	*format = *format + 1;
	*stage = flag;
}

/*
 * Valid conversion specifiers: diouxX, csp, f (and b as a bonus)
 */

void	set_conversion(const char format, t_dir *dir)
{
	if (format == 'c')
		dir->conversion = character;
	else if (format == 's')
		dir->conversion = string;
	else if (format == 'p')
		dir->conversion = pointer;
	else if (format == 'd')
		dir->conversion = decimal;
	else if (format == 'i')
		dir->conversion = integer;
	else if (format == 'o')
		dir->conversion = octal;
	else if (format == 'u')
		dir->conversion = uinteger;
	else if (format == 'x')
		dir->conversion = hex_lower;
	else if (format == 'X')
		dir->conversion = hex_upper;
	else if (format == 'f')
		dir->conversion = floating;
	else if (format == 'b')
		dir->conversion = bit;
	else if (format == '%')
		dir->conversion = percentage;
}

void	set_width(const char **format, t_dir *dir, t_stage *stage)
{
	int	n;

	if (**format == '*')
	{
		dir->width_from_arg = true;
		*stage = width;
		return ;
	}
	n = ft_atoi(*format);
	if (n == 0)
		return ;
	dir->width = n;
	dir->width_set = true;
	*stage = width;
	*format = *format + ft_intlen(dir->width);
}

void	set_precision(const char **format, t_dir *dir, t_stage *stage)
{
	if (*(*format + 1) == '*')
	{
		dir->precision_from_arg = true;
		*format = *format + 2;
	}
	else
	{
		dir->precision = ft_atoi(*format + 1);
		*format = *format + ft_intlen(dir->precision);
	}
	*stage = precision;
}

void	set_length(const char **format, t_dir *dir)
{
	if (**format == 'l' && *(*format + 1) == 'l')
	{
		dir->length = ll;
		*format += 2;
	}
	else if (**format == 'h' && *(*format + 1) == 'h')
	{
		dir->length = hh;
		*format += 2;
	}
	else if (**format == 'l')
	{
		dir->length = l;
		*format += 1;
	}
	else if (**format == 'h')
	{
		dir->length = h;
		*format += 1;
	}
	else if (**format == 'L')
	{
		dir->length = L;
		*format += 1;
	}
}
