/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:25:58 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/17 18:28:48 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int key, t_player *player)
{
	double posX;
	double posY;
	if (key == ESC_KEY_MAC)
	{
		mlx_destroy_window(player->mlx->mlx, player->mlx->mlx_win);
		exit(0);
	}
	else if (key == UP_ARR_MAC)
	{
		player->map->current_col = 0;
		init_new_img(player);
		if(player->map->map_content[(int)(player->posX + player->dirX) /* *moveSpeed */][(int)(player->posY)] == 48)
		{
			printf("pepe\n");
			//mlx_destroy_image(player->mlx, player->img->img);
			posX = player->posX + player->dirX /** moveSpeed*/;
			//set_structs(player, player->img, player->ray, player->draw);
			player->posX = posX;
		}
		if(player->map->map_content[(int)(player->posX)][(int)(player->posY + player->dirY /* * moveSpeed */)] == 48)
		{
			printf("pepo\n");
			//mlx_destroy_image(player->mlx, player->img->img);
			posY = player->posY + player->dirY /** moveSpeed*/;
			//set_structs(player, player->img, player->ray, player->draw);
			player->posY = posY;
		}
		raycasting_loop(player);
	}
	return (0);
}

int	ft_hook(t_player *player)
{
	mlx_hook(player->mlx->mlx_win, 2, (1L << 0), key_hook, player);
	return (0);
}