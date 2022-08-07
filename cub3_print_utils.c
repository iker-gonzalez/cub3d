/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3_print_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:37:35 by ingonzal          #+#    #+#             */
/*   Updated: 2022/08/07 19:41:00 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_premap(t_tmp *tmp)
{
	int	j;
	int	i;

	j = 0;
	while (tmp->premap[j] != NULL)
	{
		i = 0;
		while (tmp->premap[j][i] != '\0')
		{
			printf("%c", tmp->premap[j][i]);
			i++;
		}
		j++;
	}
}
