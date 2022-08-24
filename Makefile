# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 16:17:30 by ikgonzal          #+#    #+#              #
#    Updated: 2022/08/24 19:20:09 by ikgonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit 

CC = gcc -O2

FLAGS =	-Wall -Wextra -Werror -g3

S = -fsanitize=address

SRC  =	ikermain.c \
		error.c \
		gets.c \
		checkutils.c \
		print_utils.c \
		map_utils.c \
		map_header.c \
		check_map.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		config.c \
		mlx_functions.c \
		textures/parsing/fill_text_matrix.c \
		raycasting/ray.c \
		raycasting/ray_2.c \
		raycasting/draw.c \
		ft_hook.c \
		moves.c \

LIB = Libft/libft.a

LIBFT = -Llibft -lft

OBJ = $(SRC:.c=.o)

.c.o: $(SRC)
	@$(CC) $(FLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./libft bonus
	@ echo "libft compiled 🔋"
	@$(MAKE) -Wno -C ./mlx
	@ echo "mlx compiled 📇"
	$(CC) $(FLAGS) $(LIB) $(OBJ) $(MLX_FLAGS) -o $(NAME)
	@ echo "cub3d compiled 🧊"

san : $(OBJ)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./libft bonus
	@ echo "libft compiled 🔋"
	@$(MAKE) -Wno -C ./mlx
	@ echo "minilibx compiled 📇"
	$(CC) $(FLAGS) $(LIB) $(S) $(OBJ) $(MLX_FLAGS) -o $(NAME)
	@ echo "cub3d sanitized 🧊"

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
