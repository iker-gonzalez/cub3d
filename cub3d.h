/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:07:00 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/25 20:40:37 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <unistd.h>
#include <stdio.h>

# define NO_TEXTURE 0
# define EA_TEXTURE 1
# define SO_TEXTURE 2
# define WE_TEXTURE 3

typedef struct s_data{
	int y;
	size_t x;
	int fd;
}	t_data;

typedef struct s_map {
	char* no_texture;
	char* ea_texture;
	char* so_texture;
	char* we_texture;
	char* f_color;
	char* c_color;
	int columns;
	int rows;
	char** map_content;
}	t_map;

int	ft_check_extension(char *file);



#endif
