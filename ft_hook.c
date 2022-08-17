/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:25:58 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/17 17:30:39 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
void	ft_moves(t_data *mlx)
{
	int			prev_x;
	int			prev_y;
	static int	moves;

	prev_x = mlx->p_row;
	prev_y = mlx->p_col;
	ft_fill_p2(mlx);
	if (prev_x != mlx->p_row || prev_y != mlx->p_col)
		printf("moves = %d \n", ++moves);
}
*/
int	key_hook(int key, t_player *player)
{
	if (key == ESC_KEY_MAC)
	{
		mlx_destroy_window(player->mlx->mlx, player->mlx->mlx_win);
		exit(0);
	}
	else if (key == UP_ARR_MAC)
	{
		if(player->map->map_content[(int)(player->posX + player->dirX) /* *moveSpeed */][(int)(player->posY)] == 48)
		{
			printf("pepe\n");
			//mlx_destroy_image(player->mlx, player->img->img);
			player->posX += player->dirX /** moveSpeed*/;
			init_new_img(player);
			raycasting_loop(player);
		}
		if(player->map->map_content[(int)(player->posX)][(int)(player->posY + player->dirY /* * moveSpeed */)] == 48)
		{
			printf("pepo\n");
			player->posY += player->dirY /** moveSpeed*/;
		}
	}
	return (0);
}

int	ft_hook(t_player *player)
{
	mlx_hook(player->mlx->mlx_win, 2, (1L << 0), key_hook, player);
	return (0);
}