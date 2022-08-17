/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:24:30 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/16 18:53:20 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_calculate_perpDistance(t_player *p)
{
	//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	if(p->ray->side == 0)
		p->ray->perpWallDist = (p->ray->sideDistX - p->ray->deltaDistX);
	else
		p->ray->perpWallDist = (p->ray->sideDistY - p->ray->deltaDistY);
	//printf("ray->perpWallDist: %f\n", ray->perpWallDist);
}