# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 22:20:54 by caugusta          #+#    #+#              #
#    Updated: 2021/05/11 15:35:44 by caugusta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
LIBFT_NAME = libft.a
MLX_NAME = libmlx.dylib

FLAGS = -Wall -Wextra -Werror
INCLUDE_FLAG = -I $(INCLUDES_PATH) -I $(MLX_PATH)

VPATH = source:includes
MLX_PATH = mlx
LIBFT_PATH = libft
OBJ_PATH = object

HEADERS = $(wildcard *.h)
SRC = $(wildcard *.c)
OBJ = $(wildcard *.o)

O_FILE = $(patsubst %.c, $(OBJ_PATH)%.o, $(SRC))

all : libcompil obj $(NAME)

libcompil :
	@$(MAKE) -C $(LIBFT_PATH)
	@$(MAKE) -C $(MLX_PATH)

obj :
	@mkdir -p $(OBJ_PATH)

$(O_FILE) : $(SRC)
	gcc $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(HEADERS)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

bonus : all

clean :
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(MAKE) clean -C $(MLX_PATH)
	@rm -rf $(OBJ_PATH)

fclean : clean
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@$(MAKE) clean -C $(MLX_PATH)
	@rm -rf $(NAME)

re : fclean all

.PHONY : all obj clean fclean re bonus
