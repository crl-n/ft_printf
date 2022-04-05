/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:40:25 by cnysten           #+#    #+#             */
/*   Updated: 2022/04/05 17:49:18 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_str	*new_str(size_t	capacity)
{
	t_str	*str;

	str = (t_dir *) malloc(sizeof (t_str));
	if (!str)
		return (NULL);
	ft_bzero(str, sizeof (t_str));
	if (capacity)
	{
		str->data = (char *) malloc(capacity * sizeof (char));
		if (!str->data)
		{
			free(str);
			return (NULL);
		}
		str->capacity = capacity;
	}
	return (str);
}

void	free_str(t_str	*str)
{
	if (!str)
		return ;
	if (str->data)
	{
		ft_bzero(str->data, str->capacity);
		free(str->data);
	}
	ft_bzero(str, sizeof (t_str));
}
