/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:53:28 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/17 19:18:50 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_up(t_player *player)
{
	player->map->render = 0;
	if(player->map->map_content[(int)(player->posX + player->dirX) /* *moveSpeed */][(int)(player->posY)] == 48)
	{
		//printf("pepi\n");
		player->map->render += 1;
		player->posX += player->dirX /** moveSpeed*/;
	}
	if(player->map->map_content[(int)(player->posX)][(int)(player->posY + player->dirY /* * moveSpeed */)] == 48)
	{
		//printf("pepe\n");
		player->map->render += 1;
		player->posY += player->dirY /** moveSpeed*/;
	}
	if (player->map->render == 2)
	{
		player->map->current_col = 0;
		init_new_img(player);
		raycasting_loop(player);
	}
}

void	ft_move_down(t_player *player)
{
	player->map->render = 0;
	if(player->map->map_content[(int)(player->posX - player->dirX) /* *moveSpeed */][(int)(player->posY)] == 48)
	{
		//printf("pepi\n");
		player->map->render += 1;
		player->posX -= player->dirX /** moveSpeed*/;
	}
	if(player->map->map_content[(int)(player->posX)][(int)(player->posY - player->dirY /* * moveSpeed */)] == 48)
	{
		//printf("pepe\n");
		player->map->render += 1;
		player->posY -= player->dirY /** moveSpeed*/;
	}
	if (player->map->render == 2)
	{
		player->map->current_col = 0;
		init_new_img(player);
		raycasting_loop(player);
	}
}

void	ft_move_right(t_player *player)
{
	//both camera direction and camera plane must be rotated
	double oldDirX = player->dirX;
	player->dirX = player->dirX /* * cos(-rotSpeed) */ - player->dirY /* * sin(-rotSpeed) */;
	player->dirY = oldDirX /* * sin(-rotSpeed)*/ + player->dirY /* * cos(-rotSpeed)*/;
	double oldPlaneX = player->planeX;
	player->planeX = player->planeX /* * cos(-rotSpeed) */ - player->planeY  /* * sin(-rotSpeed) */;
	player->planeY = oldPlaneX /* * sin(-rotSpeed) */ + player->planeY /* * cos(-rotSpeed) */;
	/*----------------*/
	player->map->current_col = 0;
	init_new_img(player);
	raycasting_loop(player);
}
