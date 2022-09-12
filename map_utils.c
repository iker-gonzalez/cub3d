/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:34:02 by ingonzal          #+#    #+#             */
/*   Updated: 2022/09/12 18:49:04 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>
#include "mlx/mlx.h"

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
	ft_free_texture(p->tmp);
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

void	ft_check_player(t_tmp *tmp)
{
	char		*set;
	int			i;
	int			j;
	int			k;
	static int	o;

	set = "NSWE";
	i = 0;
	while (tmp->map[i] != NULL)
	{
		j = -1;
		while (tmp->map[i][++j])
		{
			k = -1;
			while (set[++k])
			{
				if (set[k] == tmp->map[i][j])
					o = ft_player_pos(tmp, i, j);
			}
		}
		i++;
	}
	if (o != 1)
		ft_print_error(6, tmp);
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

void	ft_extract_map(t_tmp *tmp)
{
	int		y;
	int		i;
	size_t	x;

	y = 5;
	i = 0;
	tmp->map = (char **)malloc((tmp->y - 5) * sizeof(char *));
	while (tmp->premap[++y] != NULL)
	{
		tmp->map[i] = (char *)malloc((tmp->max_x + 1) * sizeof(char));
		x = -1;
		while (++x < tmp->max_x)
		{
			tmp->map[i][x] = tmp->premap[y][x];
			if ((tmp->premap[y][x] == '\n' || tmp->premap[y][x] == '\0')
				&& x < tmp->max_x)
				x = ft_fill_blanks(x, i, tmp);
		}
		tmp->map[i][x - 1] = '\n';
		tmp->map[i][x] = '\0';
		i++;
	}
	tmp->map[i] = NULL;
	tmp->map_y = i - 1;
	ft_check_mapchars(tmp);
}
