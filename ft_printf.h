/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:48:48 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/19 14:17:13 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
# define CHAR      0b0000 // Can NONE be used for flag, conv and length?
# define STRING    0b0001
# define POINTER   0b0010
# define DIGIT     0b0011
# define INTEGER   0b0100
# define OCTAL     0b0101
# define UNSIGNED  0b0111
# define HEX_LOWER 0b1000
# define HEX_UPPER 0b1001
# define FLOAT     0b1010
# define BIT       0b1011
# define NONE      0b1100 // Can NONE be used for flag, conv and length?

/* Lengths */
# define L  0b001
# define LL 0b010
# define H  0b011
# define HH 0b100

/* Typedefs and structs */
typedef char	*t_converter(t_directive *dir, void *arg);

typedef struct s_directive
{
	unsigned int	flags : 8;
	unsigned int	conversion : 4;
	unsigned int	length : 3;
	int				width; // Maximum width seems to be 2147483646
	int				precision; // Maximum precision seems to be 2147483645
}	t_directive;

int		ft_printf(const char *format, ...);
void	parse_format(const char *format, t_list **dir_list);
int		is_flag(const char c);
int		is_conversion(const char c);
int		is_precision(const char c);
int		is_length(const char c);
void	set_flag(const char c, t_directive *dir);
void	set_conversion(const char format, t_directive *dir);
void	set_width(const char *format, t_directive *dir);
void	set_precision(const char *format, t_directive *dir);
void	set_length(const char *format, t_directive *dir);

char	*ptoa(unsigned long p);

#endif
