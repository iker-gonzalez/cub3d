/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:13:56 by ingonzal          #+#    #+#             */
/*   Updated: 2022/08/21 21:05:26 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	ft_walls_cases(t_tmp *tmp, int i, int j)
{
	if (((tmp->map[i][j] == ' ')
		&& ((tmp->map[i][j + 1] != ' ') && (tmp->map[i][j + 1] != '\n'))) &&
	(((tmp->map[i][j + 1] != '1')) ||
	((tmp->map[i + 1][j] != ' ') && (tmp->map[i + 1][j] != '1'))))
		ft_print_error(5, tmp);
	if ((tmp->map[0][j] == '1') &&
	((((tmp->map[0][j + 1]) != '1') && ((tmp->map[0][j + 1]) != '\n')) &&
	((tmp->map[0][j + 1]) != ' ')))
		ft_print_error(5, tmp);
	if ((tmp->map[i][j] == '0') &&
	(((tmp->map[i][j + 1]) != '1') && ((tmp->map[i][j + 1]) != '0') &&
	(tmp->map[i][j + 1] != tmp->player)))
		ft_print_error(5, tmp);
	if ((tmp->map[i][j] == '0') &&
	((tmp->map[i + 1][j] != '1') && (tmp->map[i + 1][j] != tmp->player) &&
	(tmp->map[i + 1][j] != '0')))
		ft_print_error(5, tmp);
	if ((tmp->map[tmp->map_y][j] != '1') && (tmp->map[tmp->map_y][j] != ' ') &&
	(tmp->map[tmp->map_y][j] != '\n') && (tmp->map[tmp->map_y][j] != '\0'))
		ft_print_error(5, tmp);
}	

		/* printf("%s\n", tmp->map[tmp->map_y]); */
		/* printf("%d\n", tmp->map_y); */

void	ft_check_walls(t_tmp *tmp)
{
	int	i;
	int	j;

	i = 0;
	while (tmp->map[i + 1] != NULL)
	{
		j = 0;
		while (tmp->map[i][j])
		{
			ft_walls_cases(tmp, i, j);
			j++;
		}
		i++;
	}
}
				/* printf(">>>>>>>> %d\n", tmp->y); */
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
	i = -1;
	while (tmp->map[++i] != NULL)
	{
		j = -1;
		while (tmp->map[i][++j])
		{
			k = -1;
			while (set[++k])
			{
				if (set[k] == tmp->map[i][j] || tmp->map[i][j] == '\n')
					break ;
			}
			if (k > 7)
				/* printf("%d\n", k); */
				ft_print_error(4, tmp);
		}
	}
	ft_check_player(tmp);
	ft_check_walls(tmp);
}

