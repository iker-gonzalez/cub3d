/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:17:38 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/15 16:01:10 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>
#include "../../mlx/mlx.h"

void	ft_calculate_draw_values(t_player *p)
{
	p->draw->line_height = (int)(WIN_HEIGHT / p->ray->perp_wall_dist);
	p->draw->draw_start = -p->draw->line_height / 2 + WIN_HEIGHT / 2;
	if (p->draw->draw_start < 0)
		p->draw->draw_start = 0;
	p->draw->draw_end = p->draw->line_height / 2 + WIN_HEIGHT / 2;
	if (p->draw->draw_end >= WIN_HEIGHT)
		p->draw->draw_end = WIN_HEIGHT - 1;
}

void	ft_calculate_texture_x_coordinate(t_player *p)
{
	int	x;

	if (p->ray->side == 0)
		p->ray->wall_x = p->pos_y + p->ray->perp_wall_dist * p->ray->ray_dir_y;
	else
		p->ray->wall_x = p->pos_x + p->ray->perp_wall_dist * p->ray->ray_dir_x;
	p->ray->wall_x -= floor((p->ray->wall_x));
	x = p->ray->wall_x * (double)(TEXTURE_WIDTH);
	p->ray->tex_x = (int)x;
	if (p->ray->side == 0 && p->ray->ray_dir_x > 0)
		p->ray->tex_x = TEXTURE_WIDTH - p->ray->tex_x - 1;
	if (p->ray->side == 1 && p->ray->ray_dir_y < 0)
		p->ray->tex_x = TEXTURE_WIDTH - p->ray->tex_x - 1;
}

void	ft_draw_wall(t_player *p, int *y, double *step, double *tex_pos)
{
	p->ray->tex_y = (int)(*tex_pos) & (TEXTURE_HEIGHT - 1);
	(*tex_pos) += (*step);
	if (p->ray->side == 0)
	{
		if (p->ray->ray_dir_x < 0)
			my_img_pixel_put(p, p->map->current_col, (*y),
				p->text->pixels[SO_TEXTURE][p->ray->tex_x][p->ray->tex_y]);
		else
			my_img_pixel_put(p, p->map->current_col, (*y),
				p->text->pixels[NO_TEXTURE][p->ray->tex_x][p->ray->tex_y]);
	}
	else
	{
		if (p->ray->ray_dir_y < 0)
			my_img_pixel_put(p, p->map->current_col, (*y),
				p->text->pixels[WE_TEXTURE][p->ray->tex_x][p->ray->tex_y]);
		else
			my_img_pixel_put(p, p->map->current_col, (*y),
				p->text->pixels[EA_TEXTURE][p->ray->tex_x][p->ray->tex_y]);
	}
}

void	ft_paint_pixels(t_player *p)
{
	double	step;
	int		y;
	double	tex_pos;

	step = 1.0 * TEXTURE_HEIGHT / p->draw->line_height;
	tex_pos = (p->draw->draw_start - WIN_HEIGHT / 2
			+ p->draw->line_height / 2) * step;
	y = 0;
	while (y < p->draw->draw_start)
	{
		my_img_pixel_put(p, p->map->current_col, y,
			create_trgb(NO_TRANSPARENCY, p->map->c_color[0][0],
				p->map->c_color[1][0], p->map->c_color[2][0]));
		y++;
	}
	while (y < p->draw->draw_end)
	{
		ft_draw_wall(p, &y, &step, &tex_pos);
		y++;
	}
	while (y < WIN_HEIGHT)
		my_img_pixel_put(p, p->map->current_col, y++,
			create_trgb(NO_TRANSPARENCY, p->map->f_color[0][0],
				p->map->f_color[1][0], p->map->f_color[2][0]));
}

int	raycasting_loop(t_player *p)
{
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
	mlx_put_image_to_window(p->mlx->mlx, p->mlx->mlx_win, p->img->img, 0, 0);
	return (0);
}
