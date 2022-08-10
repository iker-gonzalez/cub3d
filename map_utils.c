/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:34:02 by ingonzal          #+#    #+#             */
/*   Updated: 2022/08/10 21:57:59 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_extract_map(t_tmp *tmp)
{
	int 	y;
	int 	i;
	size_t	x;

	y = 6;
	i = 0;
	/* printf("Y - %d", tmp->y); */
	tmp->map = (char **)malloc((tmp->y - 6) * sizeof(char *));
	while (tmp->premap[y] != NULL)
	{
		tmp->map[i] = (char *)malloc((tmp->max_x) * sizeof(char));
		x = 0;
		/* while (tmp->premap[y][x] != '\0') */
		while (x <= tmp->max_x)
		{
			tmp->map[i][x] = tmp->premap[y][x];
			/* if (tmp->premap[y][x] == '\0' && x < tmp->max_x) */
			/* 	while (x < tmp->max_x) */
			/* 	{ */
			/* 		tmp->map[i][x] = ' '; */
			/* 		x++; */
			/* 	} */
			x++;
		}
		printf("X - %zu\n", x);
		printf("Max_X - %zu\n", tmp->max_x);
		y++;
		i++;
	}
	tmp->map[i] = NULL;
}
