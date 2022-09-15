/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:49:10 by ingonzal          #+#    #+#             */
/*   Updated: 2022/09/15 20:03:28 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	ft_init_int(t_tmp *tmp)
{
	int	i;

	i = -1;
	tmp->f_int = (int **)malloc(3 * sizeof(int *));
	while (++i < 3)
		tmp->f_int[i] = (int *)malloc(sizeof(int));
	i = -1;
	tmp->c_int = (int **)malloc(3 * sizeof(int *));
	while (++i < 3)
		tmp->c_int[i] = (int *)malloc(sizeof(int));
}

void	ft_init_structs(t_player *p)
{
	p->mlx = malloc(sizeof(t_mlx));
	p->img = malloc(sizeof(t_img));
	p->ray = malloc(sizeof(t_ray));
	p->draw = malloc(sizeof(t_draw));
	p->text = malloc(sizeof(t_text));
	p->map = malloc(sizeof(t_map));
	ft_memset(p->ray, 0, sizeof(t_ray));
	ft_memset(p->mlx, 0, sizeof(t_mlx));
	ft_memset(p->text, 0, sizeof(t_text));
	ft_memset(p->img, 0, sizeof(t_img));
	ft_memset(p->draw, 0, sizeof(t_draw));
	ft_memset(p->map, 0, sizeof(t_map));
}

void	ft_init_tmp(t_tmp *tmp, t_map *map)
{
	tmp->premap = NULL;
	tmp->map = NULL;
	tmp->rgb = 'a';
	tmp->y = 0;
	tmp->x = 0;
	tmp->max_x = 0;
	tmp->map_y = 0;
	tmp->pos = 0;
	tmp->err = 0;
	tmp->ln = " ";
	tmp->no_path = NULL;
	tmp->so_path = NULL;
	tmp->ea_path = NULL;
	tmp->we_path = NULL;
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->ea_texture = NULL;
	map->we_texture = NULL;
}

void	ft_init_player_dir(t_player *player)
{
	double	adjust;

	adjust = 0.5;
	player->pos_y = player->map->player_x + adjust;
	player->pos_x = player->map->player_y + adjust;
	if (player->map->player == 'N')
	{
		player->dir_x = -1.0 - adjust;
		player->plane_y = 0.66;
	}
	else if (player->map->player == 'S')
	{
		player->dir_x = 1.0 + adjust;
		player->plane_y = -0.66;
	}
	else if (player->map->player == 'W')
	{
		player->dir_y = 1.0 + adjust;
		player->plane_x = 0.66;
	}
	else if (player->map->player == 'E')
	{
		player->dir_y = -1.0 - adjust;
		player->plane_x = -0.66;
	}
}
