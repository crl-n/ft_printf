/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itohex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:35:02 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/27 21:28:39 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>

/* get_char() converts an int into a corresponding digit of its base */

static size_t	uintlen_hex(unsigned long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

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

char	*itohex(unsigned long value, const int letter_case, const int prefix)
{
	char	*str;
	size_t	size;

	size = uintlen_hex(value) + 1;
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
