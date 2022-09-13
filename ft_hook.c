/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 17:25:58 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/13 20:24:24 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include "mlx_linux/mlx.h"

int	close_window(t_player *p)
{
	ft_free_pixels(p->text, p->text->columns);
	ft_free_all(p);
	mlx_destroy_window(p->mlx->mlx, p->mlx->mlx_win);
	free(p->mlx->mlx);
	ft_free_structs(p);
	exit(0);
}

	/* Destroy display for mlx_linux after destroy window*/
	/* UP - Close Window*/
	/* mlx_destroy_display(p->mlx->mlx); */
	/* DOWN - Esc Key Hook*/
	/* mlx_destroy_display(player->mlx->mlx); */

int	key_hook(int key, t_player *player)
{
	if (key == ESC_KEY_MAC || key == ESC_KEY_LINUX)
	{
		ft_free_pixels(player->text, player->text->columns);
		ft_free_all(player);
		mlx_destroy_window(player->mlx->mlx, player->mlx->mlx_win);
		free(player->mlx->mlx);
		ft_free_structs(player);
		exit(0);
	}
	else if (key == W_KEY_MAC || key == W_KEY_LINUX)
		ft_move_up(player);
	else if (key == S_KEY_MAC || key == S_KEY_LINUX)
		ft_move_down(player);
	else if (key == D_KEY_MAC || key == D_KEY_LINUX)
		ft_move_right(player);
	else if (key == A_KEY_MAC || key == A_KEY_LINUX)
		ft_move_left(player);
	else if (key == RIGHT_ARR_MAC || key == RIGHT_ARR_LINUX)
		ft_turn_right(player);
	else if (key == LEFT_ARR_MAC || key == LEFT_ARR_LINUX)
		ft_turn_left(player);
	return (0);
}

int	ft_hook(t_player *p)
{
	mlx_hook(p->mlx->mlx_win, 2, (1L << 0), key_hook, p);
	mlx_hook(p->mlx->mlx_win, 17, (1L << 8), close_window, p);
	return (0);
}
