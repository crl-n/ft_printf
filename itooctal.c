/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itooctal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 16:57:15 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/23 18:31:31 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static size_t	octal_len(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 8;
		len++;
	}
	return (len);
}

char	*itooctal(unsigned int n, const int prefix)
{
	char	*str;
	size_t	size;

	size = octal_len(n) + 1;
	if (prefix)
		size++;
	str = (char *) malloc(size * sizeof (char));
	if (!str)
		return (NULL);
	str[--size] = '\0';
	while (size > (size_t)(0 + prefix))
	{
		str[--size] = '0' + (n % 8);
		n = n / 8;
	}
	if (prefix)
		str[0] = '0';
	return (str);
}
