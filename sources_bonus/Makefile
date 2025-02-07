# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 10:39:22 by thomas            #+#    #+#              #
#    Updated: 2025/02/07 16:06:35 by tmillot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRCS = check_map_utils_bonus.c \
		free_error_utils_bonus.c \
		init_struct_bonus.c \
		move_player_bonus.c \
		draw_map_after_move_bonus.c \
		handling_draw_wall_bonus.c \
		main_bonus.c \
		draw_map_bonus.c \
		handling_map_bonus.c \
		valid_way_bonus.c \
		enemy_handling.c 

OBJS = $(SRCS:.c=.o)

# Directories for libraries
GNL_DIR = ../libft_complet/gnl
PRINTF_DIR = ../libft_complet/printf
LIBFT_DIR = ../libft_complet/libft
MINILIBX_DIR = ../minilibx

# Library files
GNL_LIB = $(GNL_DIR)/libgnl.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a

# Includes for libraries
INCLUDES = -I$(GNL_DIR) -I$(PRINTF_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)

all: $(GNL_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(MINILIBX_LIB) $(NAME)

$(NAME): $(OBJS) $(GNL_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(MINILIBX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME) \
		-L$(GNL_DIR) -lgnl \
		-L$(PRINTF_DIR) -lftprintf \
		-L$(LIBFT_DIR) -lft \
		-L$(MINILIBX_DIR) -lmlx \
		-lX11 -lXext

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rules to build the individual libraries
$(GNL_LIB):
	make -C $(GNL_DIR)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(MINILIBX_LIB):
	make -C $(MINILIBX_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(GNL_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(GNL_DIR)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

re: fclean all

.PHONY: all clean fclean re
