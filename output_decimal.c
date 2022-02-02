/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:13:21 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/02 21:10:13 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "../libft/libft.h"

static char	*get_str(t_dir *dir, va_list *ap)
{
	char	*str;

	if (dir->length == HH)
		str = itoa((signed char) va_arg(*ap, int), dir);
	else if (dir->length == H)
		str = itoa((signed short int) va_arg(*ap, int), dir);
	else if (dir->length == L)
		str = itoa(va_arg(*ap, long int), dir);
	else if (dir->length == LL)
		str = itoa(va_arg(*ap, long long int), dir);
	else
		str = itoa(va_arg(*ap, int), dir);
	if (!str)
		exit(1);
	return (str);
}

static void	justify(t_dir *dir, int n, int *ret)
{
	char	c;
	char	*str;

	if (n <= 0)
		return ;
	str = ft_strnew(n);
	if (!str)
		exit(1);
	if ((dir->flags & ZERO) == ZERO)
		c = '0';
	else
		c = ' ';
	if ((dir->flags & (SPACE & PLUS)) == SPACE)
		n--;
	ft_memset((void *)str, c, n);
	write(1, str, n);
	*ret += n;
	free(str);
}

static void	handle_sign(t_dir *dir, char *str, int *ret)
{
	if (str[0] == '-')
		dir->negative = 1;
	if (dir->negative == 0 && (dir->flags & PLUS) == PLUS)
	{
		write(1, "+", 1);
		*ret += 1;
	}
}

void	output_decimal(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	str = get_str(dir, ap);
	len = ft_strlen(str);
	handle_sign(dir, str, ret);
	if ((dir->flags & SPACE) == SPACE 
			&& !dir->negative
			&& (dir->flags & PLUS) != PLUS)
	{
		write(1, " ", 1);
		*ret += 1;
	}
	if ((dir->flags & MINUS) != MINUS)
		justify(dir, dir->width - len, ret);
	write(1, str, len);
	*ret += len;
	if ((dir->flags & MINUS) == MINUS)
		justify(dir, dir->width - len, ret);
	free(str);
}
