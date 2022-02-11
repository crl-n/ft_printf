/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:02:41 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/11 18:59:23 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static void	justify(t_dir *dir, int n, int *ret)
{
	char	c;
	char	*str;

	if (n <= 0)
		return ;
	str = ft_strnew(n);
	if (!str)
		exit(1);
	if (dir->zero_flag)
		c = '0';
	else
		c = ' ';
	if (dir->space_flag)
		n--;
	ft_memset((void *)str, c, n);
	write(1, str, n);
	*ret += n;
	free(str);
}

void	output_pointer(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	(void) dir;
	str = itohex(va_arg(*ap, unsigned long), LOWERCASE, TRUE, dir);
	if (!str)
		exit(1);
	len = ft_strlen(str);
	if (!dir->minus_flag)
		justify(dir, dir->width - len, ret);
	write(1, str, len);
	*ret += len;
	if (dir->minus_flag)
		justify(dir, dir->width - len, ret);
	free(str);
}
