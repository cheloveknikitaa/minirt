# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/10 22:20:54 by caugusta          #+#    #+#              #
#    Updated: 2021/06/29 00:35:50 by caugusta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= miniRT
LIBFT_NAME			= libft.a
MLX_NAME			= libmlx.dylib

CC					= gcc
CFLAGS				= #-Wall -Wextra -Werror

OBJ_DIR				= object/
SOURCE_DIR			= source/
SOURCE				= sphere.c	utils_hook.c	utils_vec2.c	utils_vec3.c	utils_vec3_2.c	utils.c	utils_protect.c parser.c\
						main.c	utils_color.c	utils_mlx.c	utils_vec2_1.c	utils_vec3_1.c	plane.c	utils_color_not_use.c cylinder.c

LIBFT				= libft/$(LIBFT_NAME)
LIBFT_DIR			= libft/
MLX					= mlx/$(MLX_NAME)
MLX_DIR				= mlx/

OBJ					= $(addprefix $(OBJ_DIR), $(SOURCE:.c=.o))
D_FILES				= $(wildcard $(OBJ_DIR)*.d)

.PHONY : all sub_directory clean fclean re bonus

all : sub_directory $(NAME)
	@echo COMPLETE

sub_directory :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SOURCE_DIR)%.c
	$(CC) -g -c -MMD -g $(CFLAGS) -I includes $< -o $@

$(NAME) : $(MLX) $(LIBFT) $(OBJ) #$(SOURCE_DIR)neubivay.c 
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $^ -o $@
	@cp $(MLX) .

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR) --silent
	@cp $(LIBFT_DIR)/libft.h ./includes
	@echo LIBFT OK
$(MLX) :
	@$(MAKE) -C $(MLX_DIR) --silent
	@echo MLX OK

include $(D_FILES)

bonus : all

clean :
	@$(MAKE) clean -C $(LIBFT_DIR) --silent
	@echo CLEAN LIBFT
	@$(MAKE) clean -C $(MLX_DIR) --silent
	@echo CLEAN MLX
	@rm -rf $(OBJ_DIR)

fclean : clean
	@$(MAKE) fclean -C $(LIBFT_DIR) --silent
	@echo FCLEAN COMPLETE
	@rm -f $(MLX_NAME) --silent
	@rm -rf $(NAME)
	@rm -rf includes/libft.h

re : fclean all
