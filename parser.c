#include "../libft/libft.h"
#include "ft_printf.h"

static void	parse_directions(const char **format_adr, t_directive *dir)
{
	const char	*format;

	format = *format_adr;
	while (*format)
	{
		if (dir->width == 0 && is_flag(*format))
			set_flag(*format, dir);
		if (dir->precision == 0 && ft_isdigit(*format)) // RIGHTERNMOST number is used unless it is 0
			set_width(format, dir); // format needs to be forwarded as many steps as there are digits
		if (dir->length == 0 && is_precision(*format))
			set_precision(format, dir); // format needs to be forwarded as many steps as there are digits + 1
		if (is_length(*format))
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
	t_directive	*dir;
	int			ret; // return amount of chars that will not be written?

	dir = NULL;
	ret = 0;
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
			parse_directions(&format, dir);
			ft_lstadd_back(dir_list, ft_lstnew((void *)dir, sizeof (t_directive *)));
		}
		if (*format == '\0')
			break ;
		format++;
	}
	return (ret);
}
