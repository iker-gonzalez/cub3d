/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:07:00 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/07 14:48:10 by ikgonzal         ###   ########.fr       */
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

# define GAME_TITLE "🤬 WOLPAPASTEIN 🤬"

# define NO_TEXTURE 0
# define EA_TEXTURE 1
# define SO_TEXTURE 2
# define WE_TEXTURE 3

# define FOV 66
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define NO_TRANSPARENCY 0x00
# define NB_TEXTURES 4
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

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

//struct for img
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

//struct for mlx
typedef struct s_mlx
{	
	void	*mlx;
	void	*mlx_win;
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
	//the distance the ray has to travel to go from 1 x-side to the next x-side, or from 1 y-side to the next y-side intersection.
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
	//represents the exact value where the wall was hit, not just the integer coordinates of the wall. 
	double wallX;
	//x-coordinate of the texture we have to use
	int texX;
	//y-coordinate of the texture we have to use
	int texY;
}				t_ray;

typedef struct s_player {
	// represent the position vector of the player
	double	posX;
	double	posY;
	// initial direction vector (-1 left; 0 straight; 1 right)
	double	dirX;
	double	dirY;
	// plane vector determines the FOV of the player
	double	planeX;
	double	planeY;
}				t_player;


typedef struct s_map {
	char *no_texture;
	char *ea_texture;
	char *so_texture;
	char *we_texture;
	char *f_color;
	char *c_color;
	int columns;
	int rows;
	char** map_content;
	//the time difference between these two can be used to determinate how much you should move when a certain key is pressed (to move a
	//constant speed no matter how long the calculation of the frames takes), and for the frames per second (FPS) counter.
	double	time; // time of current frame
	double	oldTime; // time of previous frame
}				t_map;

//initial config
void	set_map_values(t_map *map); //fictional values
void	set_player_values(t_player *player);
void	file_config(t_map *map, t_player *player);

//raycasting functions
void	ft_ray_position_direction(t_map *map, t_player *player, t_ray *ray, int i);
void	ray_map_coordinates(t_ray *ray, t_player *player);
void	ft_calculate_delta_distance(t_ray *ray);
void	ft_calculate_side_distance(t_ray *ray, t_player *player);
void	dda_algorithm(t_map *map, t_ray *ray);
void	ft_calculate_perpDistance(t_ray *ray);
void	ft_calculate_texture_x_coordinate(t_ray *ray, t_player *player);


//drawing functions
void	ft_calculate_drawValues(t_ray *ray, t_draw *draw);
void	init_new_img(t_img *img, t_mlx *mlx);
void	ft_paint_pixels(t_img *img, t_ray *ray, t_draw *draw, t_text *text, int x);
void	my_img_pixel_put(t_img *img, int x, int y, int color);


//mlx functions
void	mlx_config(t_mlx *mlx);


//textures
int		ft_validate_xpm(char *path, void *mlx, t_text *text);
int		create_trgb(int t, int r, int g, int b);
int		xpm_parser(t_mlx *mlx, t_map *map, t_text *text);

void	print_values(t_ray *ray, t_draw *draw);

#endif