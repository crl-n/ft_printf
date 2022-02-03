/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:48:48 by cnysten           #+#    #+#             */
/*   Updated: 2022/02/03 17:59:13 by carlnysten       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Includes */
# include "libft.h"
# include <stdarg.h>

/* Conversions */
# define CHAR       0b0000
# define STRING     0b0001
# define POINTER    0b0010
# define DECIMAL    0b0011
# define INTEGER    0b0100
# define OCTAL      0b0101
# define UNSIGNED   0b0110
# define HEX_LOWER  0b0111
# define HEX_UPPER  0b1000
# define FLOAT      0b1001
# define BIT        0b1010
# define PERCENTAGE 0b1011
# define NONE       0b1111

/* Lengths */
# define L         0b001
# define LL        0b010
# define H         0b011
# define HH        0b100
# define CAPITAL_L 0b101

/* Parser stage */
# define FLAG       0
# define WIDTH      1
# define PRECISION  2
# define LENGTH     3
# define CONVERSION 4

/* Floating point */
# define SIGN_32 0x80000000

/* Other */
# define LOWERCASE 0
# define UPPERCASE 1
# define FALSE 0
# define TRUE 1

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
	unsigned int	conversion : 4;
	unsigned int	length : 3;
	unsigned int	negative : 1;
	int				width; // Maximum width seems to be 2147483646
	int				precision; // Maximum precision seems to be 2147483645
	int				start_i;
	int				end_i;
}	t_dir;

typedef void	t_converter(t_dir *dir, va_list *ap, int *ret);
typedef int		t_stage;

/* Prototypes */
int		ft_printf(const char *format, ...);
int		parse_format(const char *format, t_list **dir_list);
void	put_arg(t_dir *dir, va_list *ap, int *ret);

int		is_flag(const char c);
int		is_conversion(const char c);
int		is_precision(const char c);
int		is_length(const char c);

char	*itoa(long long n, t_dir *dir);
char	*ftoa(double value, int precision);
char	*itohex(unsigned long n, const int letter_case, const int prefix, t_dir *dir);
char	*itooctal(unsigned long n, const int prefix, t_dir *dir);
char	*ptoa(unsigned long p);
char	*utoa(unsigned long int n);

void	set_flag(const char **format, t_dir *dir, t_stage *stage);
void	set_conversion(const char format, t_dir *dir);
void	set_width(const char **format, t_dir *dir, t_stage *stage);
void	set_precision(const char **format, t_dir *dir);
void	set_length(const char **format, t_dir *dir);

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
