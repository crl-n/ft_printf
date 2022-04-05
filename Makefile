# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnysten <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 15:18:20 by cnysten           #+#    #+#              #
#    Updated: 2022/04/05 21:46:57 by carlnysten       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIB = -L./libft/ -lft

INCL = -I. -I./libft/

SRCS = ft_printf.c \
	   boolean.c\
	   output_none.c \
	   output_char.c output_string.c output_pointer.c \
	   output_decimal.c output_octal.c output_unsigned.c output_hex.c \
	   output_float.c \
	   output_percentage.c \
	   output_bit.c\

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS) $(LIB)

$(NAME): $(OBJS) $(LIBOBJS)
	ar rc $(NAME) $(OBJS) $(LIBOBJS)
	ranlib $(NAME)

leaks:

test:

clean:
	-rm -f $(OBJS) $(LIBOBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all

