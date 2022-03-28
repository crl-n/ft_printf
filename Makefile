# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnysten <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 15:18:20 by cnysten           #+#    #+#              #
#    Updated: 2022/03/28 23:46:40 by carlnysten       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

INCL = -I. -I./libft/

SRCS = ft_printf.c \
	   parser.c boolean.c setters.c\
	   output_none.c \
	   output_char.c output_string.c output_pointer.c \
	   output_decimal.c output_octal.c output_unsigned.c output_hex.c \
	   output_float.c \
	   output_percentage.c \
	   output_bit.c\
	   ftoa.c utoa.c itooctal.c itohex.c itoa.c \

LIBSRCS = libft/ft_atoi.c libft/ft_bzero.c \
		  libft/ft_intlen.c libft/ft_intlen_base.c \
		  libft/ft_isdigit.c \
		  libft/ft_itoa_base.c \
		  libft/ft_memcpy.c libft/ft_memset.c \
		  libft/ft_lstnew.c libft/ft_lstadd_back.c libft/ft_lstpop_left.c \
		  libft/ft_strdup.c libft/ft_strlen.c libft/ft_strnew.c \
		  libft/ft_strndup.c libft/ft_strncpy.c 

OBJS = $(SRCS:%.c=%.o)

TEST = main.c

LIBOBJS = $(LIBSRCS:%.c=%.o)

all: $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(INCL) $(SRCS) -g

$(LIBOBJS): $(LIBSRCS)
	make -C ./libft/

$(NAME): $(OBJS) $(LIBOBJS)
	ar rc $(NAME) $(OBJS) $(LIBOBJS)
	ranlib $(NAME)

test: $(OBJS) $(LIBOBJS) $(TEST)
	$(CC) $(CFLAGS) -g -o test $(INCL) main.c $(OBJS) $(LIBOBJS)

clean:
	-rm -f $(OBJS) $(LIBOBJS) test

fclean: clean
	-rm -f $(NAME)

re: fclean all

