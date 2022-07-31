/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:17:38 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/31 12:23:52 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_calculate_drawValues(t_ray *ray, t_draw *draw)
{
	//Calculate height of line to draw on screen
	draw->lineHeight = (int)(WIN_HEIGHT/ ray->perpWallDist);

	//calculate lowest and highest pixel to fill in current stripe
	draw->drawStart = -draw->lineHeight / 2 + WIN_HEIGHT / 2;
	if(draw->drawStart < 0)
		draw->drawStart = 0;
	draw->drawEnd = draw->lineHeight / 2 + WIN_HEIGHT / 2;
	if(draw->drawEnd >= WIN_HEIGHT)
		draw->drawEnd = WIN_HEIGHT - 1;
}