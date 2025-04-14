# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 16:42:35 by gdelhota          #+#    #+#              #
#    Updated: 2025/04/14 20:11:43 by gdelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./srcs/
OBJ_DIR = ./objs/
INCLUDES_DIR = ./includes/

MLX = ./minilibx-linux/
LIBFT = ./libft/

INCLUDES = -I $(INCLUDES_DIR) -I $(LIBFT) -I $(MLX)

SRCS = so_long.c

OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJ_DIR),$(OBJS))
SRCS := $(addprefix $(SRC_DIR),$(SRCS))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
