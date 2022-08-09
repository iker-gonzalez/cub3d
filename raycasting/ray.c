/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:23:26 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/09 18:07:42 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//calculate ray position and direction
void	ft_ray_position_direction(t_map *map, t_player *player, t_ray *ray, int i)
{
	ray->cameraX = 2 * i / (double)WIN_WIDTH - 1; //x-coordinate in camera space
	ray->rayDirX = player->dirX + player->planeX * ray->cameraX;
	ray->rayDirY = player->dirY + player->planeY * ray->cameraX;
}

//mapX and mapY represent the current square of the map the ray is in.
void	ray_map_coordinates(t_ray *ray, t_player *player)
{
	ray->mapX = (int)player->posX;
	ray->mapY = (int)player->posY;
}

//formula to calculate delta distance
void	ft_calculate_delta_distance(t_ray *ray)
{
	//If rayDirX or rayDirY are 0, the division through zero is avoided by setting it to a very high value
	if (ray->rayDirX == 0)
		ray->deltaDistX = INFINITY;
	else
		//length of ray from one x-side to next x-side
		ray->deltaDistX = sqrt(1 + (ray->rayDirY * ray->rayDirY) / (ray->rayDirX * ray->rayDirX));
		
	if (ray->rayDirY == 0)
		ray->deltaDistY = INFINITY;
	else
		//length of ray from one y-side to next y-side
		ray->deltaDistY = sqrt(1 + (ray->rayDirX * ray->rayDirX) / (ray->rayDirY * ray->rayDirY));
	//printf("deltaX: %f\n", ray->deltaDistX);
	//printf("deltaY: %f\n", ray->deltaDistY );
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
	//printf("sideY: %f\n", ray->sideDistY);
	//printf("sideX: %f\n", ray->sideDistX);
}

void	dda_algorithm(t_map *map, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		//Check if ray has hit a wall
		printf("ray->mapx: %d\n", ray->mapX);
		printf("ray->mapy: %d\n", ray->mapY);
		printf("%d\n", map->map_content[ray->mapX][ray->mapY]);
		if (map->map_content[ray->mapX][ray->mapY] > 48)
		{
			ray->hit = 1;
		}
	}
	printf("=================\n");
}
