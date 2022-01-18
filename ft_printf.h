/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnysten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:48:48 by cnysten           #+#    #+#             */
/*   Updated: 2022/01/18 16:00:32 by cnysten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ALT   0b100000
# define ZERO  0b010000
# define PLUS  0b001000
# define MINUS 0b000100
# define SPACE 0b000010
# define SEP   0b000001

# define CHAR      0b1000000000
# define STRING    0b0100000000
# define POINTER   0b0010000000
# define DIGIT     0b0001000000
# define INTEGER   0b0000100000
# define OCTAL     0b0000010000
# define UNSIGNED  0b0000001000
# define HEX_LOWER 0b0000000100
# define HEX_UPPER 0b0000000010
# define FLOAT     0b0000000001

typedef struct s_directive
{
	unsigned int	flags : 6;
	unsigned int	conversion : 10;
	unsigned int	length : 4;
	int				width; // Maximum width seems to be 2147483646
	int				precision; // Maximum precision seems to be 2147483645
	
} t_directive;

int	ft_printf(const char *format, ...);
char	*ptoa(unsigned long p);

#endif
