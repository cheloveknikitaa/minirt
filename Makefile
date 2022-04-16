include srcs.mk

NAME	:=	miniRT

OBJ_DIR	:=	object/
SRC_DIR	:=	source/

FT_LIB_DIR	:=	./libft/
FT_LIB		:=	$(FT_LIB_DIR)libft.a

MLX_DIR		:=	./.mlx/
MLX			:=	$(MLX_DIR)libmlx.dylib

LDFLAGS		:=	-L$(FT_LIB_DIR)	-L$(MLX_DIR) -lft -lmlx 

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -I$(FT_LIB_DIR) -I$(MLX_DIR) -I./includes
RM		:=	rm -rf

SRCS	:=	$(addprefix $(SRC_DIR), $(SOURCE))
OBJS	:=	$(addprefix $(OBJ_DIR), $(OBJECT))

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(MLX) $(FT_LIB)

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

# bonus:	$(NAME_B)

# rules for libs  #
# Make libs start #
.PHONY		: libft mlx libs_clean libs_fclean

libft		:
	$(MAKE) -C $(FT_LIB_DIR)

$(FT_LIB)	:	libft

mlx			:
	$(MAKE) -j1 -C $(MLX_DIR)

$(MLX)		:	mlx

libs_clean	:
	$(MAKE) clean -C $(FT_LIB_DIR)
	$(MAKE) clean -C $(MLX_DIR)

libs_fclean	:
	$(MAKE) fclean -C $(FT_LIB_DIR)

# Make libs end #

clean: libs_clean
	@$(RM) $(OBJS)

fclean:	clean libs_fclean
	@$(RM) $(NAME)

re:	fclean all
