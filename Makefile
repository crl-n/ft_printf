# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnysten <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 15:18:20 by cnysten           #+#    #+#              #
#    Updated: 2022/04/05 23:00:40 by carlnysten       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIB = -L./libft/ -lft 
LIB += 

INCL = -I. -I./libft/

SRCS = ft_printf.c \
	   boolean.c string.c get_format.c \
	   output_none.c \
	   output_char.c output_string.c output_pointer.c \
	   output_decimal.c output_octal.c output_unsigned.c output_hex.c \
	   output_float.c \
	   output_percentage.c \
	   output_bit.c\

TEST_SRCS = main.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS)

$(NAME): $(OBJS) $(LIBOBJS)
	ar rc $(NAME) $(OBJS) $(LIBOBJS)
	ranlib $(NAME)

$(LIB):
	-make -C ./libft

leaks: $(TEST_SRCS) $(LIB)
	$(CC) $(CFLAGS) -o test_exe $(TEST_SRCS) $(INCL) $(LIB) -L. -lftprintf

test: $(TEST_SRCS) $(LIB)
	$(CC) $(CFLAGS) -o test_exe $(TEST_SRCS) $(INCL) $(LIB) -L. -lftprintf

clean:
	-rm -f $(OBJS) $(LIBOBJS)
	-make -C clean ./libft

fclean: clean
	-rm -f $(NAME)
	-make -C fclean ./libft

re: fclean all

