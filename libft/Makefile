# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/23 18:32:18 by caugusta          #+#    #+#              #
#    Updated: 2021/05/10 23:41:07 by caugusta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =		ft_atoi.c		ft_isalpha.c		ft_itoa.c\
			ft_memcpy.c		ft_putendl_fd.c		ft_strdup.c\
			ft_strmapi.c	ft_tolower.c		ft_bzero.c\
			ft_isascii.c	ft_memccpy.c		ft_memmove.c\
			ft_putnbr_fd.c	ft_strlcat.c		ft_strncmp.c\
			ft_toupper.c	ft_calloc.c			ft_isdigit.c\
			ft_memchr.c		ft_memset.c			ft_putstr_fd.c\
			ft_strlcpy.c	ft_strnstr.c		ft_isalnum.c\
			ft_isprint.c	ft_memcmp.c			ft_putchar_fd.c\
			ft_strchr.c		ft_strlen.c			ft_strrchr.c\
			ft_substr.c		ft_strjoin.c		get_next_line.c\
			ft_split.c		ft_strtrim.c\
			ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
			ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
			ft_lstclear.c	ft_lstiter.c		ft_lstmap.c\
			
HEADER = 	*.h
OBJ_PATH = object
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

OPTFLAGS = -O2
FLAGS = -Wall -Wextra -Werror

all : obj $(NAME)

obj :
	@mkdir -p $(OBJ_PATH)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

$(OBJ_PATH)/%.o : %.c $(HEADER)
	@gcc $(FLAGS) $(OPTFLAGS) -I$(HEADER) -c $< -o $@

bonus : all

clean :
	@rm -rf $(OBJ_PATH)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : 	all clean fclean re bonus
