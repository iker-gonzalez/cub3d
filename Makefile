# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 16:17:30 by ikgonzal          #+#    #+#              #
#    Updated: 2022/09/06 19:36:28 by ikgonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit 

CC = gcc

FLAGS =	-Wall -Wextra -Werror -g3

S = -fsanitize=address

SRC  =	main.c \
		error.c \
		gets.c \
		checkutils.c \
		map_utils.c \
		map_header.c \
		check_map.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		mlx_functions.c \
		textures/parsing/parse_texture_1.c \
		textures/parsing/parse_texture_2.c \
		textures/parsing/parse_texture_3.c \
		raycasting/ray.c \
		raycasting/ray_2.c \
		raycasting/draw.c \
		ft_hook.c \
		moves.c \
		free.c \
		print_utils.c \

SRC2  =	main.c \
		error.c \
		gets.c \
		checkutils.c \
		print_utils.c \
		map_utils.c \
		map_header.c \
		check_map.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

LIB = Libft/libft.a

LIBFT = -Llibft -lft

OBJ = $(SRC:.c=.o)

OBJ2 = $(SRC2:.c=.o)

.c.o: $(SRC)
	@$(CC) $(FLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./libft bonus
	@ echo "libft compiled 🔋"
	@$(MAKE) -Wno -C ./mlx
	@ echo "mlx compiled 📇"
	$(CC) $(OBJ) $(FLAGS) $(LIB) $(MLX_FLAGS) -o $(NAME)
	@ echo "cub3d compiled 🧊"

san : $(OBJ)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./libft bonus
	@ echo "libft compiled 🔋"
	@$(MAKE) -Wno -C ./mlx
	@ echo "minilibx compiled 📇"
	$(CC) $(OBJ) $(FLAGS) $(LIB) $(S) $(MLX_FLAGS) -o $(NAME)
	@ echo "cub3d sanitized 🧊"

docsan : $(OBJ2)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./libft bonus
	@ echo "libft compiled 🔋"
	# @$(MAKE) -Wno -C ./mlx
	# @ echo "minilibx compiled 📇"
	$(CC) $(OBJ2) $(FLAGS) $(LIB) $(S)  -o $(NAME)
	@ echo "cub3d sanitized 🧊"

doc : $(OBJ2)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./libft bonus
	@ echo "libft compiled 🔋"
	# @$(MAKE) -Wno -C ./mlx
	# @ echo "minilibx compiled 📇"
	$(CC) $(OBJ2) $(FLAGS) $(LIB) -o $(NAME)
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
