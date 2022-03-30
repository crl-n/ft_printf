/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itooctal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:57:15 by cnysten           #+#    #+#             */
/*   Updated: 2022/03/31 00:20:02 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"
#include "libft.h"

static size_t	octal_len(unsigned long n, t_dir *dir, const int prefix)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (prefix && n != 0)
		len++;
	while (n > 0)
	{
		n = n / 8;
		len++;
	}
	if (len < dir->precision)
		len = dir->precision;
	else if (dir->zero_flag && len < dir->width && dir->precision == -1)
	{
		len = dir->width;
		if (dir->plus_flag || dir->space_flag)
			len--;
	}
	return (len);
}

char	*itooctal(unsigned long n, const int prefix, t_dir *dir)
{
	char	*str;
	int		size;

	if (n == 0 && dir->precision == 0 && dir->alt_flag)
		dir->precision = 1;
	else if (dir->precision == 0 && dir->alt_flag)
		dir->precision = ft_intlen_base(n, 8) + 1;
	if (dir->precision == 0 && n == 0)
		return (ft_strdup(""));
	size = octal_len(n, dir, prefix) + 1;
	str = (char *) malloc(size * sizeof (char));
	if (!str)
		return (NULL);
	str[--size] = '\0';
	while (size > 0 + prefix)
	{
		str[--size] = '0' + (n % 8);
		n = n / 8;
	}
	if (prefix)
		str[0] = '0';
	return (str);
}
