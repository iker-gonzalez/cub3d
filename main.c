/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/07 14:48:20 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int clear_window(t_mlx *mlx, t_img *img)
{
	if (img->img)
		mlx_destroy_image(mlx->mlx, img->img);
	if (mlx->mlx && mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	return (0);
}

int main(int argc, char **argv)
{
	t_map map;
	t_player player;
	t_ray	ray;
	t_mlx	mlx;
	t_text	text;
	t_img img;
	t_draw draw;
	int i;
	
	ft_memset(&map, 0, sizeof(t_map));
	ft_memset(&player, 0, sizeof(t_player));
	ft_memset(&ray, 0, sizeof(t_ray));
	ft_memset(&mlx, 0, sizeof(t_mlx));
	ft_memset(&text, 0, sizeof(t_text));
	ft_memset(&img, 0, sizeof(t_img));
	ft_memset(&draw, 0, sizeof(t_draw));
	file_config(&map, &player);
	mlx.mlx = mlx_init();
	if (xpm_parser(&mlx, &map, &text))
		return (1);
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, GAME_TITLE);
	i = -1;
	//while (1)
	//{
		//raycasting loop
		init_new_img(&img, &mlx);
		while (++i < WIN_WIDTH)
		{
			ft_ray_position_direction(&map, &player, &ray, i);
			ray_map_coordinates(&ray, &player);
			ft_calculate_delta_distance(&ray);
			ft_calculate_side_distance(&ray, &player);
			dda_algorithm(&map, &ray);
			ft_calculate_perpDistance(&ray);
			ft_calculate_drawValues(&ray, &draw);
			ft_calculate_texture_x_coordinate(&ray, &player);
			ft_paint_pixels(&img, &ray, &draw, &text, i);
		}
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);
	//}
	//clear_window(&mlx, &img);
	mlx_loop(mlx.mlx);

	return (0);
}