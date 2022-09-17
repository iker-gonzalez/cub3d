/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:37:35 by ingonzal          #+#    #+#             */
/*   Updated: 2022/09/17 11:48:27 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_print_map(char **map)
{
	int	j;
	int	i;

	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\n')
		{
			printf("%c", map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

void	ft_print_error(int errno, t_player *p)
{
	if (errno == 1)
	{
		printf("Error:\nWrong number of arguments or invalid map\n");
		ft_free_structs(p);
	}
	if (errno == 2)
		printf("Error:\nNot Allowed Line First Char or Map Position\n");
	if (errno == 3)
		printf("Error:\nWrong newline or Char position\n");
	if (errno == 4)
		printf("Error:\nNot Allowed Char Map\n");
	if (errno == 5)
		printf("Error:\nMap not properly closed\n");
	if (errno == 6)
		printf("Error:\nWrong number of players\n");
	if (errno == 7)
	{
		printf("Error:\nBad formatted headers\n");
		ft_free_texture(p);
	}
	if (errno > 4)
		ft_free_int_errors(p);
	ft_free_errors(p);
	ft_free_structs(p);
}
