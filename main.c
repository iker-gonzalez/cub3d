/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/02 18:11:46 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		while (++i < map.columns)
		{
			ft_ray_position_direction(&map, &player, &ray, i);
			ray_map_coordinates(&ray, &player);
			ft_calculate_delta_distance(&ray);
			ft_calculate_side_distance(&ray, &player);
			dda_algorithm(&map, &ray);
			ft_calculate_perpDistance(&ray);
			ft_calculate_drawValues(&ray, &draw);
			ft_calculate_texture_x_coordinate(&ray, &player);
			ft_paint_pixels(&img, &ray, &draw, &text);
			mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);
		}
	//}
	mlx_loop(mlx.mlx);
	return (0);
}