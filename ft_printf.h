/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:48:48 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/23 18:29:43 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Includes */
#include "../libft/libft.h"

/* Mandatory flags */
# define ALT    0b10000000
# define ZERO   0b01000000
# define PLUS   0b00100000
# define MINUS  0b00010000
# define SPACE  0b00001000

/* Bonus flags */
# define SEP    0b00000100
# define ASTR   0b00000010
# define DOLLAR 0b00000001

/* Conversions */
# define CHAR      0b0000
# define STRING    0b0001
# define POINTER   0b0010
# define DECIMAL   0b0011
# define INTEGER   0b0100
# define OCTAL     0b0101
# define UNSIGNED  0b0110
# define HEX_LOWER 0b0111
# define HEX_UPPER 0b1000
# define FLOAT     0b1001
# define BIT       0b1010
# define NONE      0b1111 // Can NONE be used for flag, conv and length?

/* Lengths */
# define L  0b001
# define LL 0b010
# define H  0b011
# define HH 0b100

/* Parser stage */
# define FLAG       0
# define WIDTH      1
# define PRECISION  2
# define LENGTH     3
# define CONVERSION 4

/* Other */
# define LOWERCASE 0
# define UPPERCASE 1

# define FALSE 0
# define TRUE 1

/* Typedefs and structs */
typedef struct s_directive
{
	unsigned int	flags : 8;
	unsigned int	conversion : 4;
	unsigned int	length : 3;
	unsigned int	negative : 1;
	int				width; // Maximum width seems to be 2147483646
	int				precision; // Maximum precision seems to be 2147483645
}	t_directive;

typedef char	*t_converter(t_directive *dir, void *arg);
typedef int		t_parser_stage;

int			ft_printf(const char *format, ...);
int			parse_format(const char *format, t_list **dir_list);
int			is_flag(const char c);
int			is_conversion(const char c);
int			is_precision(const char c);
int			is_length(const char c);
char		*itohex(int n, const int letter_case, const int prefix);
char		*itooctal(int n,const  int prefix);
void		set_flag(const char **format, t_directive *dir, t_parser_stage *stage);
void		set_conversion(const char format, t_directive *dir);
void		set_width(const char **format, t_directive *dir, t_parser_stage *stage);
void		set_precision(const char *format, t_directive *dir);
void		set_length(const char *format, t_directive *dir);
char		*as_char(t_directive *dir, void *arg);
char		*as_string(t_directive *dir, void *arg);
char		*as_pointer(t_directive *dir, void *arg);
char		*as_decimal(t_directive *dir, void *arg);
char		*as_octal(t_directive *dir, void *arg);
char		*as_unsigned(t_directive *dir, void *arg);
char		*as_hex(t_directive *dir, void *arg);
char		*as_float(t_directive *dir, void *arg);
char		*as_bit(t_directive *dir, void *arg);
t_directive	*new_directive(void);

char	*ptoa(unsigned long p);

#endif
