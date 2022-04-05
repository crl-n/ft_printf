/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:16:31 by carlnysten        #+#    #+#             */
/*   Updated: 2022/04/05 17:32:56 by cnysten          ###   ########.fr       */
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
	write(fd, str, n);
	*ret += n;
	free(str);
}

void	output_bit(const char *format, va_list *ap)
{
	char	*nbr;
	int		len;

	nbr = ft_itoa_base(va_arg(*ap, long), 2);
	if (!nbr)
		exit(1); // Die here
	len = ft_strlen(nbr);
	if (!dir->minus_flag)
		justify(dir->width - len, ret);
	write(fd, "0b", 2);
	write(fd, str, len);
	*ret += len + 2;
	if (dir->minus_flag)
		justify(dir->width - len, ret);
	free(str);
}
