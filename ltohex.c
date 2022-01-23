/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltohex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:54:50 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/23 18:56:41 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>

/* get_char() converts an int into a corresponding digit of its base */

static char	get_hex_char(int n, const int letter_case)
{
	char	c;

	c = (char) n + '0';
	if (c > '9')
	{
		if (letter_case == UPPERCASE)
			c += 7;
		else
			c += 39;
	}
	return (c);
}

static void	add_prefix(char	*str, const int letter_case)
{
	if (letter_case == UPPERCASE)
	{
		str[0] = '0';
		str[1] = 'X';
	}
	else
	{
		str[0] = '0';
		str[1] = 'x';
	}
}

char	*ltohex(long value, const int letter_case, const int prefix)
{
	char	*str;
	size_t	size;

	size = ft_intlen_base(value, 16) + 1;
	if (prefix == TRUE)
		size += 2;
	str = (char *) malloc(size * sizeof (char));
	if (!str)
		return (NULL);
	str[--size] = '\0';
	while (value >= 16)
	{
		str[--size] = get_hex_char(value % 16, letter_case);
		value = value / 16;
	}
	str[--size] = value + '0';
	if (prefix == TRUE)
		add_prefix(str, letter_case);
	return (str);
}
