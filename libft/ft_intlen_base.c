/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:21:35 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/27 09:21:42 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen_base(int value, int base)
{
	size_t	len;

	len = 0;
	if (value == 0)
		return (1);
	if (base == 10 && value < 0)
	{
		value = -value;
		len++;
	}
	while (value > 0)
	{
		value = value / base;
		len++;
	}
	return (len);
}
