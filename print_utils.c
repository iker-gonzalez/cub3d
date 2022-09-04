/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:37:35 by ingonzal          #+#    #+#             */
/*   Updated: 2022/09/04 17:37:12 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

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
			printf("[%c]", map[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

int	ft_print_error(int errno, t_tmp *tmp)
{
	if (errno == 1)
	{
		printf("Error:\nWrong number of arguments\n");
		exit (1);
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
		ft_free_texture(tmp);
	}
	if (errno > 4)
		ft_free_int_errors(tmp);
	ft_free_errors(tmp);
	exit (1);
}
