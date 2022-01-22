#include "ft_printf.h"

/*
 * There can be zero or more of the flags: #0- +'
 */

void	set_flag(const char **format, t_directive *dir, t_parser_stage *stage) // bonus flags missing
{
	char	c;

	c = **format;
	if (c == '#')
		dir->flags = dir->flags | ALT;
	else if (c == '0')
		dir->flags = dir->flags | ZERO;
	else if (c == '-')
		dir->flags = dir->flags | MINUS;
	else if (c == ' ')
		dir->flags = dir->flags | SPACE;
	else if (c == '+')
		dir->flags = dir->flags | PLUS;
	else if (c == '\'')
		dir->flags = dir->flags | SEP;
	*format = *format + 1;
	*stage = FLAG;
}

/*
 * Valid conversion specifiers: diouxX, csp, f (and b as a bonus)
 */

void	set_conversion(const char format, t_directive *dir)
{
	if (format == 'c')
		dir->conversion = CHAR;
	else if (format == 's')
		dir->conversion = STRING;
	else if (format == 'p')
		dir->conversion = POINTER;
	else if (format == 'd')
		dir->conversion = DECIMAL;
	else if (format == 'i')
		dir->conversion = INTEGER;
	else if (format == 'o')
		dir->conversion = OCTAL;
	else if (format == 'u')
		dir->conversion = UNSIGNED;
	else if (format == 'x')
		dir->conversion = HEX_LOWER;
	else if (format == 'X')
		dir->conversion = HEX_UPPER;
	else if (format == 'f')
		dir->conversion = FLOAT;
	else if (format == 'b')
		dir->conversion = BIT;
}

void	set_width(const char **format, t_directive *dir, t_parser_stage *stage)
{
	dir->width = ft_atoi(*format);
	*format = *format + ft_intlen(dir->width);
	*stage = WIDTH;
}

void	set_precision(const char *format, t_directive *dir)
{
	dir->precision = ft_atoi(format + 1);
}

void	set_length(const char *format, t_directive *dir)
{
	if (*format == 'l' && *(format + 1) == 'l')
		dir->length = LL;
	if (*format == 'h' && *(format + 1) == 'h')
		dir->length = HH;
	if (*format == 'l')
		dir->length = L;
	if (*format == 'h')
		dir->length = H;
}
