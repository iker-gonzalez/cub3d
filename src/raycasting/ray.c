/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:23:26 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/14 19:58:43 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

void	ft_ray_position_direction(t_player *p)
{
	p->ray->camera_x = 2 * p->map->current_col / (double)WIN_WIDTH - 1;
	p->ray->ray_dir_x = p->dir_x + p->plane_x * p->ray->camera_x;
	p->ray->ray_dir_y = p->dir_y + p->plane_y * p->ray->camera_x;
}

void	ray_map_coordinates(t_player *p)
{
	p->ray->map_x = (int)p->pos_x;
	p->ray->map_y = (int)p->pos_y;
}

void	ft_calculate_delta_distance(t_player *p)
{
	if (p->ray->ray_dir_x == 0)
		p->ray->delta_dist_x = INFINITY;
	else
		p->ray->delta_dist_x = fabs(1 / p->ray->ray_dir_x);
	if (p->ray->ray_dir_y == 0)
		p->ray->delta_dist_y = INFINITY;
	else
		p->ray->delta_dist_y = fabs(1 / p->ray->ray_dir_y);
}

void	ft_calculate_side_distance(t_player *p)
{
	if (p->ray->ray_dir_x < 0)
	{
		p->ray->step_x = -1;
		p->ray->side_dist_x = (p->pos_x - p->ray->map_x) * p->ray->delta_dist_x;
	}
	else
	{
		p->ray->step_x = 1;
		p->ray->side_dist_x = (p->ray->map_x + 1.0 - p->pos_x)
			* p->ray->delta_dist_x;
	}
	if (p->ray->ray_dir_y < 0)
	{
		p->ray->step_y = -1;
		p->ray->side_dist_y = (p->pos_y - p->ray->map_y) * p->ray->delta_dist_y;
	}
	else
	{
		p->ray->step_y = 1;
		p->ray->side_dist_y = (p->ray->map_y + 1.0 - p->pos_y)
			* p->ray->delta_dist_y;
	}
}

void	dda_algorithm(t_player *p)
{
	p->ray->hit = 0;
	while (p->ray->hit == 0)
	{
		if (p->ray->side_dist_x < p->ray->side_dist_y)
		{
			p->ray->side_dist_x += p->ray->delta_dist_x;
			p->ray->map_x += p->ray->step_x;
			p->ray->side = 0;
		}
		else
		{
			p->ray->side_dist_y += p->ray->delta_dist_y;
			p->ray->map_y += p->ray->step_y;
			p->ray->side = 1;
		}
		if (p->map->map_content[p->ray->map_x][p->ray->map_y] == 49)
			p->ray->hit = 1;
	}
}
