/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:07:37 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/27 09:53:43 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ptoa(unsigned long p)
{
	char			*a;
	size_t			i;
	unsigned long	rem;

	a = (char *) malloc(15);
	if (!a)
		return (NULL);
	i = 14;
	a[i--] = '\0';
	while (p > 0)
	{
		rem = p % 16;
		if (rem > 9)
			a[i] = 'a' + rem - 10;
		else
			a[i] = '0' + rem;
		p = p / 16;
		i--;
	}
	while (i < 1)
		a[i--] = '0';
	a[0] = '0';
	a[1] = 'x';
	return (a);
}
