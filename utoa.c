/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:57:15 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/11 19:15:56 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"

static int	uint_len(unsigned long int n, t_dir *dir)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	if (dir->precision >= 0 && dir->precision > len)
		len = dir->precision;
	return (len);
}

char	*utoa(unsigned long int n, t_dir *dir)
{
	char	*s;
	int		size;

	if (dir->precision == 0 && n == 0)
		return (ft_strdup(""));
	size = uint_len(n, dir) + 1;
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
