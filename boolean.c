/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:53:56 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/01 21:31:07 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Boolean functions used in parsing the format string */

int	is_flag(const char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+' || c == '\'')
		return (1);
	return (0);
}

int	is_conversion(const char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'o' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'f' || c == 'b'
		|| c == '%')
		return (1);
	return (0);
}

int	is_precision(const char c)
{
	if (c == '.')
		return (1);
	return (0);
}

int	is_length(const char c)
{
	if (c == 'l' || c == 'h' || c == 'L')
		return (1);
	return (0);
}
