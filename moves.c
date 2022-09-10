/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:53:28 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/10 19:13:13 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_up(t_player *player)
{
	double	move_speed;
	double	value;

	move_speed = 0.3;
	value = player->posX + player->dirX * move_speed;
	if (player->map->map_content[(int)(value)][(int)(player->posY)] == 48)
		player->posX += player->dirX * move_speed;
	value = player->posY + player->dirY * move_speed;
	if (player->map->map_content[(int)(player->posX)][(int)(value)] == 48)
		player->posY += player->dirY * move_speed;
}

void	ft_move_down(t_player *player)
{
	double	move_speed;
	double	value;

	move_speed = 0.3;
	value = player->posX - player->dirX * move_speed;
	if (player->map->map_content[(int)(value)][(int)(player->posY)] == 48)
		player->posX -= player->dirX * move_speed;
	value = player->posY - player->dirY * move_speed;
	if (player->map->map_content[(int)(player->posX)][(int)(value)] == 48)
		player->posY -= player->dirY * move_speed;
}

void	ft_move_left(t_player *player)
{
	double	move_speed;
	double	value;

	move_speed = 0.3;
	value = player->posX - player->dirY * move_speed;
	//printf("value: %f\n", value);
	//printf("posY: %f\n", player->posY);
	if (player->map->map_content[(int)(value)][(int)(player->posY)] == 48)
		player->posX = value;
	value = player->posY + player->dirX * move_speed;
	if (player->map->map_content[(int)(player->posX)][(int)(value)] == 48)
		player->posY = value;
}

void	ft_move_right(t_player *player)
{
	double	move_speed;
	double	value;

	move_speed = 0.3;
	value = player->posX + player->dirY * move_speed;
	if (player->map->map_content[(int)(value)][(int)(player->posY)] == 48)
		player->posX = value;
	value = player->posY - player->dirX * move_speed;
	if (player->map->map_content[(int)(player->posX)][(int)(value)] == 48)
		player->posY = value;
}

void	ft_turn_right(t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dirX;
	p->dirX = p->dirX * TURN_RIGHT_COS - p->dirY * TURN_RIGHT_SIN;
	p->dirY = old_dir_x * TURN_RIGHT_SIN + p->dirY * TURN_RIGHT_COS;
	old_plane_x = p->planeX;
	p->planeX = p->planeX * TURN_RIGHT_COS - p->planeY * TURN_RIGHT_SIN;
	p->planeY = old_plane_x * TURN_RIGHT_SIN + p->planeY * TURN_RIGHT_COS;
}

void	ft_turn_left(t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dirX;
	p->dirX = p->dirX * TURN_LEFT_COS - p->dirY * TURN_LEFT_SIN;
	p->dirY = old_dir_x * TURN_LEFT_SIN + p->dirY * TURN_LEFT_COS;
	old_plane_x = p->planeX;
	p->planeX = p->planeX * TURN_LEFT_COS - p->planeY * TURN_LEFT_SIN;
	p->planeY = old_plane_x * TURN_LEFT_SIN + p->planeY * TURN_LEFT_COS;
}
