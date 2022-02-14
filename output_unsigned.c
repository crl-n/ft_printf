/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:14:42 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/14 15:45:29 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static char	*get_str(t_dir *dir, va_list *ap)
{
	char	*str;

	if (dir->length == HH)
		str = utoa((unsigned char) va_arg(*ap, unsigned int), dir);
	else if (dir->length == H)
		str = utoa((unsigned short int) va_arg(*ap, unsigned int), dir);
	else if (dir->length == L)
		str = utoa(va_arg(*ap, unsigned long int), dir);
	else if (dir->length == LL)
		str = utoa(va_arg(*ap, unsigned long long int), dir);
	else
		str = utoa(va_arg(*ap, unsigned int), dir);
	if (!str)
		exit(1);
	return (str);
}

static void	justify(t_dir *dir, int n, int *ret)
{
	char	c;
	char	*str;

	c = ' ';
	if (n <= 0)
		return ;
	str = ft_strnew(n);
	if (!str)
		exit(1);
	if (dir->space_flag)
		n--;
	ft_memset((void *)str, c, n);
	write(1, str, n);
	*ret += n;
	free(str);
}

void	output_unsigned(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	str = get_str(dir, ap);
	len = ft_strlen(str);
	if (!dir->minus_flag)
		justify(dir, dir->width - len, ret);
	write(1, str, len);
	*ret += len;
	if (dir->minus_flag)
		justify(dir, dir->width - len, ret);
	free(str);
}
