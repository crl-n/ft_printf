/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_bit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:16:31 by carlnysten        #+#    #+#             */
/*   Updated: 2022/04/05 22:32:13 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

void	output_bit(t_str *output, t_fmt fmt, va_list *ap)
{
	char	*nbr;

	(void) fmt;
	nbr = ft_itoa_base(va_arg(*ap, long), 2);
	if (!nbr)
		exit(1); // Die here
	append(output, nbr, ft_strlen(nbr));
}
