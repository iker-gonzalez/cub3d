/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/31 13:08:50 by ikgonzal         ###   ########.fr       */
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
	int i;
	
	file_config(&map, &player);
	mlx.mlx = mlx_init();
	text.pixels = (int ***)malloc(sizeof(int **) * (NB_TEXTURES + 1));
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
			ft_calculate_perpDistance(&ray);
			//ft_paint_pixel()
		}
	//}
	mlx_loop(mlx.mlx);
	return (0);
}