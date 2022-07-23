# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 16:17:30 by ikgonzal          #+#    #+#              #
#    Updated: 2022/07/23 13:03:01 by ikgonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3d

CC = gcc

FLAGS =	-Wall -Wextra -Werror

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC  =	main.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		raycasting/config.c \
		mlx_functions.c \

LIB = Libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -s -C ./libft
	@$(MAKE) -s -C ./libft bonus
	@ echo "libft compiled 🔋"
	@$(MAKE) -s -C ./mlx
	@ echo "mlx compiled 📇"
	$(CC) $(FLAGS) $(LIB) $(OBJ) $(MLX_FLAGS) -o $(NAME)
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
