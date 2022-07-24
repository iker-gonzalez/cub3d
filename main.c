/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/24 13:40:06 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_map map;
	t_player player;
	t_ray	ray;
	t_game	game;
	t_mlx	mlx;
	t_text	text;
	int i;
	
	file_config(&map, &player);
	mlx.mlx = mlx_init();
	ft_validate_xpm(&map, &mlx, &text);
	i = -1;
	game.on = 0;
	mlx_config(&mlx);
	while (!game.on)
	{
		//raycasting loop
		while (++i < map.columns)
		{
			ft_ray_position_direction(&map, &player, &ray);
			ray_map_coordinates(&ray, &player);
			ft_calculate_delta_distance(&ray);
			ft_calculate_side_distance(&ray, &player);
			ft_calculate_perpDistance(&ray);
		}
	}
	mlx_loop(mlx.mlx);
	return (0);
}