/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:46:53 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/09 13:55:30 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

/*
static const double	rounding[] = {
	0.5,
	0.05,
	0.005,
	0.0005,
	0.00005,
	0.000005,
	0.0000005,
	0.00000005,
	0.000000005,
	0.0000000005,
	0.00000000005,
	0.000000000005,
	0.0000000000005,
	0.00000000000005,
	0.000000000000005,
	0.0000000000000005,
	0.00000000000000005,
	0.000000000000000005,
	0.0000000000000000005,
	0.00000000000000000005,
	0.000000000000000000005,
	0.0000000000000000000005,
	0.00000000000000000000005
};
*/

static void	integer_part(int value, char *str, int negative, int int_len)
{
	if (negative)
		str[0] = '-';
	else
		int_len--;
	while (value > 9)
	{
		str[int_len--] = '0' + value % 10;
		value = value / 10;
	}
	str[int_len] = '0' + value;
}

static void	fraction_part(double fraction, char *str, int start, int precision)
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

double	bankers_rounding(int precision)
{
	double	rounding;

	rounding = 0.5;
	while (precision--)
		rounding *= 0.1;
	return (rounding);
}

//TODO nan, inf, -inf, -0

char	*ftoa(double value, int precision)
{
	char	*str;
	int		int_len;
	int		total_len;
	int		negative;
	double	fraction;

	int_len = ft_intlen((int) value);
	if (((unsigned int) value & SIGN_32) == SIGN_32)
		negative = 1;
	else
		negative = 0;
	total_len = int_len + precision + negative;
	if (precision > 0)
		total_len++;
	str = (char *) malloc(total_len + 1 * sizeof (char));
	if (!str)
		return (NULL);
	str[total_len] = '\0';
	integer_part((int) value, str, negative, int_len);
	if (precision == 0)
		return (str);
	fraction = value - (int) value + bankers_rounding(precision);
	fraction_part(fraction, str, int_len + negative + 1, precision);
	return (str);
}
