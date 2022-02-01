/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:52:26 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/01 23:21:19 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "../libft/libft.h"

char	*as_char(t_dir *dir, va_list *ap)
{
	char	*str;
	int		arg;

	(void) dir;
	arg = va_arg(*ap, int);
	if (arg == 0)
	{
		dir->null_char = 1;
		return (ft_strdup("^@"));
	}
	str = ft_strnew(1);
	if (!str)
		exit(1);
	str[0] = arg;
	return (str);
}

char	*as_string(t_dir *dir, va_list *ap)
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

char	*as_pointer(t_dir *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	str = itohex(va_arg(*ap, unsigned long), LOWERCASE, TRUE, dir);
	if (!str)
		exit(1);
	return (str);
}
