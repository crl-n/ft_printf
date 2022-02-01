/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 22:01:53 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/01 23:04:01 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../libft/libft.h"

static void	justify(t_dir *dir, size_t n, int *ret)
{
	char	c;
	char	*str;

	str = ft_strnew(n);
	if (!str)
		exit(1);
	if ((dir->flags & ZERO) == ZERO)
		c = '0';
	else
		c = ' ';
	if ((dir->flags & SPACE) == SPACE)
		n--;
	ft_memset((void *)str, c, n);
	write(1, str, n);
	*ret += n;
	free(str);
}

static void	handle_space_flag(t_dir *dir, int *ret)
{
	if ((dir->flags & SPACE) == SPACE
			&& ((dir->flags & PLUS) == 0 || dir->negative == 1)
			&& (dir->conversion == DECIMAL
			|| dir->conversion == INTEGER
			|| dir->conversion == FLOAT))
	{
		write(1, " ", 1);
		*ret += 1;
	}
}

static void	handle_negative(t_dir *dir, char *str, int *ret)
{
	int	negative;

	negative = 0;
	if ((dir->conversion == DECIMAL
		|| dir->conversion == INTEGER)
		&& str[0] == '-')
		negative = 1;
	if (dir->negative == 0 && (dir->flags & PLUS) == PLUS)
	{
		write(1, "+", 1);
		*ret += 1;
	}
}

void	put_arg(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	str = convert(dir, ap);
	len = ft_strlen(str);
	handle_space_flag(dir, ret);
	if (dir->width > len - (int) dir->null_char && (dir->flags & MINUS) != MINUS)
		justify(dir, dir->width - len + dir->null_char, ret);
	handle_negative(dir, str, ret);
	write(1, str, len);
	*ret = *ret + len - dir->null_char;
	if (dir->width > len - (int) dir->null_char && (dir->flags & MINUS) == MINUS)
		justify(dir, dir->width - len + dir->null_char, ret);
	free(str);
	free(dir);
}
