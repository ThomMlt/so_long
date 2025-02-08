# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmillot <tmillot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 13:54:29 by tmillot           #+#    #+#              #
#    Updated: 2025/02/08 14:14:36 by tmillot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Source files for the main program
SRCS = sources/check_map_utils.c \
       sources/free_error_utils.c \
       sources/init_struct.c \
       sources/move_player.c \
       sources/draw_map_after_move.c \
       sources/handling_draw_wall.c \
       sources/main.c \
       sources/draw_map.c \
       sources/handling_map.c \
       sources/valid_way.c

# Source files for the bonus program
BONUS_SRCS = sources_bonus/check_map_utils_bonus.c \
             sources_bonus/free_error_utils_bonus.c \
             sources_bonus/init_struct_bonus.c \
             sources_bonus/move_player_bonus.c \
             sources_bonus/draw_map_after_move_bonus.c \
             sources_bonus/handling_draw_wall_bonus.c \
             sources_bonus/main_bonus.c \
             sources_bonus/draw_map_bonus.c \
             sources_bonus/handling_map_bonus.c \
             sources_bonus/valid_way_bonus.c \
             sources_bonus/display_move.c

# Object files for the main program
OBJS = $(SRCS:.c=.o)

# Object files for the bonus program
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Directories for libraries
GNL_DIR = ./libft_complet/gnl
PRINTF_DIR = ./libft_complet/printf
LIBFT_DIR = ./libft_complet/libft
MINILIBX_DIR = ./minilibx

# Library files
GNL_LIB = $(GNL_DIR)/libgnl.a
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a

# Includes for libraries and source directories
INCLUDES = -I$(GNL_DIR) -I$(PRINTF_DIR) -I$(LIBFT_DIR) -I$(MINILIBX_DIR) -I./sources -I./sources_bonus

# Default target: compile the main program
all: $(NAME)

# Target to compile the main program
$(NAME): $(OBJS) $(GNL_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(MINILIBX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME) \
		-L$(GNL_DIR) -lgnl \
		-L$(PRINTF_DIR) -lftprintf \
		-L$(LIBFT_DIR) -lft \
		-L$(MINILIBX_DIR) -lmlx \
		-lX11 -lXext

# Target to compile the bonus program
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS) $(GNL_LIB) $(PRINTF_LIB) $(LIBFT_LIB) $(MINILIBX_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(INCLUDES) -o $(NAME_BONUS) \
		-L$(GNL_DIR) -lgnl \
		-L$(PRINTF_DIR) -lftprintf \
		-L$(LIBFT_DIR) -lft \
		-L$(MINILIBX_DIR) -lmlx \
		-lX11 -lXext

# Generic rule to compile .c files to .o files
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

# Clean rule
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

# Full clean rule
fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(GNL_DIR)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

# Recompilation rule
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus
