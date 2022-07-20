/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:05:30 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/20 18:53:52 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
111111
100001
100001
111111
*/

void	set_values(t_map *map, t_player *player)
{
	player->posX = 4;
	player->posY = 3;

	map->columns = 6;
	map->rows = 4;

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