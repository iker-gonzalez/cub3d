/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:23:26 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/31 17:34:13 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_ray_position_direction(t_player *p)
{
	p->ray->cameraX = 2 * p->map->current_col / (double)WIN_WIDTH - 1;
	p->ray->rayDirX = p->dirX + p->planeX * p->ray->cameraX;
	p->ray->rayDirY = p->dirY + p->planeY * p->ray->cameraX;
}

void	ray_map_coordinates(t_player *p)
{
	p->ray->mapX = (int)p->posX;
	p->ray->mapY = (int)p->posY;
}

void	ft_calculate_delta_distance(t_player *p)
{
	if (p->ray->rayDirX == 0)
		p->ray->deltaDistX = INFINITY;
	else
		p->ray->deltaDistX = fabs(1 / p->ray->rayDirX);
	if (p->ray->rayDirY == 0)
		p->ray->deltaDistY = INFINITY;
	else
		p->ray->deltaDistY = fabs(1 / p->ray->rayDirY);
}

void	ft_calculate_side_distance(t_player *p)
{
	if (p->ray->rayDirX < 0)
	{
		p->ray->stepX = -1;
		p->ray->sideDistX = (p->posX - p->ray->mapX) * p->ray->deltaDistX;
	}
	else
	{
		p->ray->stepX = 1;
		p->ray->sideDistX = (p->ray->mapX + 1.0 - p->posX) * p->ray->deltaDistX;
	}
	if (p->ray->rayDirY < 0)
	{
		p->ray->stepY = -1;
		p->ray->sideDistY = (p->posY - p->ray->mapY) * p->ray->deltaDistY;
	}
	else
	{
		p->ray->stepY = 1;
		p->ray->sideDistY = (p->ray->mapY + 1.0 - p->posY) * p->ray->deltaDistY;
	}
}

void	dda_algorithm(t_player *p)
{
	p->ray->hit = 0;
	while (p->ray->hit == 0)
	{
		if (p->ray->sideDistX < p->ray->sideDistY)
		{
			p->ray->sideDistX += p->ray->deltaDistX;
			p->ray->mapX += p->ray->stepX;
			p->ray->side = 0;
		}
		else
		{
			p->ray->sideDistY += p->ray->deltaDistY;
			p->ray->mapY += p->ray->stepY;
			p->ray->side = 1;
		}
		if (p->map->map_content[p->ray->mapX][p->ray->mapY] == 49)
			p->ray->hit = 1;
	}
}
