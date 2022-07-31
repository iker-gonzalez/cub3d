/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/31 10:33:39 by ikgonzal         ###   ########.fr       */
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
	mlx_config(&mlx);
	text.pixels = (int ***)malloc(sizeof(int **) * (NB_TEXTURES + 1));
	xpm_parser(map.no_texture, &map, &text, NO_TEXTURE);
	xpm_parser(map.ea_texture, &map, &text, EA_TEXTURE);
	xpm_parser(map.so_texture, &map, &text, SO_TEXTURE);
	xpm_parser(map.we_texture, &map, &text, WE_TEXTURE);
	printf("%d\n", text.pixels[SO_TEXTURE][59][61]);
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
	mlx_loop(mlx.mlx);
	return (0);
}