/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:56:23 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/01 18:57:10 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "../libft/libft.h"

char	*as_float(t_dir *dir, va_list *ap)
{
	char	*str;

	str = ftoa(va_arg(*ap, double), dir->precision);
	if (!str)
		exit(1);
	return (str);
}

char	*as_bit(t_dir *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	str = ft_itoa_base(va_arg(*ap, long), 2);
	if (!str)
		exit(1);
	return (str);
}
