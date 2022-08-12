/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:37:35 by ingonzal          #+#    #+#             */
/*   Updated: 2022/08/12 20:17:19 by ingonzal         ###   ########.fr       */
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
		while (map[j][i] != '\0')
		{
			printf("%c", map[j][i]);
			i++;
		}
		j++;
	}
}

/* void	ft_print_map(t_tmp *tmp) */
/* { */
/* 	int	j; */
/* 	int	i; */

/* 	j = 0; */
/* 	while (tmp->map[j] != NULL) */
/* 	{ */
/* 		i = 0; */
/* 		while (tmp->map[j][i] != '\0') */
/* 		{ */
/* 			printf("%c", tmp->map[j][i]); */
/* 			i++; */
/* 		} */
/* 		j++; */
/* 	} */
/* } */

	/* printf("ENTRA\n"); */

/* void	ft_print_premap(t_tmp *tmp) */
/* { */
/* 	int	j; */
/* 	int	i; */

/* 	j = 0; */
/* 	while (tmp->premap[j] != NULL) */
/* 	{ */
/* 		i = 0; */
/* 		while (tmp->premap[j][i] != '\0') */
/* 		{ */
/* 			printf("%c", tmp->premap[j][i]); */
/* 			i++; */
/* 		} */
/* 		j++; */
/* 	} */
/* } */
