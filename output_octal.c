/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:14:01 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/16 17:02:05 by cnysten          ###   ########.fr       */
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

	prefix = FALSE;
	if (dir->alt_flag)
		prefix = TRUE;
	if (dir->length == HH)
	{
		value = va_arg(*ap, unsigned int);
		return (itooctal((unsigned char) value, prefix, dir));
	}
	else if (dir->length == H)
	{
		value = va_arg(*ap, unsigned int);
		return (itooctal((unsigned short int) value, prefix, dir));
	}
	else if (dir->length == L)
		return (itooctal(va_arg(*ap, unsigned long int), prefix, dir));
	else if (dir->length == LL)
		return (itooctal(va_arg(*ap, unsigned long long int), prefix, dir));
	else
		return (itooctal(va_arg(*ap, unsigned int), prefix, dir));
}

static void	justify(t_dir *dir, int n, int *ret)
{
	char	c;
	char	*str;

	if (n <= 0)
		return ;
	str = ft_strnew(n);
	if (!str)
		exit(1);
	if (dir->zero_flag)
		c = '0';
	else
		c = ' ';
	ft_memset((void *)str, c, n);
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
		justify(dir, dir->width - len, ret);
	write(1, str, len);
	*ret += len;
	if (dir->minus_flag)
		justify(dir, dir->width - len, ret);
	free(str);
}
