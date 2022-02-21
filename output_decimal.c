/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:13:21 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/21 19:11:52 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static char	*get_str(t_dir *dir, va_list *ap)
{
	char	*str;

	if (dir->length == hh)
		str = itoa((signed char) va_arg(*ap, int), dir);
	else if (dir->length == h)
		str = itoa((signed short int) va_arg(*ap, int), dir);
	else if (dir->length == l)
		str = itoa(va_arg(*ap, long int), dir);
	else if (dir->length == ll)
		str = itoa(va_arg(*ap, long long int), dir);
	else
		str = itoa(va_arg(*ap, int), dir);
	if (!str)
		exit(1);
	return (str);
}

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
	else if (dir->plus_flag)
	{
		write(1, "+", 1);
		*ret += 1;
	}
	else if (dir->space_flag && !dir->negative && !dir->plus_flag)
	{
		write(1, " ", 1);
		*ret += 1;
	}
}

void	output_decimal(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	str = get_str(dir, ap);
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
