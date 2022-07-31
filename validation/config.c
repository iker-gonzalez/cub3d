/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:05:30 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/31 12:01:09 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
111111
100001
100001
111111
*/

void	set_map_values(t_map *map)
{
	map->columns = 6;
	map->rows = 4;
	map->time = 0;
	map->oldTime = 0;

	map->map_content = (char **)malloc(sizeof(char *) * (map->rows + 1));

	map->map_content[0] = malloc(sizeof(char) * (map->columns + 1));
	map->map_content[0][0] = 1;
	map->map_content[0][1] = 1;
	map->map_content[0][2] = 1;
	map->map_content[0][3] = 1;
	map->map_content[0][4] = 1;
	map->map_content[0][5] = 1;
	
	map->map_content[1] = malloc(sizeof(char) * (map->columns + 1));
	map->map_content[1][0] = 1;
	map->map_content[1][1] = 0;
	map->map_content[1][2] = 0;
	map->map_content[1][3] = 0;
	map->map_content[1][4] = 0;
	map->map_content[1][5] = 1;
	
	map->map_content[2] = malloc(sizeof(char) * (map->columns + 1));
	map->map_content[2][0] = 1;
	map->map_content[2][1] = 0;
	map->map_content[2][2] = 0;
	map->map_content[2][3] = 0;
	map->map_content[2][4] = 0;
	map->map_content[2][5] = 1;
	
	map->map_content[3] = malloc(sizeof(char) * (map->columns + 1));
	map->map_content[3][0] = 1;
	map->map_content[3][1] = 1;
	map->map_content[3][2] = 1;
	map->map_content[3][3] = 1;
	map->map_content[3][4] = 1;
	map->map_content[3][5] = 1;
}

void	set_player_values(t_player *player)
{
	player->posX = 4;
	player->posY = 3;
	player->dirX = -1;
	player->dirY = 0;
	player->planeX = 0;
	player->planeY = 0.66;
}

void	set_texture_paths(t_map	*map)
{
	map->no_texture = "textures/wall_1.xpm";
	map->ea_texture = "textures/wall_2.xpm";
	map->so_texture = "textures/wall_3.xpm";
	map->we_texture = "textures/wall_4.xpm";
}

void	file_config(t_map *map, t_player *player)
{
	set_map_values(map);
	set_player_values(player);
	set_texture_paths(map);
}
