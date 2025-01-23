# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomas <thomas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 10:39:22 by thomas            #+#    #+#              #
#    Updated: 2025/01/23 12:06:04 by thomas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc 


SRCS = $(wildcard *.c)

LIBFT_COMPLET_DIR = ./libft_complet

LIBFT_COMPLET_INCLUDE = -I$(LIBFT_DIR)/includes

LIBFT_LIB = $(LIBFT_COMPLET_DIR)/libf_complet.a

MINILIBX_DIR = ./minilibx

OBJS = $(SRCS:.c=.o)

all: $(LIBFT_LIB) $(MINILIBX_DIR)/libmlx.a $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB)
		$(CC) $(CFLAGS) $(LIBFT_INCLUDE) $(OBJS) -L $(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_COMPLET_INCLUDE) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_COMPLET_DIR)

$(MINILIBX_DIR)/libmlx.a:
	make -C $(MINILIBX_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_COMPLET_DIR)
	make clean -C $(MINILIBX_DIR)

fclean: clean
	rm -f $(NAME) 
	make fclean -C $(LIBFT_COMPLET_DIR)
	make clean -C $(MINILIBX_DIR)

re: fclean all