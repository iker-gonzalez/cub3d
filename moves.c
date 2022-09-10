/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:53:28 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/10 20:57:45 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_up(t_player *player)
{
	double	move_speed;
	double	value;

	move_speed = 0.3;
	value = player->pos_x + player->dir_x * move_speed;
	if (player->map->map_content[(int)(value)][(int)(player->pos_y)] == 48)
		player->pos_x += player->dir_x * move_speed;
	value = player->pos_y + player->dir_y * move_speed;
	if (player->map->map_content[(int)(player->pos_x)][(int)(value)] == 48)
		player->pos_y += player->dir_y * move_speed;
}

void	ft_move_down(t_player *player)
{
	double	move_speed;
	double	value;

	move_speed = 0.3;
	value = player->pos_x - player->dir_x * move_speed;
	if (player->map->map_content[(int)(value)][(int)(player->pos_y)] == 48)
		player->pos_x -= player->dir_x * move_speed;
	value = player->pos_y - player->dir_y * move_speed;
	if (player->map->map_content[(int)(player->pos_x)][(int)(value)] == 48)
		player->pos_y -= player->dir_y * move_speed;
}

void	ft_move_left(t_player *player)
{
	double	move_speed;
	double	value;

	move_speed = 0.3;
	value = player->pos_x - player->dir_y * move_speed;
	if (player->map->map_content[(int)(value)][(int)(player->pos_y)] == 48)
		player->pos_x = value;
	value = player->pos_y + player->dir_x * move_speed;
	if (player->map->map_content[(int)(player->pos_x)][(int)(value)] == 48)
		player->pos_y = value;
}

void	ft_move_right(t_player *player)
{
	double	move_speed;
	double	value;

	move_speed = 0.3;
	value = player->pos_x + player->dir_y * move_speed;
	if (player->map->map_content[(int)(value)][(int)(player->pos_y)] == 48)
		player->pos_x = value;
	value = player->pos_y - player->dir_x * move_speed;
	if (player->map->map_content[(int)(player->pos_x)][(int)(value)] == 48)
		player->pos_y = value;
}
