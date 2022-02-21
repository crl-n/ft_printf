/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itohex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:35:02 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/21 18:53:32 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>

/* get_char() converts an int into a corresponding digit of its base */

static int	get_size(unsigned long n, int prefix, t_dir *dir)
{
	int	size;

	size = 0;
	if (n == 0)
		size = 1;
	while (n > 0)
	{
		n = n / 16;
		size++;
	}
	size++;
	if (dir->precision >= 0 && dir->precision > size)
		size = dir->precision + 1;
	if (prefix == true)
		size += 2;
	if (dir->zero_flag
		&& !dir->minus_flag
		&& size < dir->width
		&& dir->precision == -1)
		size = dir->width + 1;
	return (size);
}

static char	get_hex_char(int n, const int letter_case)
{
	char	c;

	c = (char) n + '0';
	if (c > '9')
	{
		if (letter_case == upper)
			c += 7;
		else
			c += 39;
	}
	return (c);
}

static void	add_prefix(char	*str, const int letter_case)
{
	if (letter_case == upper)
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

char	*itohex(unsigned long value,
				const int letter_case,
				const int prefix,
				t_dir *dir)
{
	char	*str;
	int		size;

	if (dir->precision == 0 && dir->conversion == pointer)
		return (ft_strdup("0x"));
	if (dir->precision == 0)
		return (ft_strdup(""));
	size = get_size(value, prefix, dir);
	str = (char *) malloc(size * sizeof (char));
	if (!str)
		return (NULL);
	str[--size] = '\0';
	while (value >= 16)
	{
		str[--size] = get_hex_char(value % 16, letter_case);
		value = value / 16;
	}
	str[--size] = get_hex_char(value, letter_case);
	while (--size >= 0)
		str[size] = '0';
	if (prefix == true)
		add_prefix(str, letter_case);
	return (str);
}
