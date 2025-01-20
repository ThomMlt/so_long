# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomas <thomas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 11:41:05 by toto              #+#    #+#              #
#    Updated: 2025/01/18 16:01:07 by thomas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_print_pointer.c \
		ft_printf.c \
		ft_putnbr_count.c \
		ft_putnbr_hexa.c \
		ft_putstr_count.c \

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

all: ${NAME}

${NAME}: ${OBJS}
		ar -crs ${NAME} ${OBJS}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

clean :
			rm -f ${OBJS}

fclean : clean
			rm -f ${NAME}

re: fclean all