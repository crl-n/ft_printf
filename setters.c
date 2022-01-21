#include "ft_printf.h"

/*
 * There can be zero or more of the flags: #0- +'
 */

void	set_flag(const char c, t_directive *dir) // bonus flags missing
{
	if (c == '#')
		dir->flags = dir->flags | ALT;
	if (c == '0')
		dir->flags = dir->flags | ZERO;
	if (c == '-')
		dir->flags = dir->flags | MINUS;
	if (c == ' ')
		dir->flags = dir->flags | SPACE;
	if (c == '+')
		dir->flags = dir->flags | PLUS;
	if (c == '\'')
		dir->flags = dir->flags | SEP;
}

/*
 * Valid conversion specifiers: diouxX, csp, f (and b as a bonus)
 */

void	set_conversion(const char format, t_directive *dir)
{
	if (format == 'c')
		dir->conversion = CHAR;
	if (format == 's')
		dir->conversion = STRING;
	if (format == 'p')
		dir->conversion = POINTER;
	if (format == 'd')
		dir->conversion = DECIMAL;
	if (format == 'i')
		dir->conversion = INTEGER;
	if (format == 'o')
		dir->conversion = OCTAL;
	if (format == 'u')
		dir->conversion = UNSIGNED;
	if (format == 'x')
		dir->conversion = HEX_LOWER;
	if (format == 'X')
		dir->conversion = HEX_UPPER;
	if (format == 'f')
		dir->conversion = FLOAT;
	if (format == 'b')
		dir->conversion = BIT;
}

void	set_width(const char *format, t_directive *dir)
{
	dir->width = ft_atoi(format);
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
