/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:07:00 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/21 18:34:49 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <math.h>

# define FOV 66
# define WIN_WIDTH 320
# define WIN_HEIGHT 200

typedef struct s_ray {
	//cameraX is the x-coordinate on the camera plane that the current x-coordinate of the screen represents (-1 left, 0 front, 1 right).
	double	cameraX;
	//direction vector on both coordinates x and y.
	double	rayDirX;
	double	rayDirY;
	//mapX and mapY represent the current square of the map the ray is in.
	int		mapX;
	int		mapY;
	//the distance the ray has to travel from its start position to the first x-side and the first y-side.
	double	sideDistX;
	double	sideDistY;
	//the distance the ray has to travel to go from 1 x-side to the next x-side, or from 1 y-side to the next y-side.
	double	deltaDistX;
	double	deltaDistY;
	//what direction to step in x or y-direction (either +1 or -1)
	int stepX;
	int stepY;
	//was there a wall hit? (0, 1)
	int hit;
	//was a NS (0) or a EW (1) wall hit?
	int side;
}				t_ray;

typedef struct s_player {
	double	posX;
	double	posY;
	//direction vector (-1 left; 0 straight; 1 right)
	double	dirX;
	double	dirY;
	//plane vector determines the FOV of the player
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
	//The variables time and oldTime will be used to store the time of the current and the previous frame,
	//the time difference between these two can be used to determinate how much you should move when a certain key is pressed (to move a
	//constant speed no matter how long the calculation of the frames takes), and for the FPS counter.
	double	time;
	double	oldTime;
}				t_map;


void	set_values(t_map *map); //fictional values
void	set_player_values(t_player *player);
void	set_ray_values(t_ray *ray);





#endif