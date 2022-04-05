/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:48:48 by cnysten           #+#    #+#             */
/*   Updated: 2022/04/05 17:49:45 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Includes */
# include "libft.h"
# include <stdarg.h>

/* String struct */
typedef struct	s_str
{
	char	*data;
	size_t	len;
	size_t	capacity;
}	t_str;

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

/* Typedef for dispatch table */
typedef void	(*t_converter)(const char *format, va_list *ap);

/* Prototypes */
int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_sprintf(char *str, const char *format, ...);

int		is_flag(const char c);
int		is_width(const char c);
int		is_conversion(const char c);
int		is_precision(const char c);
int		is_length(const char c);

t_str	*new_str(size_t	capacity);
void	free_str(t_str	*str);

/*
char	*itoa(long long n, t_dir *dir);
char	*ftoa(long double value, int precision, t_dir *dir, char *str);
char	*itohex(unsigned long n,
			const int letter_case,
			const int prefix,
			t_dir *dir);
char	*itooctal(unsigned long n, const int prefix, t_dir *dir);
char	*ptoa(unsigned long p);
char	*utoa(unsigned long int n, t_dir *dir);
*/

void	output_none(char *format, va_list *ap);
void	output_char(char *format, va_list *ap);
void	output_string(char *format, va_list *ap);
void	output_pointer(char *format, va_list *ap);
void	output_decimal(char *format, va_list *ap);
void	output_octal(char *format, va_list *ap);
void	output_unsigned(char *format, va_list *ap);
void	output_hex(char *format, va_list *ap);
void	output_float(char *format, va_list *ap);
void	output_bit(char *format, va_list *ap);
void	output_percentage(char *format, va_list *ap);

#endif
