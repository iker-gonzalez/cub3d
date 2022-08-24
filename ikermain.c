
#include "cub3d.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"

int clear_window(t_mlx *mlx, t_img *img)
{
	if (img->img)
		mlx_destroy_image(mlx->mlx, img->img);
	if (mlx->mlx && mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	return (0);
}

int main()
{
	t_map map;
	t_player p;
	t_ray	ray;
	t_mlx	mlx;
	t_text	text;
	t_img img;
	t_draw draw;
	
	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&p, 0, sizeof(t_player));
	ft_memset(&ray, 0, sizeof(t_ray));
	ft_memset(&mlx, 0, sizeof(t_mlx));
	ft_memset(&text, 0, sizeof(t_text));
	ft_memset(&img, 0, sizeof(t_img));
	ft_memset(&draw, 0, sizeof(t_draw));
	file_config(&map, &p);
	map.render_2 = 0;
	p.mlx = &mlx;
	p.map = &map;
	p.img = &img;
	p.ray = &ray;
	p.draw = &draw;
	p.text = &text;
	mlx.mlx = mlx_init();
	if (xpm_parser(&mlx, &map, &text))
		return (1);
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, GAME_TITLE);
	map.current_col = -1;
	//raycasting loop
	init_new_img(&p);
	//ft_draw_floor_ceil(&p);
	raycasting_loop(&p);
	//printf("current col: %d\n", map.current_col);
	//clear_window(&mlx, &img);
	ft_hook(&p);
	mlx_loop_hook(mlx.mlx, raycasting_loop, &p);
	mlx_loop(mlx.mlx);
	return (0);
}
