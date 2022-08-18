/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:53:28 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/18 18:58:00 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_up(t_player *player)
{
	printf("pepe parriba");
	player->map->render = 0;
	if(player->map->map_content[(int)(player->posX + player->dirX) /* *moveSpeed */][(int)(player->posY)] == 48)
	{
		player->map->render += 1;
		player->posX += player->dirX /** moveSpeed*/;
	}
	if(player->map->map_content[(int)(player->posX)][(int)(player->posY + player->dirY /* * moveSpeed */)] == 48)
	{
		player->map->render += 1;
		player->posY += player->dirY /** moveSpeed*/;
	}
	if (player->map->render == 2)
	{
		player->map->current_col = 0;
		init_new_img(player);
		printf("up new image success\n");
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
		printf("down new image success\n");
		raycasting_loop(player);
	}
}

void	ft_move_right(t_player *player)
{
	//both camera direction and camera plane must be rotated
	double oldDirX = player->dirX;
	player->dirX = player->dirX * cos(-1) - player->dirY * sin(-1);
	player->dirY = oldDirX * sin(-1) + player->dirY * cos(-1);
	double oldPlaneX = player->planeX;
	player->planeX = player->planeX * cos(-1) - player->planeY * sin(-1);
	player->planeY = oldPlaneX * sin(-1) + player->planeY * cos(-1);
	/*----------------*/
	player->map->current_col = 0;
	init_new_img(player);
	printf("right new image success\n");
	raycasting_loop(player);
}

void	ft_move_left(t_player *player)
{
	//both camera direction and camera plane must be rotated
	double oldDirX = player->dirX;
	player->dirX = player->dirX * cos(1) - player->dirY * sin(1);
	player->dirY = oldDirX * sin(1) + player->dirY * cos(1);
	double oldPlaneX = player->planeX;
	player->planeX = player->planeX * cos(1) - player->planeY * sin(1);
	player->planeY = oldPlaneX * sin(1) + player->planeY * cos(1);
	/*----------------*/
	player->map->current_col = 0;
	init_new_img(player);
	printf("left new image success\n");
	raycasting_loop(player);
}

