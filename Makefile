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

FLAGS = -Wall -Werror -Wextra -g# -fsanitize=address

NORM = norminette -R CheckForbiddenSourceHeader

SRC = 	main.c \
		hooks.c \
		parser.c \
		renderer.c

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBFT = ./libft/libft.a
LIBFTINC = -I./libft
LINK_LIBFT = -L./libft -lft

MLX = ./minilibx/libmlx.a
MLXINC = -I./minilibx
LINK_MLX = -L./minilibx -lmlx -framework OpenGL -framework AppKit

LIBGFX = ./libgfx/libgfx.a
LIBGFXINC = -I./libgfx
LINK_GFX = -L./libgfx -lgfx

SRCDIR = ./src/
INCDIR = ./includes/
OBJDIR = ./obj/

all: obj libft.a mlx.a libgfx.a $(NAME)

love: all #credit to gwood / notoriousgtw

norm:
	$(NORM)

gfx:
	@rm -rf $(NAME)
	@rm -rf $(OBJDIR)
	@make -C ./libgfx fclean
	@make

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@gcc $(FLAGS) $(LIBFTINC) $(MLXINC) $(LIBGFXINC) -I $(INCDIR) -o $@ -c $<

libft.a:
	@make -C ./libft

libgfx.a:
	@make -C ./libgfx

mlx.a:
	@make -C ./minilibx

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) $(LINK_MLX) $(LINK_GFX) $(LINK_LIBFT)

clean:
	@rm -rf $(OBJDIR)
	@make -C ./libft clean
	@make -C ./minilibx clean
	@make -C ./libgfx clean

fclean: clean
	@rm -rf $(NAME)
	@make -C ./libft fclean
	@make -C ./libgfx fclean

re: fclean all

.PHONY: all clean fclean re
