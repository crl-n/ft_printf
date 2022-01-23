/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:46:53 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/23 20:53:56 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	float_len(float value)
{
	return (ft_intlen((int)(value & MANTISSA_32)) + 1);
}

char	*ftoa(float value)
{
	char	*str;
	int		len;

	len = float_len(value);
	if ((value & SIGN_32) == SIGN_32)
		len++;
	str = (char *) malloc((len + 1) * sizeof (char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
}
