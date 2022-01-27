# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnysten <cnysten@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/27 10:39:36 by cnysten           #+#    #+#              #
#    Updated: 2022/01/27 10:48:49 by cnysten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = # IS NAME NEEDED HERE?

CFLAGS = -Wall -Wextra -Werror -c

SRCS = ft_atoi.c ft_itoa_base.c ft_strdup.c \
	   ft_bzero.c ft_lstadd_back.c ft_strlen.c \
	   ft_intlen.c ft_lstnew.c ft_strnew.c \
	   ft_intlen_base.c ft_lstpop_left.c \
	   ft_isdigit.c ft_memcpy.c \
	   ft_itoa.c ft_memset.c \

OBJS = $(SRCS:%.c=%.o)

all: $(OBJS)

$(OBJS):
	gcc $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean

re: fclean all
