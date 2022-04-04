/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:02:41 by carlnysten        #+#    #+#             */
/*   Updated: 2022/04/04 22:52:41 by carlnysten       ###   ########.fr       */
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

void	output_pointer(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	(void) dir;
	str = itohex(va_arg(*ap, unsigned long), lower, true, dir);
	if (!str)
		exit(1);
	len = ft_strlen(str);
	if (!dir->minus_flag)
		justify(dir->width - len, ret);
	write(fd, str, len);
	*ret += len;
	if (dir->minus_flag)
		justify(dir->width - len, ret);
	free(str);
}
