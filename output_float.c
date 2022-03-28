/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:15:57 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/28 22:00:02 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static void	justify(t_dir *dir, int n, int *ret)
{
	char	*str;

	if (n <= 0)
		return ;
	str = ft_strnew(n);
	if (!str)
		exit(1);
	if (dir->negative)
		n--;
	else if (dir->plus_flag)
		n--;
	else if (dir->space_flag && !dir->negative && !dir->plus_flag)
		n--;
	ft_memset((void *)str, ' ', n);
	write(1, str, n);
	*ret += n;
	free(str);
}

static void	handle_sign(t_dir *dir, int *ret)
{
	if (dir->negative)
	{
		write(1, "-", 1);
		*ret += 1;
	}
	else if (dir->plus_flag && !dir->is_nan)
	{
		write(1, "+", 1);
		*ret += 1;
	}
	else if (dir->space_flag && !dir->negative
		&& !dir->plus_flag && !dir->is_nan)
	{
		write(1, " ", 1);
		*ret += 1;
	}
}

void	output_float(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	if (dir->precision == -1 && !dir->precision_from_arg)
		dir->precision = 6;
	if (dir->length == L)
		str = ftoa(va_arg(*ap, long double), dir->precision, dir, NULL);
	else
		str = ftoa(va_arg(*ap, double), dir->precision, dir, NULL);
	if (!str)
		exit(1);
	len = ft_strlen(str);
	if (!dir->minus_flag)
		justify(dir, dir->width - len, ret);
	handle_sign(dir, ret);
	write(1, str, len);
	*ret += len;
	if (dir->minus_flag)
		justify(dir, dir->width - len, ret);
	free(str);
}
