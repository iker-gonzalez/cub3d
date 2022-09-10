/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:17:38 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/10 16:30:11 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_calculate_draw_values(t_player *p)
{
	p->draw->lineHeight = (int)(WIN_HEIGHT / p->ray->perpWallDist);
	p->draw->drawStart = -p->draw->lineHeight / 2 + WIN_HEIGHT / 2;
	if (p->draw->drawStart < 0)
		p->draw->drawStart = 0;
	p->draw->drawEnd = p->draw->lineHeight / 2 + WIN_HEIGHT / 2;
	if (p->draw->drawEnd >= WIN_HEIGHT)
		p->draw->drawEnd = WIN_HEIGHT - 1;
	//printf("drawStart: %d\n", p->draw->drawStart);
	//printf("drawEnd: %d\n", p->draw->drawEnd);
}

void	ft_calculate_texture_x_coordinate(t_player *p)
{
	int	x;

	if (p->ray->side == 0)
		p->ray->wallX = p->posY + p->ray->perpWallDist * p->ray->rayDirY;
	else
		p->ray->wallX = p->posX + p->ray->perpWallDist * p->ray->rayDirX;
	p->ray->wallX -= floor((p->ray->wallX));
	x = p->ray->wallX * (double)(TEXTURE_WIDTH);
	p->ray->texX = (int)x;
	if (p->ray->side == 0 && p->ray->rayDirX > 0)
		p->ray->texX = TEXTURE_WIDTH - p->ray->texX - 1;
	if (p->ray->side == 1 && p->ray->rayDirY < 0)
		p->ray->texX = TEXTURE_WIDTH - p->ray->texX - 1;
}

void	ft_draw_wall(t_player *p, int *y, double *step, double *tex_pos)
{
	p->ray->texY = (int)(*tex_pos) & (TEXTURE_HEIGHT - 1);
	(*tex_pos) += (*step);
	if (p->ray->side == 0)
	{
		if (p->ray->rayDirX < 0)
			my_img_pixel_put(p, p->map->current_col, (*y),
				p->text->pixels[NO_TEXTURE][p->ray->texX][p->ray->texY]);
		else
			my_img_pixel_put(p, p->map->current_col, (*y),
				p->text->pixels[SO_TEXTURE][p->ray->texX][p->ray->texY]);
	}
	else
	{
		if (p->ray->rayDirY < 0)
			my_img_pixel_put(p, p->map->current_col, (*y),
				p->text->pixels[WE_TEXTURE][p->ray->texX][p->ray->texY]);
		else
			my_img_pixel_put(p, p->map->current_col, (*y),
				p->text->pixels[EA_TEXTURE][p->ray->texX][p->ray->texY]);
	}
}

void	ft_paint_pixels(t_player *p)
{
	double	step;
	int		y;
	double	tex_pos;

	step = 1.0 * TEXTURE_HEIGHT / p->draw->lineHeight;
	tex_pos = (p->draw->drawStart - WIN_HEIGHT / 2
			+ p->draw->lineHeight / 2) * step;
	y = 0;
	while (y < p->draw->drawStart)
	{
		my_img_pixel_put(p, p->map->current_col, y,
			create_trgb(NO_TRANSPARENCY, 0, 255, 255));
		y++;
	}
	while (y < p->draw->drawEnd)
	{
		ft_draw_wall(p, &y, &step, &tex_pos);
		y++;
	}
	while (y < WIN_HEIGHT)
		my_img_pixel_put(p, p->map->current_col, y++,
			create_trgb(NO_TRANSPARENCY, 255, 255, 255));
}

int	raycasting_loop(t_player *p)
{
	static int images;

	p->map->current_col = 0;
	mlx_clear_window(p->mlx->mlx, p->mlx->mlx_win);
	while (p->map->current_col < WIN_WIDTH)
	{
		ft_ray_position_direction(p);
		ray_map_coordinates(p);
		ft_calculate_delta_distance(p);
		ft_calculate_side_distance(p);
		dda_algorithm(p);
		ft_calculate_perp_distance(p);
		ft_calculate_draw_values(p);
		ft_calculate_texture_x_coordinate(p);
		ft_paint_pixels(p);
		p->map->current_col++;
	}
	printf("images: %d\n", images++);
	mlx_put_image_to_window(p->mlx->mlx, p->mlx->mlx_win, p->img->img, 0, 0);
	return (0);
}
