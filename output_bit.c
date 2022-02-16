/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:16:31 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/16 17:13:27 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static void	justify(int n, int *ret)
{
	char	*str;

	if (n <= 0)
		return ;
	str = ft_strnew(n);
	if (!str)
		exit(1);
	ft_memset((void *)str, ' ', n);
	write(1, str, n);
	*ret += n;
	free(str);
}

void	output_bit(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	str = ft_itoa_base(va_arg(*ap, long), 2);
	if (!str)
		exit(1);
	len = ft_strlen(str);
	if (!dir->minus_flag)
		justify(dir->width - len, ret);
	write(1, "0b", 2);
	write(1, str, len);
	*ret += len + 2;
	if (dir->minus_flag)
		justify(dir->width - len, ret);
	free(str);
}
