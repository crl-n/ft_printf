# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnysten <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 15:18:20 by cnysten           #+#    #+#              #
#    Updated: 2022/02/02 11:07:36 by carlnysten       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

CC = gcc

FLAGS = -Wall -Wextra -g # FIX THIS

NAME = libftprintf.a

SRCS = ft_printf.c parser.c boolean.c setters.c put_arg.c \
	   csp.c diouxx.c fb.c \
	   itoa.c itooctal.c ftoa.c utoa.c itohex.c

LIBSRCS = libft/ft_atoi.c libft/ft_bzero.c \
		  libft/ft_intlen.c libft/ft_intlen_base.c \
		  libft/ft_isdigit.c \
		  libft/ft_itoa_base.c \
		  libft/ft_memcpy.c libft/ft_memset.c \
		  libft/ft_lstnew.c libft/ft_lstadd_back.c libft/ft_lstpop_left.c \
		  libft/ft_strdup.c libft/ft_strlen.c libft/ft_strnew.c \
		  libft/ft_strndup.c libft/ft_strncpy.c 

OBJS = $(SRCS:%.c=%.o)

LIBOBJS = $(LIBSRCS:%.c=%.o)

all: $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) -c -I../libft/ $(SRCS)

$(LIBOBJS): $(LIBSRCS)
	make -C ./libft/

$(NAME): $(OBJS) $(LIBOBJS)
	ar rc $(NAME) $(OBJS) $(LIBOBJS)
	ranlib $(NAME)

debug: $(SRCS)
	$(CC) $(FLAGS) -I./libft/ main.c $(SRCS) $(LIBSRCS)

clean:
	rm -f $(OBJS) $(LIBOBJS)

fclean: clean
	rm -f $(NAME)
	rm -f a.out
	rm -rf a.out.dSYM

re: fclean all

