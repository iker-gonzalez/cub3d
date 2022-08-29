/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:07:00 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/29 17:16:57 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <unistd.h>
#include <math.h>
#include "mlx/mlx.h"
#include <stdio.h>
#include <fcntl.h>

# define GAME_TITLE "🤬 WOLPAPASTEIN 🤬"
# define FOV 66
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

# define NO_TEXTURE 0
# define EA_TEXTURE 1
# define SO_TEXTURE 2
# define WE_TEXTURE 3

# define ESC_KEY_MAC 53
# define LEFT_ARR_MAC 123
# define UP_ARR_MAC 126
# define RIGHT_ARR_MAC 124
# define DOWN_ARR_MAC 125
# define A_KEY_MAC 0
# define W_KEY_MAC 13
# define D_KEY_MAC 2
# define S_KEY_MAC 1

# define NO_TRANSPARENCY 0x00
# define NB_TEXTURES 4
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

# define TURN_LEFT_COS 0.995
# define TURN_LEFT_SIN 0.0998
# define TURN_RIGHT_COS 0.995
# define TURN_RIGHT_SIN -0.0998



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
	int		current_col;
	int		render;
	int		render_2;
}				t_map;

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
	t_mlx	*mlx;
	t_map	*map;
	t_img	*img;
	t_ray	*ray;
	t_draw	*draw;
	t_text	*text;
}				t_player;

typedef struct s_tmp{
	int		y;
	size_t	x;
	size_t	max_x;
	int		fd;
	int		pos;
	int		spaces;
	int		map_y;
	char	*ln;
	char	**premap;
	char	**map;
	char	*no_path;
	char	*so_path;
	char	*ea_path;
	char	*we_path;
	char	*f_val;
	char	*c_val;
	char	player;
}	t_tmp;

//initial config
void	set_map_values(t_map *map); //fictional values
void	set_player_values(t_player *player);
void	file_config(t_map *map, t_player *player);

//raycasting functions
void	ft_ray_position_direction(t_player *p);
void	ray_map_coordinates(t_player *p);
void	ft_calculate_delta_distance(t_player *p);
void	ft_calculate_side_distance(t_player *p);
void	dda_algorithm(t_player *p);
void	ft_calculate_perpDistance(t_player *p);
void	ft_calculate_texture_x_coordinate(t_player *p);


//drawing functions
void	ft_calculate_drawValues(t_player *p);
void	init_new_img(t_player *p);
void	ft_paint_pixels(t_player *p);
void	my_img_pixel_put(t_player *p, int x, int y, int color);
void	ft_draw_floor_ceil(t_player *p);

//mlx functions
void	mlx_config(t_mlx *mlx);


//textures
int		ft_validate_xpm(char *path, void *mlx, t_text *text);
int		create_trgb(int t, int r, int g, int b);
int		xpm_parser(t_mlx *mlx, t_map *map, t_text *text);

void	print_values(t_ray *ray, t_draw *draw);

int		ft_hook(t_player *player);
int	raycasting_loop(t_player *p);

void	set_structs(t_player *p, t_img *img, t_ray *ray, t_draw *draw);

//moves
void	ft_move_up(t_player *player);
void	ft_move_down(t_player *player);
void	ft_move_right(t_player *player);
void	ft_move_left(t_player *player);

/* check errors */
void	ft_get_x(t_tmp *tmp);
void	ft_get_y(t_tmp *tmp);
int		ft_isstrprint(t_tmp *tmp);
int		ft_isstrspace(t_tmp *tmp);
int		ft_check_fchars(t_tmp *tmp);
void	ft_print_map(char **map);
void	ft_extract_map(t_tmp *tmp);
int		ft_fchar(char *line);
int		ft_isspace(char *line);
int		ft_check_extension(char *file);
int		ft_print_error(int errno, t_tmp *tmp);
void	ft_free(char **premap);
void	ft_check_mapchars(t_tmp *tmp);
void	ft_check_walls(t_tmp *tmp);
void	ft_walls_cases(t_tmp *tmp, int i, int j);
void	ft_check_player(t_tmp *tmp);
void	ft_headers(t_tmp *tmp);

#endif
