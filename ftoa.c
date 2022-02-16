/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:46:53 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/16 15:59:23 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>

static size_t	get_intlen(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	integer_part(long value, char *str, int negative, int int_len)
{
	if (negative)
		str[0] = '-';
	int_len--;
	while (value > 9)
	{
		str[int_len--] = '0' + value % 10;
		value = value / 10;
	}
	str[int_len] = '0' + value;
}

static void	fraction_part(long double fraction,
							char *str,
							int start,
							int precision)
{
	int	i;

	if (precision == 0)
		return ;
	i = 0;
	str[start - 1] = '.';
	while (i < precision)
	{
		fraction *= 10;
		str[start + i++] = '0' + ((int) fraction % 10);
		fraction -= (int) fraction;
	}
}

static double	rounding(int precision)
{
	double	rounding;

	rounding = 0.5;
	while (precision--)
		rounding *= 0.1;
	return (rounding);
}

//TODO nan, inf, -inf, -0

char	*ftoa(long double value, int precision, t_dir *dir)
{
	char		*str;
	int			int_len;
	int			total_len;
	long double	fraction;

	if (value < 0.0)
	{
		dir->negative = 1;
		value = -value;
	}
	int_len = get_intlen((long) value);
	total_len = int_len + precision;
	if (precision > 0)
		total_len++;
	str = (char *) malloc(total_len + 1 * sizeof (char));
	if (!str)
		return (NULL);
	str[total_len] = '\0';
	integer_part((long) value, str, dir->negative, int_len);
	value = value + rounding(precision);
	if (precision == 0)
		return (str);
	fraction = value - (long) value;
	fraction_part(fraction, str, int_len + 1, precision);
	return (str);
}
