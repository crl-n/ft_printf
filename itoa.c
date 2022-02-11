/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:07:48 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/11 19:13:29 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>

static int	get_size(long long n, t_dir *dir)
{
	int	size;

	size = 0;
	if (n == 0)
		size = 1;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	if (dir->precision >= 0 && dir->precision > size)
		size = dir->precision;
	else if (dir->zero_flag && size < dir->width)
	{
		size = dir->width;
		if (dir->negative || ((dir->plus_flag || dir->space_flag) && !dir->negative))
			size--;
	}
	return (size + 1);
}

static long long	handle_negative(long long n, t_dir *dir)
{
	if (n < 0)
	{
		dir->negative = 1;
		n = -n;
	}
	return (n);
}

char	*itoa(long long n, t_dir *dir)
{
	char	*s;
	int		size;

	if (dir->precision == 0 && n == 0)
		return (ft_strdup(""));
	if (n < -9223372036854775807LL)
		return ft_strdup("-9223372036854775808");
	n = handle_negative(n, dir);
	size = get_size(n, dir);
	s = (char *) malloc(size * sizeof (char));
	if (!s)
		return (NULL);
	s[--size] = '\0';
	while (size > 0)
	{
		s[--size] = '0' + (n % 10);
		n = n / 10;
	}
	return (s);
}
