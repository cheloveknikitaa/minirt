# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 22:20:54 by caugusta          #+#    #+#              #
#    Updated: 2021/05/11 20:30:18 by caugusta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= miniRT
LIBFT_NAME			= libft.a
MLX_NAME			= libmlx.dylib

CC					= gcc
CFLAGS				= #-Wall -Wextra -Werror

OBJ_DIR				= object/
SOURCE_DIR			= source/
SOURCE				= main.c

LIBFT				= libft/$(LIBFT_NAME)
LIBFT_PATH			= libft/
MLX					= mlx/$(MLX_NAME)
MLX_PATH			= mlx/

OBJ					= $(addprefix $(OBJ_DIR), $(SOURCE:.c=.o))
D_FILES				= $(OBJ_DIR)%.d

.PHONY : all sub_directory clean fclean re bonus

all : sub_directory $(NAME)

sub_directory :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SOURCE_DIR)%.c
	$(CC) -c -MMD $(CFLAGS) -I includes $< -o $@

$(NAME) : $(MLX) $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $^ -o $@

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_PATH)
$(MLX) :
	@$(MAKE) -C $(MLX_PATH)

include $(D_FILES)

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
