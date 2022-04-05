/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:40:25 by cnysten           #+#    #+#             */
/*   Updated: 2022/04/05 18:14:17 by cnysten          ###   ########.fr       */
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

void	append(t_str *str, const char *src, size_t n)
{
	size_t	available;
	size_t	new_size;
	size_t	srclen;

	if (!str || !src)
		return ;
	available = str->capacity - str->len - 1;
	srclen = ft_strlen(src);
	if (available < srclen)
	{
		new_size = str->capacity + str->capacity / 2;
		if (new_size - str->capacity < srclen - available)
			new_size += srclen - available;
		ft_realloc(str->data, new_size);
		if (!str->data)
			exit(0);
	}
	ft_strncat(str->data, src, n);
	str->len += n;
}

void	free_str(t_str *str)
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
