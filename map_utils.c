/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:34:02 by ingonzal          #+#    #+#             */
/*   Updated: 2022/08/12 19:40:29 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_check_mapchars(t_tmp *tmp)
{
	char	*set;
	int		i;
	int		j;
	int		k;

	set = "10NSWO ";
	i = 0;
	while (tmp->map[i] != NULL)
	{
		j= 0;
		while (tmp->map[i][j])
		{
			k = 0;
			while (set[k])
			{
				if (set[k] == tmp->map[i][j] || tmp->map[i][j] == '\n')
					break;
				k++;
			}
			if (k > 6)
				ft_print_error(4);
			j++;
		}
		i++;
	}
}
				/* printf(">>>>>%d\n", k); */

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
		tmp->map[i] = (char *)malloc((tmp->max_x) * sizeof(char));
		x = 0;
		while (x < tmp->max_x)
		{
			tmp->map[i][x] = tmp->premap[y][x];
			if (tmp->premap[y][x] == '\n' && x < tmp->max_x)
				x = ft_fill_blanks(x, i, tmp);
			x++;
		}
		tmp->map[i][x - 1] = '\n';
		y++;
		i++;
	}
	tmp->map[i] = NULL;
	ft_check_mapchars(tmp);
}
