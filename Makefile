# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/04 16:17:30 by ikgonzal          #+#    #+#              #
#    Updated: 2022/07/04 17:04:34 by ikgonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3d

FLAGS =	-Wall -Wextra -Werror

SRC  =	main.c \
		error.c \

LIB = Libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -s -C ./libft
	@$(MAKE) -s -C ./libft bonus
	@ echo "libft compiled 🔋"
	@$(MAKE) -s -C ./minilibx
	@ echo "minilibx compiled 📇"
	$(CC) $(FLAGS) $(LIB) $(OBJ) -o $(NAME)
	@ echo "cub3d compiled 🧊"

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
