/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:48:48 by cnysten           #+#    #+#             */
/*   Updated: 2022/04/02 11:29:11 by carlnysten       ###   ########.fr       */
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

/* Parser stage enum */
typedef enum e_stage
{
	flag,
	width,
	precision,
	length,
	conversion
}	t_stage;

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

/* Typedefs and structs */
/* t_dir/s_dir: Struct for directives contained in the format string */
/* t_converter: Function typedef for the dispatch table. */
/* t_stage: Parser stage typedef */

typedef struct s_dir
{
	unsigned int	alt_flag : 1;
	unsigned int	zero_flag : 1;
	unsigned int	plus_flag : 1;
	unsigned int	minus_flag : 1;
	unsigned int	space_flag : 1;
	unsigned int	width_set : 1;
	unsigned int	width_from_arg : 1;
	unsigned int	precision_from_arg : 1;
	unsigned int	is_nan : 1;
	enum e_len		length : 3;
	enum e_conv		conversion : 4;
	enum e_bool		negative : 1;
	int				width;
	int				precision;
}	t_dir;

/* Typedef for dispatch table */
typedef void	(*t_converter)(t_dir *dir, va_list *ap, int *ret);

/* Prototypes */
int		ft_printf(const char *format, ...);
int		parse_format(const char *format, t_list **dir_list);
void	put_arg(t_dir *dir, va_list *ap, int *ret);

int		is_flag(const char c);
int		is_width(const char c);
int		is_conversion(const char c);
int		is_precision(const char c);
int		is_length(const char c);

char	*itoa(long long n, t_dir *dir);
char	*ftoa(long double value, int precision, t_dir *dir, char *str);
char	*itohex(unsigned long n,
			const int letter_case,
			const int prefix,
			t_dir *dir);
char	*itooctal(unsigned long n, const int prefix, t_dir *dir);
char	*ptoa(unsigned long p);
char	*utoa(unsigned long int n, t_dir *dir);

void	set_flag(const char **format, t_dir *dir, t_stage *stage);
void	set_conversion(const char format, t_dir *dir);
void	set_width(const char **format, t_dir *dir, t_stage *stage);
void	set_precision(const char **format, t_dir *dir, t_stage *stage);
void	set_length(const char **format, t_dir *dir);

void	output_none(t_dir *dir, va_list *ap, int *ret);
void	output_char(t_dir *dir, va_list *ap, int *ret);
void	output_string(t_dir *dir, va_list *ap, int *ret);
void	output_pointer(t_dir *dir, va_list *ap, int *ret);
void	output_decimal(t_dir *dir, va_list *ap, int *ret);
void	output_octal(t_dir *dir, va_list *ap, int *ret);
void	output_unsigned(t_dir *dir, va_list *ap, int *ret);
void	output_hex(t_dir *dir, va_list *ap, int *ret);
void	output_float(t_dir *dir, va_list *ap, int *ret);
void	output_bit(t_dir *dir, va_list *ap, int *ret);
void	output_percentage(t_dir *dir, va_list *ap, int *ret);

#endif
