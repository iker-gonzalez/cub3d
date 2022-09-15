# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 16:17:30 by ikgonzal          #+#    #+#              #
#    Updated: 2022/09/15 17:27:31 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

NAME_B = cub3D_bonus

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit 

LMLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

CC = gcc

FLAGS =	-Wall -Wextra -Werror -g3

S = -fsanitize=address

SRC  =	src/main.c \
		src/error.c \
		src/gets.c \
		src/checkutils.c \
		src/map_utils.c \
		src/map_header.c \
		src/check_map.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		src/mlx_functions.c \
		src/textures/parsing/parse_texture_1.c \
		src/textures/parsing/parse_texture_2.c \
		src/textures/parsing/parse_texture_3.c \
		src/raycasting/ray.c \
		src/raycasting/ray_2.c \
		src/raycasting/draw.c \
		src/ft_hook.c \
		src/moves.c \
		src/free.c \
		src/print_utils.c \
		src/turns.c \
		src/inits.c

SRC_B  =	src_bonus/main_bonus.c \
		src_bonus/error_bonus.c \
		src_bonus//gets_bonus.c \
		src_bonus//checkutils_bonus.c \
		src_bonus//map_utils_bonus.c \
		src_bonus//map_header_bonus.c \
		src_bonus//check_map_bonus.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		src_bonus//mlx_functions_bonus.c \
		src_bonus//textures/parsing/parse_texture_1_bonus.c \
		src_bonus//textures/parsing/parse_texture_2_bonus.c \
		src_bonus//textures/parsing/parse_texture_3_bonus.c \
		src_bonus//raycasting/ray_bonus.c \
		src_bonus//raycasting/ray_2_bonus.c \
		src_bonus//raycasting/draw_bonus.c \
		src_bonus//ft_hook_bonus.c \
		src_bonus//moves_bonus.c \
		src_bonus//free_bonus.c \
		src_bonus//print_utils_bonus.c \
		src_bonus//turns_bonus.c \
		src_bonus//inits_bonus.c

SRC2  =	src/main.c \
		src/error.c \
		src/gets.c \
		src/checkutils.c \
		src/print_utils.c \
		src/map_utils.c \
		src/map_header.c \
		src/check_map.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

LIB = libft/libft.a

LIBFT = -Llibft -lft

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

OBJ2 = $(SRC2:.c=.o)

.c.o: $(SRC)
	@$(CC) $(FLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C ./libft
	@ echo "libft compiled 🔋"
	@$(MAKE) -Wno -C ./mlx
	@ echo "mlx compiled 📇"
	$(CC) $(OBJ) $(FLAGS) $(LIB) $(MLX_FLAGS) -o $(NAME)
	@ echo "cub3d compiled 🧊"

bonus : $(NAME_B)

$(NAME_B) : $(OBJ_B)
	@$(MAKE) -C ./libft
	@ echo "libft compiled 🔋"
	@$(MAKE) -Wno -C ./mlx
	@ echo "mlx compiled 📇"
	$(CC) $(OBJ_B) $(FLAGS) $(LIB) $(MLX_FLAGS) -o $(NAME_B)
	@ echo "cub3d compiled 🧊"

disp : $(OBJ)
	@$(MAKE) -C ./libft
	@ echo "libft compiled 🔋"
	@$(MAKE) -Wno -C ./mlx_linux
	@ echo "mlx linux compiled 📇"
	$(CC) $(OBJ) $(FLAGS) $(LIB) $(LMLX_FLAGS) -o $(NAME)
	@ echo "cub3d linux compiled 🧊"

sandisp : $(OBJ)
	@$(MAKE) -C ./libft
	@ echo "libft compiled 🔋"
	@$(MAKE) -Wno -C ./mlx_linux
	@ echo "mlx linux compiled 📇"
	$(CC) $(OBJ) $(FLAGS) $(LIB) $(S) $(LMLX_FLAGS) -o $(NAME)
	@ echo "cub3d linux sanitized 🧊"

san : $(OBJ)
	@$(MAKE) -C ./libft
	@ echo "libft compiled 🔋"
	@$(MAKE) -Wno -C ./mlx
	@ echo "minilibx compiled 📇"
	$(CC) $(OBJ) $(FLAGS) $(S) $(LIB) $(MLX_FLAGS) -o $(NAME)
	@ echo "cub3d sanitized 🧊"

docsan : $(OBJ2)
	@$(MAKE) -C ./libft
	@ echo "libft compiled 🔋"
	# @$(MAKE) -Wno -C ./mlx
	# @ echo "minilibx compiled 📇"
	$(CC) $(OBJ2) $(FLAGS) $(LIB) $(S)  -o $(NAME)
	@ echo "cub3d sanitized 🧊"

doc : $(OBJ2)
	@$(MAKE) -C ./libft
	@ echo "libft compiled 🔋"
	# @$(MAKE) -Wno -C ./mlx
	# @ echo "minilibx compiled 📇"
	$(CC) $(OBJ2) $(FLAGS) $(LIB) -o $(NAME)
	@ echo "cub3d sanitized 🧊"

clean:
	@ rm -rf $(OBJ)
	@ rm -rf $(OBJ_B)
	@ rm -rf libft/*.o
	@ rm -rf libft/libft.a
	@ rm -rf mlx/*.o
	@ rm -rf mlx/libmlx.a
	@ echo "cub3d cleaned ✅"

fclean: clean
	@ rm -rf $(NAME)
	@ rm -rf $(NAME_B)

re: fclean all

re_bonus: fclean bonus

.PHONY : all bonus clean fclean re
