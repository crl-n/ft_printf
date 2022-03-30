/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:14:01 by carlnysten        #+#    #+#             */
/*   Updated: 2022/03/31 00:10:00 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static char	*get_str(t_dir *dir, va_list *ap)
{
	int				prefix;
	unsigned int	value;

	prefix = false;
	if (dir->alt_flag)
		prefix = true;
	if (dir->length == hh)
	{
		value = va_arg(*ap, unsigned int);
		return (itooctal((unsigned char) value, prefix, dir));
	}
	else if (dir->length == h)
	{
		value = va_arg(*ap, unsigned int);
		return (itooctal((unsigned short int) value, prefix, dir));
	}
	else if (dir->length == l)
		return (itooctal(va_arg(*ap, unsigned long int), prefix, dir));
	else if (dir->length == ll)
		return (itooctal(va_arg(*ap, unsigned long long int), prefix, dir));
	else
		return (itooctal(va_arg(*ap, unsigned int), prefix, dir));
}

static void	justify(int n, int *ret)
{
	char	*str;

	if (n <= 0)
		return ;
	str = ft_strnew(n);
	if (!str)
		exit(1);
	ft_memset((void *)str, ' ', n);
	write(1, str, n);
	*ret += n;
	free(str);
}

void	output_octal(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	str = get_str(dir, ap);
	len = ft_strlen(str);
	if (!dir->minus_flag)
		justify(dir->width - len, ret);
	write(1, str, len);
	*ret += len;
	if (dir->minus_flag)
		justify(dir->width - len, ret);
	free(str);
}
