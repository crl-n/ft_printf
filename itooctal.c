/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itooctal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:57:15 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/03 10:16:16 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"

static size_t	octal_len(unsigned int n, t_dir *dir)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 8;
		len++;
	}
	if (len < dir->precision)
		len = dir->precision;
	return (len);
}

char	*itooctal(unsigned long n, const int prefix, t_dir *dir)
{
	char	*str;
	int		size;

	if (dir->precision == 0 && dir->alt_flag)
		return (ft_strdup("0"));
	if (dir->precision == 0)
		return (ft_strdup(""));
	size = octal_len(n, dir) + 1;
	if (prefix)
		size++;
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
