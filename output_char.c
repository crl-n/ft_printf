/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:01:32 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/03 10:07:28 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "../libft/libft.h"

static void	justify(int	c, int n, int *ret)
{
	char	*str;

	if (n <= 0)
		return ;
	str = ft_strnew(n);
	if (!str)
		exit(1);
	ft_memset((void *)str, c, n);
	write(1, str, n);
	*ret += n;
	free(str);
}

void	output_char(t_dir *dir, va_list *ap, int *ret)
{
	int	arg;

	arg = va_arg(*ap, int);
	if (!dir->minus_flag)
		justify(' ', dir->width - 1, ret);
	if (arg == 0)
		write(1, "^@", 2);
	else
		write(1, &arg, 1);
	*ret += 1;
	if (dir->minus_flag)
		justify(' ', dir->width - 1, ret);
}