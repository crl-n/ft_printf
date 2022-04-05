/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:01:32 by carlnysten        #+#    #+#             */
/*   Updated: 2022/04/05 22:12:39 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	output_char(t_str *output, t_fmt fmt, va_list *ap)
{
	int	c;

	c = va_arg(*ap, int);
	/*
	if (!fmt->minus_flag)
		justify(' ', dir->width - 1, ret);
	*/
	append(output, &c, 1);
	/*
	if (dir->minus_flag)
		justify(' ', dir->width - 1, ret);
	*/
}
