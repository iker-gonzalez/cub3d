# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 16:17:30 by ikgonzal          #+#    #+#              #
#    Updated: 2022/08/07 21:08:03 by ingonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	Cub3d

CC = gcc
FLAGS =	-Wall -Wextra -Werror
S = -fsanitize=address -g

SRC  =	main.c \
		error.c \
		cub3_checkutils.c \
		cub3_print_utils.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

LIB = Libft/libft.a

LIBFT = -Llibft -lft
MLX = -Lmlx -lmlx

OBJ = $(SRC:.c=.o)

.c.o: $(SRCS)
	@$(CC) $(FLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./libft bonus
	@ echo "libft compiled 🔋"
	@$(MAKE) -Wno -C ./minilibx
	@ echo "minilibx compiled 📇"
	$(CC) $(FLAGS) $(LIB) $(OBJ) -o $(NAME)
	@ echo "cub3d compiled 🧊"

san : $(OBJ)
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./libft bonus
	@ echo "libft compiled 🔋"
	@$(MAKE) -Wno -C ./minilibx
	@ echo "minilibx compiled 📇"
	$(CC) $(FLAGS) $(LIB) $(S) $(OBJ) -o $(NAME)
	@ echo "cub3d sanitized 🧊"

clean:
	@ rm -rf cub3d
	@ rm -rf $(OBJ)
	@ rm -rf libft/*.o
	@ rm -rf libft/libft.a
	@ rm -rf minilibx/*.o
	@ rm -rf minilibx/libmlx.a
	@ echo "cub3d cleaned ✅"

fclean: clean

re: fclean all

.PHONY : all clean fclean re
