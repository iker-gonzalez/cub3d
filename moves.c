/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:53:28 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/29 17:18:27 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_up(t_player *player)
{
	double moveSpeed = 0.3;
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
	/*if (player->map->render == 2)
	{
		//player->map->current_col = 0;
		//init_new_img(player);
		//raycasting_loop(player);
	}*/
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
	/*if (player->map->render == 2)
	{
		//player->map->current_col = 0;
		//init_new_img(player);
		//raycasting_loop(player);
	}*/
}

void	ft_move_right(t_player *player)
{
	//both camera direction and camera plane must be rotated
	double oldDirX = player->dirX;
	player->dirX = player->dirX * TURN_RIGHT_COS - player->dirY * TURN_RIGHT_SIN;
	player->dirY = oldDirX * TURN_RIGHT_SIN + player->dirY * TURN_RIGHT_COS;
	double oldPlaneX = player->planeX;
	player->planeX = player->planeX * TURN_RIGHT_COS - player->planeY * TURN_RIGHT_SIN;
	player->planeY = oldPlaneX * TURN_RIGHT_SIN + player->planeY * TURN_RIGHT_COS;
	/*----------------*/
	//player->map->current_col = 0;
	//init_new_img(player);
	//raycasting_loop(player);
	printf("dirX: %f\n", player->dirX);
	printf("dirY: %f\n", player->dirY);
	printf("planeX: %f\n", player->planeX);
	printf("planeY: %f\n", player->planeY);
	printf("---------------------\n");
}

void	ft_move_left(t_player *player)
{
	//both camera direction and camera plane must be rotated
	double oldDirX = player->dirX;
	player->dirX = player->dirX * TURN_LEFT_COS - player->dirY * TURN_LEFT_SIN;
	player->dirY = oldDirX * TURN_LEFT_SIN + player->dirY * TURN_LEFT_COS;
	double oldPlaneX = player->planeX;
	player->planeX = player->planeX * TURN_LEFT_COS - player->planeY * TURN_LEFT_SIN;
	player->planeY = oldPlaneX * TURN_LEFT_SIN + player->planeY * TURN_LEFT_COS;
	/*----------------*/
	//player->map->current_col = 0;
	//init_new_img(player);
	//raycasting_loop(player);
	printf("dirX: %f\n", player->dirX);
	printf("dirY: %f\n", player->dirY);
	printf("planeX: %f\n", player->planeX);
	printf("planeY: %f\n", player->planeY);
	printf("---------------------\n");

}

