# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfleisch <jfleisch@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/16 14:55:22 by jfleisch          #+#    #+#              #
#    Updated: 2018/06/01 12:14:19 by jfleisch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MLX = ft_libfx

LINK = -Llibft/ -lft

LINK_MLX = -Lft_libgfx/minilibx_macos_sierra -lmlx

FRAMEWORK = -framework OpenGL -framework AppKit

FLAGS = -Wall -Werror -Wextra -g -fsanitize=address

NORM = norminette -R CheckForbiddenSourceHeader

SRC = blg.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

libft.a:
	@make -C libft/

$(NAME): libft.a $(OBJ)
	@gcc -I $(MLX) $(OBJ) $(FLAGS) $(LINK) $(LINK_MLX) $(FRAMEWORK) main.c -o $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

norm:
	$(NORM)
