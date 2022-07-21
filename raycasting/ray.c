/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:23:26 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/21 18:57:32 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_ray_position_direction(t_map *map, t_player *player, t_ray *ray)
{
	int i;

	i = -1;
	while (++i < map->columns)
	{
		//calculate ray position and direction
		ray->cameraX = 2 * map->columns / map->columns - 1; //x-coordinate in camera space
		ray->rayDirX = ray->rayDirX + player->planeX * ray->cameraX;
		ray->rayDirY = ray->rayDirY + player->planeY * ray->cameraX;
	}
}

//mapX and mapY represent the current square of the map the ray is in.
void	ray_map_coordinates(t_ray *ray, t_player *player)
{
	ray->mapX = int(player->posX);
	ray->mapY = int(player->posY);
}

//calculate step and initial sideDist
void	ft_calculate_side_distance(t_ray *ray, t_player *player)
{
      if (ray->rayDirX < 0)
      {
        ray->stepX = -1;
		//length of ray from current player position to next x-side
        ray->sideDistX = (player->posX - ray->mapX) * ray->deltaDistX;
      }
      else
      {
        ray->stepX = 1;
		//length of ray from current player position to next x-side
        ray->sideDistX = (ray->mapX + 1.0 - player->posX) * ray->deltaDistX;
      }
      if (ray->rayDirY < 0)
      {
        ray->stepY = -1;
		//length of ray from current player position to next y-side
        ray->sideDistY = (player->posY - ray->mapY) * ray->deltaDistY;
      }
      else
      {
        ray->stepY = 1;
		//length of ray from current player position to next y-side
        ray->sideDistY = (ray->mapY + 1.0 - player->posY) * ray->deltaDistY;
      }
}

void	ft_calculate_delta_distance(t_ray *ray)
{
	//length of ray from one x-side to next x-side
	if (!ray->rayDirX)
		ray->deltaDistX = INFINITY;
	else
		ray->deltaDistX = abs(1/ray->rayDirX);
		
	//length of ray from one y-side to next y-side
	if (!ray->rayDirY)
		ray->deltaDistY = INFINITY;
	else
		ray->deltaDistY = abs(1/ray->rayDirY);
}