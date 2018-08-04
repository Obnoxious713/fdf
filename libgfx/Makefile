# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfleisch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 15:55:00 by jfleisch          #+#    #+#              #
#    Updated: 2018/07/21 15:55:01 by jfleisch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libgfx.a
NAME2 = libgfx
FLAGS =	-Wall -Wextra -Werror -g
CC = gcc
ODIR =	bin/
IDIR =
SRC =
OBJ =	$(SRC:.c=.o)
EXT =	$(IDIR)$(NAME:.a=.h)

EXT +=	Makefile

SRC	+=	ft_drawline.c \
		matrix_math.c \
		transform_matrix.c \
		initializers.c

O =		$(addprefix $(ODIR), $(OBJ))

MLXINC	= -I../minilibx
LFTINC	= -I../libft

all: $(NAME)

love: all

norm:
	norminette $(S)

$(NAME): $(O) $(EXT)
	@echo "-> Creating archive $(NAME)...\n "
	@ar rc $(NAME) $(O)
	@ranlib $(NAME)

$(ODIR)%.o: %.c $(EXT)
	@$(CC) $(FLAGS) $(MLXINC) $(LFTINC) -c $< -o $@

$(O): | ./bin

./bin:
	@mkdir -p $(ODIR)

clean:
	@echo "-> Cleaning $(NAME2) object files..."
	@rm -rf $(O)

fclean:
	@echo "-> Cleaning $(NAME)..."
	@rm -rf $(NAME)
	@echo "-> Cleaning $(NAME2) object files...\n "
	@rm -rf $(O)

re: fclean all

.PHONY: all clean fclean re norm
