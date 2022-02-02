/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:14:42 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/02 13:52:02 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "../libft/libft.h"

static char	*get_str(t_dir *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	if (dir->length == HH)
		str = utoa((unsigned char) va_arg(*ap, unsigned int));
	else if (dir->length == H)
		str = utoa((unsigned short int) va_arg(*ap, unsigned int));
	else if (dir->length == L)
		str = utoa(va_arg(*ap, unsigned long int));
	else if (dir->length == LL)
		str = utoa(va_arg(*ap, unsigned long long int));
	else
		str = utoa(va_arg(*ap, unsigned int));
	if (!str)
		exit(1);
	return (str);
}

void	output_unsigned(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	str = get_str(dir, ap);
	len = ft_strlen(str);
	*ret += len;
	free(str);
}
