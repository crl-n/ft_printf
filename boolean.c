/* Boolean functions used in parsing the format string */

int	is_flag(const char c) // bonus flags missing
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+' || c == '\'')
		return (1);
	return (0);
}

int	is_conversion(const char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'o' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'f' || c == 'b')
		return (1);
	return (0);
}

/* Should is_precision() check that a number follows the dot? */
int	is_precision(const char c)
{
	if (c == '.')
		return (1);
	return (0);
}

int	is_length(const char c)
{
	if (c == 'l' || c == 'h')
		return (1);
	return (0);
}
