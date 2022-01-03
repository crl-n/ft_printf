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

#include <string.h> // remove

/*
*	The prototype for the standard printf is:
*			int	printf(const char * restrict format, ...);
*	Should restrict be omitted like in libft?
*/

char	*ptoa(unsigned long p)
{
	char			*a;
	size_t			i;
	unsigned long	rem;

	a = (char *) malloc(15);
	if (!a)
		return (NULL);
	i = 14;
	a[i--] = '\0';
	while (p > 0)
	{
		rem = p % 16;
		if (rem > 9)
			a[i] = 'a' + rem - 10;
		else
			a[i] = '0' + rem;
		p = p / 16;
		i--;
	}
	while (i < 1)
		a[i--] = '0';
	a[0] = '0';
	a[1] = 'x';
	return (a);
}

char	*convert(const char *format, char *arg)
{
	if (*(format + 1) == 's')
		return (arg);
	if (*(format + 1) == 'p')
		return (ptoa((unsigned long) arg));
	return (NULL);
}

int	ft_printf(const char *format, ...)
{
	char	*arg;
	va_list	ap;
	int		ret;

	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '%')
			{
				format++;
				write(1, "%", 1);
				continue ;
			}
			arg = convert(format, va_arg(ap, char *));
			write(1, arg, strlen(arg));
			format = format + 2;
			continue ;
		}
		write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (ret);
}
