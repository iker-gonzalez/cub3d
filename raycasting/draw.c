/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:17:38 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/24 19:48:09 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_calculate_drawValues(t_player *p)
{
	//Calculate height of line to draw on screen
	p->draw->lineHeight = (int)(WIN_HEIGHT/ p->ray->perpWallDist);
	//printf("line->height: %d\n", draw->lineHeight);
	//calculate lowest and highest pixel to fill in current stripe
	p->draw->drawStart = -p->draw->lineHeight / 2 + WIN_HEIGHT / 2;
	
	if(p->draw->drawStart < 0)
		p->draw->drawStart = 0;

	p->draw->drawEnd = p->draw->lineHeight / 2 + WIN_HEIGHT / 2;
	if(p->draw->drawEnd >= WIN_HEIGHT)
		p->draw->drawEnd = WIN_HEIGHT - 1;
}

void	ft_calculate_texture_x_coordinate(t_player *p)
{
	int x;
	//calculate value of wallX (where exactly the wall was hit)
	if (p->ray->side == 0)
		p->ray->wallX = p->posY + p->ray->perpWallDist * p->ray->rayDirY;
	else
		p->ray->wallX = p->posX + p->ray->perpWallDist * p->ray->rayDirX;
	p->ray->wallX -= floor((p->ray->wallX));

	//x coordinate on the texture
	x = p->ray->wallX * (double)(TEXTURE_WIDTH);
	p->ray->texX = (int)x;
	if(p->ray->side == 0 && p->ray->rayDirX > 0)
		p->ray->texX = TEXTURE_WIDTH - p->ray->texX - 1;
	if(p->ray->side == 1 && p->ray->rayDirY < 0)
		p->ray->texX = TEXTURE_WIDTH - p->ray->texX - 1;
	//printf("ray->texX: %d\n", ray->texX);
}

void	ft_paint_pixels(t_player *p)
{
	double step;
	int		y;

	// How much to increase the texture coordinate per screen pixel
	step = 1.0 * TEXTURE_HEIGHT / p->draw->lineHeight;
	//printf("step: %f\n", step);
	// Starting texture coordinate
	double texPos;
	texPos = (p->draw->drawStart - WIN_HEIGHT / 2 + p->draw->lineHeight / 2) * step;
	//printf("texPos: %f\n", texPos);
	y = 0;
	//printf("drawStart: %d\n", p->draw->drawStart);
	//printf("img: %d\n", p->img->img);
	
	while (y < p->draw->drawStart)
	{
		my_img_pixel_put(p, p->map->current_col, y, create_trgb(NO_TRANSPARENCY, 0, 255, 255));
		y++;
		//printf("y: %d\n", y);
	}
	//printf("drawStart: %d\n", p->draw->drawStart);
	//printf("drawEnd: %d\n", p->draw->drawEnd);
	while (y < p->draw->drawEnd)
	{
		p->ray->texY = (int)texPos & (TEXTURE_HEIGHT - 1);
		//printf("ray->texY: %d\n", ray->texY);
		texPos += step;
		//printf("ray->texX: %d\n", ray->texX);
		//printf("ray->texY: %d\n", ray->texY);
		if (p->ray->side == 0)
		{
			if (p->ray->rayDirX < 0)
				my_img_pixel_put(p, p->map->current_col, y, p->text->pixels[NO_TEXTURE][p->ray->texX][p->ray->texY]);
			else
				my_img_pixel_put(p, p->map->current_col, y, p->text->pixels[SO_TEXTURE][p->ray->texX][p->ray->texY]);
		}
		else
		{
			if (p->ray->rayDirY < 0)
				my_img_pixel_put(p, p->map->current_col, y, p->text->pixels[WE_TEXTURE][p->ray->texX][p->ray->texY]);
			else
				my_img_pixel_put(p, p->map->current_col, y, p->text->pixels[EA_TEXTURE][p->ray->texX][p->ray->texY]);
		}
		y++;
	}
	while (y < WIN_HEIGHT)
		my_img_pixel_put(p, p->map->current_col, y++, create_trgb(NO_TRANSPARENCY, 96, 96, 96));
}

void	ft_draw_floor_ceil(t_player *p)
{
	int i;
	int k;

	k = 0;
	while (k < WIN_WIDTH)
	{
		i = 0;
		printf("k: %d\n", k);
		while (i < (WIN_HEIGHT / 2))
		{
			printf("i: %d\n", i);
			my_img_pixel_put(p, k, i, create_trgb(NO_TRANSPARENCY, 0, 255, 255));
			i++;
		}
		while (i < WIN_HEIGHT)
		{
			my_img_pixel_put(p, k, i, create_trgb(NO_TRANSPARENCY, 96, 96, 96));
			i++;
		}
		k++;
	}
}

int	raycasting_loop(t_player *p)
{
	p->map->current_col = 0;
	mlx_clear_window(p->mlx->mlx, p->mlx->mlx_win);
	while (p->map->current_col < WIN_WIDTH)
	{
		//printf("=================\n");
		ft_ray_position_direction(p);
		ray_map_coordinates(p);
		ft_calculate_delta_distance(p);
		ft_calculate_side_distance(p);
		dda_algorithm(p);
		ft_calculate_perpDistance(p);
		ft_calculate_drawValues(p);
		ft_calculate_texture_x_coordinate(p);
		ft_paint_pixels(p);
		p->map->current_col++;
	}
	mlx_put_image_to_window(p->mlx->mlx, p->mlx->mlx_win, p->img->img, 0, 0);
	return (0);
}

