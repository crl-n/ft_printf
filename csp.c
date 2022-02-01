/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 18:52:26 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/01 18:52:46 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "../libft/libft.h"

char	*as_char(t_dir *dir, va_list *ap)
{
	char	*str;

	(void) dir;
	str = ft_strnew(1);
	if (!str)
		exit(1);
	str[0] = va_arg(*ap, int);
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
	str = itohex(va_arg(*ap, unsigned long), LOWERCASE, TRUE);
	if (!str)
		exit(1);
	return (str);
}
