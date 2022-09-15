/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:44:17 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/15 15:59:12 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../mlx/mlx.h"

void	my_img_pixel_put(t_player *p, int x, int y, int color)
{
	char	*dst;

	dst = p->img->addr + (y * p->img->line_length
			+ x * (p->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_new_img(t_player *p)
{	
	p->img->img = mlx_new_image(p->mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	p->img->addr = mlx_get_data_addr(p->img->img, &p->img->bits_per_pixel,
			&p->img->line_length, &p->img->endian);
}
