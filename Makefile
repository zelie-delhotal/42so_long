# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/14 16:42:35 by gdelhota          #+#    #+#              #
#    Updated: 2025/04/14 17:10:14 by gdelhota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./srcs/
OBJ_DIR = ./objs/
LIBFT_DIR = ./libft/

SRCS = so_long.c

OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJ_DIR) $(OBJS))
SRCS := $(addprefix $(SRC_DIR) $(SRCS))

$(OBJ_DIR)%.o: $(OBJ_SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
