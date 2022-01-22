#include "../libft/libft.h"
#include "ft_printf.h"

static void	parse_directions(const char **format_adr, t_directive *dir, t_parser_stage *stage)
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
		if (*stage <= WIDTH && ft_isdigit(*format)) // RIGHTERNMOST number is used unless it is 0
			set_width(&format, dir, stage);
		if (*stage <= PRECISION && is_precision(*format))
			set_precision(format, dir); // format needs to be forwarded as many steps as there are digits + 1
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
 * 		%[flag][width][.precision][length]specifier
 *
 * parse_format() parses the format string and extracts the contained directive.
 */

//TODO: test with width AND precision
int	parse_format(const char *format, t_list **dir_list)
{
	t_directive		*dir;
	t_parser_stage	stage;
	int				ret; // return amount of chars that will not be written?

	dir = NULL;
	ret = 0;
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
			ft_lstadd_back(dir_list, ft_lstnew((void *)dir, sizeof (t_directive *)));
		}
		if (*format == '\0')
			break ;
		format++;
	}
	return (ret);
}
