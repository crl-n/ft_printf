/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:16:31 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/11 16:54:02 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

void	output_bit(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	(void) dir;
	str = ft_itoa_base(va_arg(*ap, long), 2);
	if (!str)
		exit(1);
	len = ft_strlen(str);
	write(1, str, len);
	*ret += len;
}
