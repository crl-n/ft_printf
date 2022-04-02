/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:46:53 by cnysten           #+#    #+#             */
/*   Updated: 2022/04/02 11:28:16 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>

static void	get_lengths(long n, int precision, int *int_len, int *total_len)
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
	*total_len = len + precision + (precision > 0);
	*int_len = len;
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

static void	fraction_part(long double value,
							char *str,
							int start,
							int precision)
{
	int			i;
	long double	fraction;

	if (precision == 0)
		return ;
	fraction = value - (long) value;
	i = 0;
	str[start - 1] = '.';
	while (i < precision)
	{
		fraction *= 10;
		str[start + i++] = '0' + ((int) fraction % 10);
		fraction -= (int) fraction;
	}
}

static long double	rounding(long double value, int precision)
{
	int			least;
	int			i;
	long double	rounding;

	i = 0;
	while (i++ < precision)
	{
		value = value - (long) value;
		value *= 10;
	}
	least = (int) value;
	value = value - (int) value;
	rounding = 0.5;
	while (precision--)
		rounding *= 0.1;
	if ((int) value * 10 == 5 && value - (long double)((int) value) == 0.0
			&& least % 2 == 0)
		return (0.0);
	return (rounding);
}

char	*ftoa(long double value, int precision, t_dir *dir, char *str)
{
	int	int_len;
	int	total_len;

	dir->negative = (value < 0.0 || (value == -0.0 && 1 / value < 0.0));
	if (value < 0.0 || (value == -0.0 && 1 / value < 0.0))
		value = -value;
	if (value == 1.0 / 0.0)
		return (ft_strdup("inf"));
	if (value != value)
		dir->is_nan = 1;
	if (value != value)
		return (ft_strdup("nan"));
	value = value + rounding(value, precision);
	get_lengths((long) value, precision, &int_len, &total_len);
	str = (char *) malloc(total_len + 1 * sizeof (char));
	if (!str)
		return (NULL);
	str[total_len] = '\0';
	integer_part((long) value, str, dir->negative, int_len);
	if (precision == 0)
		return (str);
	fraction_part(value, str, int_len + 1, precision);
	return (str);
}
