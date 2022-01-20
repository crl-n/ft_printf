
/*
 * The format string follows this formula:
 *
 * 		%[flag][width][.precision][length]specifier
 *
 * parse_format() parses the format string and extracts the contained directive.
 */

//TODO: test with width AND precision
void	parse_format(const char *format, t_list **dir_list)
{
	t_directive	*dir;

	dir = NULL;
	while (*format)
	{
		if (*format == '%')
		{
			dir = new_directive();
			while (*format)
			{
				if (is_flag(*format))
					set_flag(*format, dir);
				if (ft_isdigit(*format)) // RIGHTERNMOST number is used unless it is 0
					set_width(format, dir); // format needs to be forwarded as many steps as there are digits
				if (is_precision(*format))
					set_precision(format, dir); // format needs to be forwarded as many steps as there are digits + 1
				if (is_length(*format))
					set_length(format, dir);
				if (is_conversion(*format))
					set_conversion(*format, dir);
				format++;
			}
			ft_lstadd_back(dir_list, ft_lstnew((void *)dir, sizeof (t_directive *)));
		}
		format++;
	}
}
