# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 16:17:30 by ikgonzal          #+#    #+#              #
#    Updated: 2022/07/31 10:27:04 by ikgonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

CC = gcc

FLAGS =	-Wall -Wextra -Werror -fsanitize=address -g3

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit 

SANITIZER = -fsanitize=address -g3

SRC  =	main.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		validation/config.c \
		mlx_functions.c \
		textures/parsing/ft_validate_xpm.c \
		textures/parsing/fill_text_matrix.c \

LIB = Libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -s -C ./libft
	@$(MAKE) -s -C ./libft bonus
	@ echo "libft compiled 🔋"
	@$(MAKE) -s -C ./mlx
	@ echo "mlx compiled 📇"
	$(CC) $(FLAGS) $(LIB) $(OBJ) $(MLX_FLAGS) $(SANITIZER) -o $(NAME)
	@ echo "cub3d compiled 🧊"

clean:
	@ rm -rf cub3d
	@ rm -rf $(OBJ)
	@ rm -rf libft/*.o
	@ rm -rf libft/libft.a
	@ rm -rf mlx/*.o
	@ rm -rf mlx/libmlx.a
	@ echo "cub3d cleaned ✅"

fclean: clean

re: fclean all

.PHONY : all clean fclean re
