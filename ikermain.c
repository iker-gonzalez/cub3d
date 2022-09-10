
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

void ft_raycasting(t_player *p)
{
	p->mlx->mlx = mlx_init();
	if (xpm_parser(&p->mlx, &p->map, &p->text))
		exit (1);
	p->mlx->mlx_win = mlx_new_window(p->mlx->mlx, WIN_WIDTH, WIN_HEIGHT, GAME_TITLE);
	p->map->current_col = -1;
	init_new_img(&p);
	raycasting_loop(&p);
	ft_hook(&p);
	mlx_loop_hook(p->mlx->mlx, raycasting_loop, &p);
	mlx_loop(p->mlx->mlx);
}
