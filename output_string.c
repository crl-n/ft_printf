/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:02:10 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/02 19:09:50 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "../libft/libft.h"

static void	justify(int n, int *ret)
{
	char	*str;

	if (n <= 0)
		return ;
	str = ft_strnew(n);
	if (!str)
		exit(1);
	ft_memset((void *)str, ' ', n);
	write(1, str, n);
	*ret += n;
	free(str);
}

static char	*get_str(t_dir *dir, va_list *ap)
{
	char	*str;
	char	*arg;

	(void) dir;
	arg = va_arg(*ap, char *);
	if (arg == NULL)
		str = ft_strdup("(null)");
	else if (dir->precision != -1)
		str = ft_strndup(arg, dir->precision);
	else
		str = ft_strdup(arg);
	if (!str)
		exit(1);
	return (str);
}

void	output_string(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	str = get_str(dir, ap);
	len = ft_strlen(str);
	if ((dir->flags & MINUS) != MINUS)
		justify(dir->width - len, ret);
	write(1, str, len);
	*ret += len;
	if ((dir->flags & MINUS) == MINUS)
		justify(dir->width - len, ret);
	free(str);
}
