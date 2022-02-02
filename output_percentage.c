/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_percentage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:27:11 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/02 13:43:40 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "../libft/libft.h"

static void	justify(int	c, int n)
{
	char	*str;

	if (n <= 0)
		return ;
	str = ft_strnew(n);
	if (!str)
		exit(1);
	ft_memset((void *)str, c, n);
	write(1, str, n);
	free(str);
}

void	output_percentage(t_dir *dir, va_list *ap, int *ret)
{
	(void) dir;
	(void) ap;
	if ((dir->flags & MINUS) != MINUS)
	{
		justify(' ', dir->width - 1);
		*ret += dir->width - 1;
	}
	write(1, "%", 1);
	*ret += 1;
	if ((dir->flags & MINUS) == MINUS)
	{
		justify(' ', dir->width - 1);
		*ret += dir->width - 1;
	}
}
