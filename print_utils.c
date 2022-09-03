/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:37:35 by ingonzal          #+#    #+#             */
/*   Updated: 2022/09/03 20:07:20 by ingonzal         ###   ########.fr       */
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
