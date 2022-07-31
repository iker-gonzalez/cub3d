/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:44:17 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/31 13:08:01 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
#include <stdio.h>

void	my_img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_paint_pixel(t_img *img, t_mlx *mlx, int x, int y, int color)
{
	my_img_pixel_put(img, 5, 5, 16711680);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img, 0, 0);
}

void	init_new_img(t_img *img, t_mlx *mlx)
{	
	img->img = mlx_new_image(img->img, WIN_WIDTH, WIN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
}