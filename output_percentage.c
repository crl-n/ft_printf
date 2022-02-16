/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_percentage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:27:11 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/16 16:18:36 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static void	justify(int n, int *ret, t_dir *dir)
{
	char	*str;
	char	c;

	if (n <= 0)
		return ;
	str = ft_strnew(n);
	if (!str)
		exit(1);
	if (dir->zero_flag)
		c = '0';
	else
		c = ' ';
	ft_memset((void *)str, c, n);
	write(1, str, n);
	*ret += n;
	free(str);
}

void	output_percentage(t_dir *dir, va_list *ap, int *ret)
{
	(void) ap;
	if (!dir->minus_flag)
		justify(dir->width - 1, ret, dir);
	write(1, "%", 1);
	*ret += 1;
	if (dir->minus_flag)
		justify(dir->width - 1, ret, dir);
}
