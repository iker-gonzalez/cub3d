/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:43:14 by ingonzal          #+#    #+#             */
/*   Updated: 2022/09/10 20:59:35 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	ft_turn_right(t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * TURN_RIGHT_COS - p->dir_y * TURN_RIGHT_SIN;
	p->dir_y = old_dir_x * TURN_RIGHT_SIN + p->dir_y * TURN_RIGHT_COS;
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * TURN_RIGHT_COS - p->plane_y * TURN_RIGHT_SIN;
	p->plane_y = old_plane_x * TURN_RIGHT_SIN + p->plane_y * TURN_RIGHT_COS;
}

void	ft_turn_left(t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * TURN_LEFT_COS - p->dir_y * TURN_LEFT_SIN;
	p->dir_y = old_dir_x * TURN_LEFT_SIN + p->dir_y * TURN_LEFT_COS;
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * TURN_LEFT_COS - p->plane_y * TURN_LEFT_SIN;
	p->plane_y = old_plane_x * TURN_LEFT_SIN + p->plane_y * TURN_LEFT_COS;
}
