# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 22:20:54 by caugusta          #+#    #+#              #
#    Updated: 2021/05/10 22:51:30 by caugusta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
LIBFT_NAME = libft.a
MLX_NAME = 

OPTFLAGS = -O2
FLAGS = -Wall -Wextra -Werror
INCLUDE_FLAG = -I $(INCLUDES) -I $(LIBFT_PATH) -I $(MLX_PATH)

INCLUDES = includes
LIBFT_PATH = libft
SRC_PATH = source
OBJ_PATH = object
MLX_PATH = mlx

HEADERS = $(INCLUDES)/*.h

SRC = \

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o)

all : libft mlx obj $(NAME)

libft :
	@$(MAKE) -C $(LIBFT_PATH)

mlx :
	@$(MAKE) -C $(MLX_PATH)

obj :
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
	gcc $(FLAGS) $(OPTFLAGS) $(INCLUDE_FLAG) -c $< -o $@

$(NAME) : $(OBJ) $(HEADERS) $(LIBFT_PATH)/$(LIBFT_NAME)
	@cp $(LIBFT_PATH)/$(LIBFT_NAME) $(OBJ_PATH)
	@cp $(MLX_PATH)/$(MLX_NAME) $(OBJ_PATH)
	gcc $(FLAGS) $(OPTFLAGS) $(INCLUDE_FLAG) $(OBJ_PATH)

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

.PHONY : all libft mlx obj clean fclean re bonus
