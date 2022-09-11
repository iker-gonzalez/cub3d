/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:25:58 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/11 14:22:24 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include "mlx/mlx.h"

int	close_window(t_player *p)
{
	mlx_destroy_window(p->mlx->mlx, p->mlx->mlx_win);
	ft_free_all(p);
	ft_free_pixels(p->text, p->text->columns);
	exit(0);
}

int	key_hook(int key, t_player *player)
{
	if (key == ESC_KEY_MAC)
	{
		mlx_destroy_window(player->mlx->mlx, player->mlx->mlx_win);
		ft_free_pixels(player->text, player->text->columns);
		ft_free_all(player);
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

int	ft_hook(t_player *p)
{
	mlx_hook(p->mlx->mlx_win, 2, (1L << 0), key_hook, p);
	mlx_hook(p->mlx->mlx_win, 17, (1L << 8), close_window, p);
	return (0);
}
