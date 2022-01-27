/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 09:50:19 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/27 10:02:05 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static t_dir	*new_directive(void)
{
	t_dir	*dir;

	dir = (t_dir *) malloc(sizeof (t_dir));
	if (!dir)
		return (NULL);
	ft_bzero(dir, sizeof (t_dir));
	dir->precision = 6;
	return (dir);
}

static void	parse_directions(const char **format_adr,
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
		if (*stage <= WIDTH && ft_isdigit(*format))
			set_width(&format, dir, stage);
		if (*stage <= PRECISION && is_precision(*format))
			set_precision(&format, dir);
		if (*stage <= LENGTH && is_length(*format))
			set_length(format, dir);
		if (is_conversion(*format))
		{
			set_conversion(*format, dir);
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
	t_dir	*dir;
	t_stage	stage;

	stage = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				format++;
				continue ;
			}
			dir = new_directive();
			parse_directions(&format, dir, &stage);
			ft_lstadd_back(dir_list, ft_lstnew((void *)dir, sizeof (t_dir)));
			free(dir);
		}
		if (*format == '\0')
			break ;
		format++;
	}
	return (0);
}
