/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlnysten <cnysten@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:02:41 by carlnysten        #+#    #+#             */
/*   Updated: 2022/02/02 14:00:41 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "../libft/libft.h"

void	output_pointer(t_dir *dir, va_list *ap, int *ret)
{
	char	*str;
	int		len;

	(void) dir;
	str = itohex(va_arg(*ap, unsigned long), LOWERCASE, TRUE, dir);
	if (!str)
		exit(1);
	len = ft_strlen(str);
	write(1, str, len);
	*ret += len;
	free(str);
}
