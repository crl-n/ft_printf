/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:29:44 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/03 17:41:22 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/*
*	The prototype for the standard printf is:
*			int	printf(const char * restrict format, ...);
*	Should restrict be omitted like in libft?
*/

size_t	get_argc(char *format)
{
	size_t	argc;

	argc = 0;
	while (*format)
	{
		if (*format == '%')
			argc++;
		format++;
	}
	return (argc);
}

int	ft_printf(const char *format, ...)
{
	size_t	len;
	char	*out;
	va_list	ap;
	char	**args;
	size_t	argc;
	size_t	i;

	len = 0;
	i = 0;
	out = NULL;
	args = NULL;
	argc = get_argc(format);
	args = (char **) malloc(argc * sizeof (char *));
	if (!args)
		return (-1);
	va_start(ap, format);
	while (i < argc)
	{
		args[i] = va_arg(ap, char *);
		i++;
	}
	va_end(ap);
	write(1, out, len);
	return (ret);
}
