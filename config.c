/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:05:30 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/29 17:46:29 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	print_map(t_map *map)
{
	int row;
	int col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->columns)
		{
			//printf("%c", map->map_content[row][col]);
			col++;
		}
		row++;
	}
}
*/
void	set_map_values(t_map *map)
{
	int fd;
	char *line;
	int row;
	int col;
	int i;

	fd = open("maps/valid/map2.cub", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: file can not be open\n");
		return ;
	}
	line = get_next_line(fd);
	map->columns = ft_strlen(line);
	row = 0;
	while(line != NULL)
	{
		row++;
		line = get_next_line(fd);
	}
	map->rows = row;
	map->map_content = (char **)malloc(sizeof(char *) * (map->rows + 1));
	close(fd);
	fd = open("maps/valid/map2.cub", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: file can not be open\n");
		return ;
	}
	row = 0;
	while(row < map->rows)
	{
		col = 0;
		i = 0;
		line = get_next_line(fd);
		map->map_content[row] = malloc(sizeof(char) * (ft_strlen(line + 1)));
		while (col < (int)ft_strlen(line))
		{
			map->map_content[row][col] = line[i];
			i++;
			col++;
		}
		row++;
	}
	//print_map(map);
	map->time = 0;
	map->oldTime = 0;
}

void	set_player_values(t_player *player)
{
	player->posX = 2;
	player->posY = 2;
	player->dirX = 0;
	player->dirY = 1;
	player->planeX = 0.66;
	player->planeY = 0.00;
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

void	set_structs(t_player *p, t_img *img, t_ray *ray, t_draw *draw)
{
	ft_memset(p->ray, 0, sizeof(t_ray));
	ft_memset(p->img, 0, sizeof(t_img));
	ft_memset(p->draw, 0, sizeof(t_draw));
	ft_memset(p, 0, sizeof(t_player));
	p->img = img;
	p->ray = ray;
	p->draw = draw;
}

void	ft_free(char **premap)
{
	int	i;

	i = 0;
	while (premap[i] != NULL)
	{
		free(premap[i]);
		i++;
	}
	free(premap);
	premap = NULL;
}
/*
void	ft_init_player_dir(t_player *player)
{
	if (player->map == 'N')
	{
		player->dirX = -1.0;
		player->planeY = 0.66;
	}
	else if (player->map == 'S')
	{
		player->dirX = 1.0;
		player->planeY = -0.66;
	}
	else if (player->map == 'W')
	{
		player->dirY = -1.0;
		player->planeX = -0.66;
	}
	else if (player->map == 'E')
	{
		player->dirY = 1.0;
		player->planeX = 0.66;
	}
}*/

