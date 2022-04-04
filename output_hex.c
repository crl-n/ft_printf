/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:15:14 by carlnysten        #+#    #+#             */
/*   Updated: 2022/04/04 22:52:41 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

static char	*get_str(t_dir *dir, va_list *ap)
{
	char			*str;
	int				letter_case;
	int				prefix;
	unsigned long	arg;

	if (dir->length == hh)
		arg = (unsigned char) va_arg(*ap, unsigned int);
	else if (dir->length == h)
		arg = (unsigned short int) va_arg(*ap, unsigned int);
	else if (dir->length == l)
		arg = va_arg(*ap, unsigned long int);
	else if (dir->length == ll)
		arg = va_arg(*ap, unsigned long long int);
	else
		arg = va_arg(*ap, unsigned int);
	letter_case = lower;
	if (dir->conversion == hex_upper)
		letter_case = upper;
	prefix = false;
	if (dir->alt_flag && arg != 0)
		prefix = true;
	str = itohex(arg, letter_case, prefix, dir);
	if (!str)
		exit(1);
	return (str);
}

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

void	output_hex(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	str = get_str(dir, ap);
	len = ft_strlen(str);
	if (!dir->minus_flag)
		justify(dir->width - len, ret);
	write(fd, str, len);
	*ret += len;
	if (dir->minus_flag)
		justify(dir->width - len, ret);
	free(str);
}
