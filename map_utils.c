/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:34:02 by ingonzal          #+#    #+#             */
/*   Updated: 2022/08/21 20:25:08 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_player(t_tmp *tmp)
{
	char		*set;
	static int	i;
	int			j;
	int			k;
	static int	o;

	set = "NSWE";
	while (tmp->map[++i] != NULL)
	{
		j = -1;
		while (tmp->map[i][++j])
		{
			k = -1;
			while (set[++k])
			{
				if (set[k] == tmp->map[i][j])
				{
					tmp->player = tmp->map[i][j];
					o += 1;
				}
			}
		}
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

	y = 6;
	i = 0;
	tmp->map = (char **)malloc((tmp->y - 6) * sizeof(char *));
	while (tmp->premap[y] != NULL)
	{
		tmp->map[i] = (char *)malloc((tmp->max_x + 1) * sizeof(char));
		x = -1;
		while (++x < tmp->max_x)
		{
			tmp->map[i][x] = tmp->premap[y][x];
			if (tmp->premap[y][x] == '\n' && x < tmp->max_x)
				x = ft_fill_blanks(x, i, tmp);
		}
		tmp->map[i][x - 1] = '\n';
		tmp->map[i][x] = '\0';
		y++;
		i++;
	}
	tmp->map[i] = NULL;
	tmp->map_y = i - 1;
	ft_check_mapchars(tmp);
}
