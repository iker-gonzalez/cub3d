/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:07:00 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/31 08:32:55 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <unistd.h>
#include <math.h>
#include "mlx/mlx.h"
#include <stdio.h>
#include <fcntl.h>

#define GAME_TITLE "🤬 WOLPAPASTEIN 🤬"

#define NO_TEXTURE 0
#define EA_TEXTURE 1
#define SO_TEXTURE 2
#define WE_TEXTURE 3

# define FOV 66
# define WIN_WIDTH 960
# define WIN_HEIGHT 600

# define NO_TRANSPARENCY 0x00
# define NB_TEXTURES 4
# define TEXTURE_SIZE 64
# define UPPERCASE_DIGIT_DIFF 55
# define LOWERCASE_DIGIT_DIFF 55

//info for each texture xpm
typedef	struct s_text
{
	int		columns;
	int		rows;
	int		file_rows;
	int		nb_colors;
	char	**pixels_map;
	char	**colors;
	int		***pixels;
}				t_text;

//struct for mlx
typedef struct s_mlx
{	
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

//struct for drawing pixels
typedef struct s_draw
{
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
}				t_draw;

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
	//used to calculate the lenght of the ray
	double	perpWallDist;
	//determined by the ray's direction x component (either +1 or -1)
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

//initial config
void	set_map_values(t_map *map); //fictional values
void	set_player_values(t_player *player);
void	file_config(t_map *map, t_player *player);

//raycasting functions
void	ft_ray_position_direction(t_map *map, t_player *player, t_ray *ray);
void	ray_map_coordinates(t_ray *ray, t_player *player);
void	ft_calculate_delta_distance(t_ray *ray);
void	ft_calculate_side_distance(t_ray *ray, t_player *player);
void	dda_algorithm(t_map *map, t_ray *ray);
void	ft_calculate_perpDistance(t_ray *ray);

//drawing functions
void	ft_calculate_drawValues(t_ray *ray, t_draw *draw);

//mlx functions
void	mlx_config(t_mlx *mlx);

//textures
int		ft_validate_xpm(t_map *map, t_mlx *mlx, t_text *text);
int		create_trgb(int t, int r, int g, int b);
void	xpm_parser(char *texture_path, t_map *map, t_text *text, int text_nb);


#endif