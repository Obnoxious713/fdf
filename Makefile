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

FLAGS = -Wall -Werror -Wextra -g -fsanitize=address

CC = gcc

NORM = norminette -R CheckForbiddenSourceHeader

SRC = 	main.c \
		hooks.c \
		parser.c \
		renderer.c

OBJ = $(addprefix $(OBJDIR),$(SRC:.c=.o))

LIBFT = ./libft/libft.a
LIBFTINC = -I./libft
LINK_FT = -L./libft -lft

MLX = ./minilibx/libmlx.a
MLXINC = -I./minilibx
LINK_MLX = -L./minilibx -lmlx -framework OpenGL -framework AppKit

LIBGFX = ./libgfx/libgfx.a
LIBGFXINC = -I./libgfx
LINK_GFX = -L./libgfx -lgfx

SRCDIR = ./src/
INCDIR = ./includes/
OBJDIR = ./obj/

LINK = -L./minilibx -lmlx -framework OpenGL -framework AppKit -L./libgfx -lgfx -L./libft -lft

all: obj mlx libgfx libft $(NAME)

gfx:
	@rm -rf $(NAME)
	@rm -rf $(OBJDIR)
	@make -C ./libgfx fclean
	@make

src:
	@mkdir -p $(SRCDIR)

obj:
	@mkdir -p $(OBJDIR)

inc:
	@mkdir -p $(INCDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(FLAGS) $(MLXINC) $(LIBGFXINC) $(LIBFTINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

libgfx: $(LIBGFX)

mlx: $(MLX)

$(LIBFT):
	@make -C ./libft

$(LIBGFX):
	@make -C ./libgfx

$(MLX):
	@make -C ./minilibx

$(NAME): $(OBJ)
	@echo "-> Compiling $(NAME)..."
	@$(CC) -o $(NAME) $(OBJ) $(LINK_MLX) $(LINK_GFX) $(LINK_FT) -v
	@echo "...Done"

clean:
	@echo "-> Cleaning $(NAME) object files..."
	@rm -rf $(OBJ)
	@make -C ./libft clean
	@make -C ./minilibx clean
	@make -C ./libgfx clean

fclean:
	@echo "-> Cleaning $(NAME)...\n "
	@rm -rf $(NAME)
	@rm -rf $(OBJ)
	@make -C ./libft fclean
	@make -C ./libgfx fclean
	@make -C ./minilibx clean

re: fclean all

norm:
	$(NORM)

love: all #credit to gwood / notoriousgtw

.PHONY: all clean fclean re
