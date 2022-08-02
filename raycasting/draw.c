/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:17:38 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/02 18:00:52 by ikgonzal         ###   ########.fr       */
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

void	ft_calculate_texture_x_coordinate(t_ray *ray, t_player *player)
{
	//calculate value of wallX (where exactly the wall was hit)
	if (ray->side == 0)
		ray->wallX = player->posY + ray->perpWallDist * ray->rayDirY;
	else
		ray->wallX = player->posX + ray->perpWallDist * ray->rayDirX;
	ray->wallX -= floor((ray->wallX));

	//x coordinate on the texture
	ray->texX = ray->wallX * (double)(TEXTURE_WIDTH);
	if(ray->side == 0 && ray->rayDirX > 0)
		ray->texX = TEXTURE_WIDTH - ray->texX - 1;
	if(ray->side == 1 && ray->rayDirY < 0)
		ray->texX = TEXTURE_WIDTH - ray->texX - 1;
}

void	ft_paint_pixels(t_img *img, t_ray *ray, t_draw *draw, t_text *text)
{
	double step;
	int		y;

	// How much to increase the texture coordinate per screen pixel
	step = 1.0 * TEXTURE_HEIGHT / draw->lineHeight;
	// Starting texture coordinate
	double texPos;
	texPos = (draw->drawStart /*- pitch*/ - WIN_HEIGHT / 2 + draw->lineHeight / 2) * step;
	y = draw->drawStart;
	while (y < draw->drawEnd)
	{
		ray->textY = (int)texPos & (TEXTURE_HEIGHT - 1);
		texPos += step;
		my_img_pixel_put(img, ray->texX, ray->textY, text->pixels[NO_TEXTURE][ray->texX][ray->textY]);
		y++;
	}
	
}