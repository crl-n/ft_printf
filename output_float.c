/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:15:57 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/03 10:08:42 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "../libft/libft.h"

void	output_float(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	if (dir->precision == -1)
		dir->precision = 6;
	str = ftoa(va_arg(*ap, double), dir->precision);
	if (!str)
		exit(1);
	len = ft_strlen(str);
	if (dir->space_flag)
	{
		write(1, " ", 1);
		*ret += 1;
	}
	write(1, str, len);
	*ret += len;
	free(str);
}
