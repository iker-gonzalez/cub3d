/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:53:28 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/23 19:42:22 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_up(t_player *player)
{
	double moveSpeed = 0.3;
	printf("pepe parriba");
	player->map->render = 0;
	double value = player->posX + player->dirX * moveSpeed;
	if(player->map->map_content[(int)(value)][(int)(player->posY)] == 48)
	{
		player->map->render += 1;
		player->posX += player->dirX * moveSpeed;
	}
	value = player->posY + player->dirY * moveSpeed;
	if(player->map->map_content[(int)(player->posX)][(int)(value)] == 48)
	{
		player->map->render += 1;
		player->posY += player->dirY * moveSpeed;
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
	double moveSpeed = 0.3;
	player->map->render = 0;
	double value = player->posX - player->dirX * moveSpeed;
	if(player->map->map_content[(int)(value)][(int)(player->posY)] == 48)
	{
		//printf("pepi\n");
		player->map->render += 1;
		player->posX -= player->dirX * moveSpeed;
	}
	value = player->posY - player->dirY * moveSpeed;
	if(player->map->map_content[(int)(player->posX)][(int)(value)] == 48)
	{
		//printf("pepe\n");
		player->map->render += 1;
		player->posY -= player->dirY * moveSpeed;
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
	player->dirX = player->dirX * cos(-0.1) - player->dirY * sin(-0.1);
	player->dirY = oldDirX * sin(-0.1) + player->dirY * cos(-0.1);
	double oldPlaneX = player->planeX;
	player->planeX = player->planeX * cos(-0.1) - player->planeY * sin(-0.1);
	player->planeY = oldPlaneX * sin(-0.1) + player->planeY * cos(-0.1);
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
	player->dirX = player->dirX * cos(0.1) - player->dirY * sin(0.1);
	player->dirY = oldDirX * sin(0.1) + player->dirY * cos(0.1);
	double oldPlaneX = player->planeX;
	player->planeX = player->planeX * cos(0.1) - player->planeY * sin(0.1);
	player->planeY = oldPlaneX * sin(0.1) + player->planeY * cos(0.1);
	/*----------------*/
	player->map->current_col = 0;
	init_new_img(player);
	printf("left new image success\n");
	raycasting_loop(player);
}

