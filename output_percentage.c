/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_percentage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:27:11 by carlnysten        #+#    #+#             */
/*   Updated: 2022/04/05 22:33:44 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

void	output_percentage(t_str *output, t_fmt fmt, va_list *ap)
{
	(void) fmt;
	(void) ap;
	append(output, "%", 1);
}
