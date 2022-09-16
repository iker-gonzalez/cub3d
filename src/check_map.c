/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:13:56 by ingonzal          #+#    #+#             */
/*   Updated: 2022/09/16 19:44:19 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	ft_free_value(char **line, t_player *p, char **str)
{
	ft_free(line);
	ft_free(str);
	ft_print_error(7, p);
}

void	ft_walls_cases(t_player *p, int i, int j)
{
	if (((p->tmp->map[i][j] == ' ') && ((p->tmp->map[i][j + 1] != ' ')
		&& (p->tmp->map[i][j + 1] != '\n'))) &&
		(((p->tmp->map[i][j + 1] != '1')) ||
	((p->tmp->map[i + 1][j] != ' ') && (p->tmp->map[i + 1][j] != '1'))))
		ft_print_error(5, p);
	if ((p->tmp->map[0][j] == '1') &&
	((((p->tmp->map[0][j + 1]) != '1') && ((p->tmp->map[0][j + 1]) != '\n')) &&
	((p->tmp->map[0][j + 1]) != ' ')))
		ft_print_error(5, p);
	if ((p->tmp->map[i][j] == '0') &&
	(((p->tmp->map[i][j + 1]) != '1') && ((p->tmp->map[i][j + 1]) != '0') &&
	(p->tmp->map[i][j + 1] != p->tmp->player)))
		ft_print_error(5, p);
	if ((p->tmp->map[i][j] == '0') &&
	((p->tmp->map[i + 1][j] != '1') && (p->tmp->map[i + 1][j] != p->tmp->player)
	&& (p->tmp->map[i + 1][j] != '0')))
		ft_print_error(5, p);
	if ((p->tmp->map[p->tmp->map_y][j] != '1')
		&& (p->tmp->map[p->tmp->map_y][j] != ' ')
		&& (p->tmp->map[p->tmp->map_y][j] != '\n')
		&& (p->tmp->map[p->tmp->map_y][j] != '\0'))
		ft_print_error(5, p);
}	

void	ft_check_walls(t_player *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->tmp->map[i + 1] != NULL)
	{
		j = 0;
		while (p->tmp->map[i][j])
		{
			ft_walls_cases(p, i, j);
			j++;
		}
		i++;
	}
}

void	ft_check_mapchars(t_player *p)
{
	char	*set;
	int		i;
	int		j;
	int		k;

	set = "10NSWO ";
	i = -1;
	while (p->tmp->map[++i] != NULL)
	{
		j = -1;
		while (p->tmp->map[i][++j])
		{
			k = -1;
			while (set[++k])
			{
				if (set[k] == p->tmp->map[i][j] || p->tmp->map[i][j] == '\n')
					break ;
			}
			if (k > 7)
				ft_print_error(4, p);
		}
	}
	ft_check_player(p);
	ft_check_walls(p);
}

int	ft_check_l(char *l)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (l)
	{
		while (l[i])
		{
			if (l[i] == '\t')
				return (1);
			if (l[i] == ',')
				j++;
			i++;
		}
		if (j > 2)
			return (1);
	}
	else
		return (1);
	return (0);
}
