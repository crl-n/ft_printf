/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:07:48 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/02 20:07:20 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>

static int	get_size(long n, t_dir *dir)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	if ((dir->flags & ZERO) == ZERO && size < dir->width)
		size = dir->width + 1;
	if (dir->precision >= 0 && size > dir->precision)
		size = dir->precision + 1;
	return (size + 1);
}

static long	handle_negative(long n, int *sign)
{
	if (n < 0)
	{
		*sign = -1;
		n = -n;
	}
	return (n);
}

char	*itoa(long n, t_dir *dir)
{
	char	*s;
	int		size;
	int		sign;

	size = get_size(n, dir);
	sign = 1;
	n = handle_negative(n, &sign);
	s = (char *) malloc(size * sizeof (char));
	if (!s)
		return (NULL);
	s[--size] = '\0';
	while (size > 0)
	{
		s[--size] = '0' + (n % 10);
		n = n / 10;
	}
	if (sign == -1)
		s[0] = '-';
	return (s);
}
