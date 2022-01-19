# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnysten <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 15:18:20 by cnysten           #+#    #+#              #
#    Updated: 2022/01/18 16:29:23 by cnysten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

CC = gcc

FLAGS = -Wall -Wextra -Werror -g # REMOVE -g, add -c

NAME = libftprintf.a

SRCS = ft_printf.c ptoa.c

OBJS = $(SRCS:%.c=%.o)

LIB = ../libft/libft.a

all: $(NAME)

$(LIB):
	make -C ../libft all

$(NAME): $(OBJS) $(LIB)
	$(CC) $(FLAGS) -c -I../libft/ $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

debug: $(OBJS) $(LIB)
	$(CC) $(FLAGS) -I../libft/ -L../libft/ -lft main.c $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

