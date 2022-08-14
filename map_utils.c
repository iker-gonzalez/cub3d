/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:34:02 by ingonzal          #+#    #+#             */
/*   Updated: 2022/08/14 21:33:24 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_check_walls(t_tmp *tmp)
{
	int	i;
	int	j;

	i = 0;
	while (tmp->map[i] != NULL)
	{
		j = 0;
		if (tmp->map[i + 1] != NULL)
		{
			while (tmp->map[i][j])
			{
				if ((((tmp->map[i][j] == ' ')) &&
				((tmp->map[i][j + 1] != ' ') && (tmp->map[i][j + 1] != '\n'))) &&
				(((tmp->map[i][j + 1] != '1')) ||
				((tmp->map[i + 1][j] != ' ') && (tmp->map[i + 1][j] != '1'))))
					ft_print_error(5);
				if ((tmp->map[0][j] == '1') &&
				((((tmp->map[0][j + 1]) != '1') && ((tmp->map[0][j + 1]) != '\n')) &&
				((tmp->map[0][j + 1]) != ' ')))
					ft_print_error(5);
				if ((tmp->map[i][j] == '0') &&
				(((tmp->map[i][j + 1]) != '1') && ((tmp->map[i][j + 1]) != '0')))
					ft_print_error(5);
				j++;
			}
		}
		i++;
	}
}
				/* printf("> ->%c\n", tmp->map[i][j]); */
				/* printf("j+1 ->%c\n", tmp->map[i][j+1]); */
				/* printf("i+1 ->%c\n", tmp->map[i+1][j]); */
				/* printf("elsei+1 ->%c\n", tmp->map[i+1][j]); */
				/* printf("else> ->%c\n", tmp->map[i][j]); */
				/* printf("elsej+1 ->%c\n", tmp->map[i][j+1]); */

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
		j = 0;
		while (tmp->map[i][j])
		{
			k = -1;
			while (set[++k])
			{
				if (set[k] == tmp->map[i][j] || tmp->map[i][j] == '\n')
					break ;
			}
			if (k > 6)
				ft_print_error(4);
			j++;
		}
		i++;
	}
	ft_check_walls(tmp);
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
		tmp->map[i][x] = '\0';
		y++;
		i++;
	}
	tmp->map[i] = NULL;
	ft_check_mapchars(tmp);
}
