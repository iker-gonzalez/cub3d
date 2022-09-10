/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:25:58 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/10 18:27:08 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

int	key_hook(int key, t_player *player)
{
	if (key == ESC_KEY_MAC)
	{
		mlx_destroy_window(player->mlx->mlx, player->mlx->mlx_win);
		ft_free_pixels(player->text, player->text->columns);
		exit(0);
	}
	else if (key == UP_ARR_MAC)
		ft_move_up(player);
	else if (key == DOWN_ARR_MAC)
		ft_move_down(player);
	else if (key == RIGHT_ARR_MAC)
		ft_move_right(player);
	else if (key == LEFT_ARR_MAC)
		ft_move_left(player);
	else if (key == TURN_RIGHT_ARR_MAC)
		ft_turn_right(player);
	else if (key == TURN_LEFT_ARR_MAC)
		ft_turn_left(player);
	return (0);
}

int	ft_hook(t_player *player)
{
	mlx_hook(player->mlx->mlx_win, 2, (1L << 0), key_hook, player);
	mlx_hook(player->mlx->mlx_win, 17, (1L << 8), close_window, player->mlx->mlx);
	return (0);
}
