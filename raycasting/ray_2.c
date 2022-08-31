/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:24:30 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/31 17:35:18 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_calculate_perp_distance(t_player *p)
{
	if (p->ray->side == 0)
		p->ray->perpWallDist = (p->ray->sideDistX - p->ray->deltaDistX);
	else
		p->ray->perpWallDist = (p->ray->sideDistY - p->ray->deltaDistY);
}
