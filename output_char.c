/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:01:32 by carlnysten        #+#    #+#             */
/*   Updated: 2022/04/05 22:43:18 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	output_char(t_str *output, t_fmt fmt, va_list *ap)
{
	char	c;

	(void) fmt;
	c = va_arg(*ap, int);
	append(output, &c, 1);
}
