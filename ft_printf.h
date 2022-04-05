/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:48:48 by cnysten           #+#    #+#             */
/*   Updated: 2022/04/05 22:15:19 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Includes */
# include "libft.h"
# include <stdarg.h>

/* Conversion enum*/
enum	e_conv	
{
	no_conv,
	character,
	string,
	pointer,
	decimal,
	integer,
	octal,
	uinteger,
	hex_lower,
	hex_upper,
	floating,
	bit,
	percentage
};

/* Length enum */
enum e_len
{
	no_len,
	l,
	ll,
	h,
	hh,
	L
};

/* Case enum*/
enum e_case
{
	lower,
	upper
};

/* Boolean enum */
enum e_bool
{
	false,
	true
};

/* String struct */
typedef struct	s_str
{
	char	*data;
	size_t	len;
	size_t	capacity;
}	t_str;

/* Format struct */
typedef struct	s_fmt
{
	unsigned int	alt : 1;
	unsigned int	zero : 1;
	unsigned int	dash : 1;
	unsigned int	space : 1;
	unsigned int	plus : 1;
	int				precision;
	int				width;
	enum e_len		len;
	enum e_conv		conversion;
}

/* Typedef for dispatch table */
typedef void	(*t_converter)(t_str *output, t_fmt fmt, va_list *ap);

/* Prototypes */
int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_sprintf(char *str, const char *format, ...);

int		is_flag(const char c);
int		is_width(const char c);
int		is_conversion(const char c);
int		is_precision(const char c);
int		is_length(const char c);

t_fmt	get_fmt(const char *format);

void	append(t_str *str, const char *src);
t_str	*new_str(size_t	capacity);
void	free_str(t_str	*str);

void	output_none(t_str *output, t_fmt fmt, va_list *ap);
void	output_char(t_str *output, t_fmt fmt, va_list *ap);
void	output_string(t_str *output, t_fmt fmt, va_list *ap);
void	output_pointer(t_str *output, t_fmt fmt, va_list *ap);
void	output_decimal(t_str *output, t_fmt fmt, va_list *ap);
void	output_octal(t_str *output, t_fmt fmt, va_list *ap);
void	output_unsigned(t_str *output, t_fmt fmt, va_list *ap);
void	output_hex(t_str *output, t_fmt fmt, va_list *ap);
void	output_float(t_str *output, t_fmt fmt, va_list *ap);
void	output_bit(t_str *output, t_fmt fmt, va_list *ap);
void	output_percentage(t_str *output, t_fmt fmt, va_list *ap);

#endif
