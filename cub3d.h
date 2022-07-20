/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:07:00 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/20 18:47:04 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>

# define FOV 66
# define WIN_WIDTH 320
# define WIN_HEIGHT 200

typedef struct s_player {
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}				t_player;


typedef struct s_map {
	char* no_texture;
	char* ea_texture;
	char* so_texture;
	char *we_texture;
	char *f_color;
	char *c_color;
	int columns;
	int rows;
	char** map_content;
	double	time;
	double	oldTime;
}				t_map;


void	set_values(t_map *map, t_player *player); //fictional values



#endif