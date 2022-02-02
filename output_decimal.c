/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:13:21 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/02 13:56:11 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "../libft/libft.h"

static char	*get_str(t_dir *dir, va_list *ap)
{
	char	*str;

	if (dir->length == HH)
		str = itoa((signed char) va_arg(*ap, int), dir);
	else if (dir->length == H)
		str = itoa((signed short int) va_arg(*ap, int), dir);
	else if (dir->length == L)
		str = itoa(va_arg(*ap, long int), dir);
	else if (dir->length == LL)
		str = itoa(va_arg(*ap, long long int), dir);
	else
		str = itoa(va_arg(*ap, int), dir);
	if (!str)
		exit(1);
	return (str);
}

void	output_decimal(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	str = get_str(dir, ap);
	len = ft_strlen(str);
	write(1, str, len);
	*ret += len;
	free(str);
}
