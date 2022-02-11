/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:14:01 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/11 18:50:31 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static char	*get_str(t_dir *dir, va_list *ap)
{
	char	*str;
	int		prefix;

	if (dir->alt_flag)
		prefix = TRUE;
	else
		prefix = FALSE;
	if (dir->length == HH)
		str = itooctal((unsigned char) va_arg(*ap, unsigned int), prefix, dir);
	else if (dir->length == H)
		str = itooctal((unsigned short int) va_arg(*ap, unsigned int), prefix, dir);
	else if (dir->length == L)
		str = itooctal(va_arg(*ap, unsigned long int), prefix, dir);
	else if (dir->length == LL)
		str = itooctal(va_arg(*ap, unsigned long long int), prefix, dir);
	else
		str = itooctal(va_arg(*ap, unsigned int), prefix, dir);
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

void	output_octal(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	str = get_str(dir, ap);
	len = ft_strlen(str);
	if (dir->space_flag)
		write(1, " ", 1);
	if (!dir->minus_flag)
		justify(dir, dir->width - len, ret);
	write(1, str, len);
	*ret += len;
	if (dir->minus_flag)
		justify(dir, dir->width - len, ret);
	free(str);
}

