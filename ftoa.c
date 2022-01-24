/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:46:53 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/24 21:43:06 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

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

static void	fraction_part(float fraction, char *str, int start, int precision)
{
	int	i;

	i = 0;
	while (i < precision)
	{
		fraction *= 10;
		str[start + i++] = '0' + ((int) fraction % 10);
	}
}

char	*ftoa(float value, int precision)
{
	char	*str;
	int		int_len;
	int		total_len;
	int		negative;

	int_len = ft_intlen((int) value);
	if (((unsigned int) value & SIGN_32) == SIGN_32)
		negative = 1;
	else
		negative = 0;
	total_len = int_len + precision + negative + 1;
	str = (char *) malloc(total_len + 1 * sizeof (char));
	if (!str)
		return (NULL);
	str[total_len] = '\0';
	integer_part((int) value, str, negative, int_len);
	str[int_len + negative] = '.';
	fraction_part(value - (int) value, str, int_len + negative + 1, precision);
	return (str);
}
