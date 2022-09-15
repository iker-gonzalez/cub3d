/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 11:24:30 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/10 20:50:53 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_calculate_perp_distance(t_player *p)
{
	if (p->ray->side == 0)
		p->ray->perp_wall_dist = (p->ray->side_dist_x - p->ray->delta_dist_x);
	else
		p->ray->perp_wall_dist = (p->ray->side_dist_y - p->ray->delta_dist_y);
}
