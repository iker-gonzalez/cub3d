/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/30 11:33:14 by ikgonzal         ###   ########.fr       */
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
	int i;
	
	file_config(&map, &player);
	mlx.mlx = mlx_init();
	if (ft_validate_xpm(&map, &mlx, &text))
	{
		printf("Error: invalid xpm\n");
		return (1);
	}
	//mlx_config(&mlx);
	text.pixels = (int ***)malloc(sizeof(int **) * (NB_TEXTURES + 1));
	//ft_validate_xpm(&map, &mlx, &text);
	xpm_parser(map.no_texture, &map, &text, NO_TEXTURE);
	xpm_parser(map.ea_texture, &map, &text, EA_TEXTURE);
	xpm_parser(map.so_texture, &map, &text, SO_TEXTURE);
	xpm_parser(map.we_texture, &map, &text, WE_TEXTURE);
	
	//i = -1;
	/*while (1)
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
	}*/
	//mlx_loop(mlx.mlx);
	return (0);
}