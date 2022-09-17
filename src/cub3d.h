/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:07:00 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/17 12:18:22 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>

# define GAME_TITLE "🤬 WOLPAPASTEIN 🤬"
# define FOV 66
# define WIN_WIDTH 1280
# define WIN_HEIGHT 960

# define NO_TEXTURE 0
# define EA_TEXTURE 1
# define SO_TEXTURE 2
# define WE_TEXTURE 3

# define ESC_KEY_LINUX 65307
# define LEFT_ARR_LINUX 65361
# define RIGHT_ARR_LINUX 65363
# define A_KEY_LINUX 97
# define W_KEY_LINUX 119
# define D_KEY_LINUX 100
# define S_KEY_LINUX 115

# define ESC_KEY_MAC 53
# define LEFT_ARR_MAC 123
# define RIGHT_ARR_MAC 124
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
typedef struct s_text
{
	int		columns;
	int		rows;
	int		file_rows;
	int		nb_colors;
	char	**pixels_map;
	char	**colors;
	int		***pixels;
	int		valid_text;
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
	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_draw;

typedef struct s_ray {
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	wall_x;
	int		tex_x;
	int		tex_y;
}				t_ray;

typedef struct s_map {
	char	*no_texture;
	char	*ea_texture;
	char	*so_texture;
	char	*we_texture;
	int		**f_color;
	int		**c_color;
	int		columns;
	int		rows;
	char	player;
	double	player_x;
	double	player_y;
	char	**map_content;
	double	time;
	double	old_time;
	int		current_col;
	int		render;
	int		render_2;
}				t_map;

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
	int		**f_int;
	int		**c_int;
	char	player;
	char	rgb;
	int		player_x;
	int		player_y;
	int		err;
}	t_tmp;

typedef struct s_player {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	t_mlx	*mlx;
	t_map	*map;
	t_img	*img;
	t_ray	*ray;
	t_draw	*draw;
	t_text	*text;
	t_tmp	*tmp;
}				t_player;

//initial config
void	set_map_values(t_map *map);
void	set_player_values(t_player *player);
void	file_config(t_map *map, t_player *player);

//raycasting functions
void	ft_ray_position_direction(t_player *p);
void	ray_map_coordinates(t_player *p);
void	ft_calculate_delta_distance(t_player *p);
void	ft_free_tmp(char *no, char *so, char *ea, char *we);
void	ft_calculate_side_distance(t_player *p);
void	dda_algorithm(t_player *p);
void	ft_calculate_perp_distance(t_player *p);
void	ft_calculate_texture_x_coordinate(t_player *p);

//drawing functions
void	ft_calculate_draw_values(t_player *p);
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
void	ft_extract_colors_nb(char *line, t_text *text, int end);
void	ft_skip_to_color_nb(char *line, t_text *text);
int		ft_hex_to_int(char *color);
void	ft_parse_pixel_column(t_text *text, int col, int text_nb);
void	ft_fill_pixels(t_text *text, int text_nb);
void	ft_create_pixels_array(t_text *text, int fd);
void	ft_fill_colors(t_text *text, int text_nb, int fd);
void	parse_xpm(char *texture_path, t_text *text, int text_nb);

int		ft_hook(t_player *player);
int		raycasting_loop(t_player *p);
void	ft_raycasting(t_player *p);

void	set_structs(t_player *p, t_img *img, t_ray *ray, t_draw *draw);
void	ft_free_colors(t_text *text, int nb_colors);
void	ft_free_pixels_map(t_text *text, int text_rows);
void	ft_free_pixels(t_text *text, int text_columns);
void	ft_free_structs(t_player *p);

//moves
void	ft_move_up(t_player *player);
void	ft_move_down(t_player *player);
void	ft_free_tmp(char *no, char *so, char *ea, char *we);
void	ft_move_right(t_player *player);
void	ft_move_left(t_player *player);
void	ft_turn_right(t_player *p);
void	ft_turn_left(t_player *p);

/* initialiatations */
void	ft_init_int(t_tmp *tmp);
void	ft_init_structs(t_player *p);
void	ft_init_tmp(t_tmp *tmp, t_map *map);
void	ft_init_player_dir(t_player *player);

/* check errors */
void	ft_get_x(t_player *p);
void	ft_get_y(t_player *p);
int		ft_isstrprint(t_tmp *tmp);
int		ft_isstrspace(t_tmp *tmp);
int		ft_check_fchars(t_tmp *tmp);
void	ft_print_map(char **map);
void	ft_extract_map(t_player *p);
int		ft_fchar(char *line);
int		ft_isspace(char *line);
int		ft_check_extension(char *file);
void	ft_print_error(int errno, t_player *p);
void	ft_free(char **premap);
void	ft_check_mapchars(t_player *p);
void	ft_check_walls(t_player *p);
void	ft_walls_cases(t_player *p, int i, int j);
void	ft_check_player(t_player *p);
void	ft_headers(t_player *p);
void	ft_change_struct(t_tmp *tmp, t_map *map);
void	ft_free_int(int **array);
void	ft_free_all(t_player *p);
void	ft_free_texture(t_player *p);
void	ft_free_int_errors(t_player *p);
void	ft_free_errors(t_player *p);
void	ft_free_value(char **line, t_player *p, char **str);
int		ft_check_l(char *l);
void	ft_free_last(char **line, t_player *p);

#endif
