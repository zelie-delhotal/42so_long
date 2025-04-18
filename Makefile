# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 16:42:35 by gdelhota          #+#    #+#              #
#    Updated: 2025/04/18 13:27:11 by gdelhota         ###   ########.fr        #
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

LDFLAGS := -L$(LIBFT) -L$(MLX)
LDLIBS := -lft -lmlx -lXext -lX11 -lm

INCLUDES = -I$(INCLUDES_DIR) -I$(LIBFT) -I$(MLX)

SRCS = so_long.c parser.c checker.c \
	   get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJ_DIR),$(OBJS))
SRCS := $(addprefix $(SRC_DIR),$(SRCS))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: makelib $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

makelib:
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MLX)

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(MLX) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
#	$(MAKE) -C $(MLX) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
