/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 09:50:19 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/14 15:03:40 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static t_dir	*new_directive(void)
{
	t_dir	*dir;

	dir = (t_dir *) malloc(sizeof (t_dir));
	if (!dir)
		return (NULL);
	ft_bzero(dir, sizeof (t_dir));
	dir->precision = -1;
	dir->start_i = -1;
	dir->end_i = -1;
	return (dir);
}

static void	parse_directions(const char **format_adr,
								const char *start,
								t_dir *dir,
								t_stage *stage)
{
	const char	*format;

	format = *format_adr;
	while (*format)
	{
		if (*stage == FLAG && is_flag(*format))
		{
			set_flag(&format, dir, stage);
			continue ;
		}
		if (*stage <= WIDTH && is_width(*format))
			set_width(&format, dir, stage);
		if (*stage <= PRECISION && is_precision(*format))
			set_precision(&format, dir, stage);
		if (*stage <= LENGTH && is_length(*format))
			set_length(&format, dir);
		if (is_conversion(*format))
		{
			set_conversion(*format, dir);
			dir->end_i = (int)(format - start);
			break ;
		}
		format++;
	}
	*format_adr = format;
}

/*
 * The format string follows this formula:
 *
 * 		%[flag][width][.precision][length]conversion specifier
 *
 * parse_format() parses the format string and extracts the contained directive.
 */

//TODO: test with width AND precision
int	parse_format(const char *format, t_list **dir_list)
{
	t_dir		*dir;
	t_stage		stage;
	const char	*start;

	start = format;
	while (*format)
	{
		stage = 0;
		if (*format == '%')
		{
			dir = new_directive();
			dir->start_i = (int)(format - start);
			format++;
			parse_directions(&format, start, dir, &stage);
			ft_lstadd_back(dir_list, ft_lstnew((void *)dir, sizeof (t_dir)));
			free(dir);
		}
		if (*format == '\0')
			break ;
		format++;
	}
	return (0);
}
