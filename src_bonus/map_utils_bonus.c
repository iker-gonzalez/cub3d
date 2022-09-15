/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:34:02 by ingonzal          #+#    #+#             */
/*   Updated: 2022/09/15 15:47:22 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include "../mlx/mlx.h"

void	ft_free_all(t_player *p)
{
	if (p->tmp->premap != NULL)
		ft_free(p->tmp->premap);
	if (p->tmp->map != NULL)
		ft_free(p->tmp->map);
	if (p->map->no_texture != NULL)
		free(p->map->no_texture);
	if (p->map->so_texture != NULL)
		free(p->map->so_texture);
	if (p->map->ea_texture != NULL)
		free(p->map->ea_texture);
	if (p->map->we_texture != NULL)
		free(p->map->we_texture);
	if (p->map->f_color != NULL)
		ft_free_int(p->map->f_color);
	if (p->map->c_color != NULL)
		ft_free_int(p->map->c_color);
	if (p->img->img)
		mlx_destroy_image(p->mlx->mlx, p->img->img);
	ft_free_texture(p);
}

static int	ft_player_pos(t_tmp *tmp, int i, int j)
{
	static int	o;

	tmp->player = tmp->map[i][j];
	tmp->player_y = i;
	tmp->player_x = j;
	tmp->map[i][j] = '0';
	o += 1;
	return (o);
}

void	ft_check_player(t_player *p)
{
	char		*set;
	int			i;
	int			j;
	int			k;
	static int	o;

	set = "NSWE";
	i = 0;
	while (p->tmp->map[i] != NULL)
	{
		j = -1;
		while (p->tmp->map[i][++j])
		{
			k = -1;
			while (set[++k])
			{
				if (set[k] == p->tmp->map[i][j])
					o = ft_player_pos(p->tmp, i, j);
			}
		}
		i++;
	}
	if (o != 1)
		ft_print_error(6, p);
}

size_t	ft_fill_blanks(size_t x, int i, t_tmp *tmp)
{
	while (x < tmp->max_x - 1)
	{
		tmp->map[i][x] = ' ';
		x++;
	}
	return (x);
}

void	ft_extract_map(t_player *p)
{
	int		y;
	int		i;
	size_t	x;

	y = 5;
	i = 0;
	p->tmp->map = (char **)malloc((p->tmp->y - 5) * sizeof(char *));
	while (p->tmp->premap[++y] != NULL)
	{
		p->tmp->map[i] = (char *)malloc((p->tmp->max_x + 1) * sizeof(char));
		x = -1;
		while (++x < p->tmp->max_x)
		{
			p->tmp->map[i][x] = p->tmp->premap[y][x];
			if ((p->tmp->premap[y][x] == '\n' || p->tmp->premap[y][x] == '\0')
				&& x < p->tmp->max_x)
				x = ft_fill_blanks(x, i, p->tmp);
		}
		p->tmp->map[i][x - 1] = '\n';
		p->tmp->map[i][x] = '\0';
		i++;
	}
	p->tmp->map[i] = NULL;
	p->tmp->map_y = i - 1;
	ft_check_mapchars(p);
}
