/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:36:08 by ingonzal          #+#    #+#             */
/*   Updated: 2022/08/19 20:13:27 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

void	ft_select_texture(char **line)
{
	

}

void	ft_header(t_tmp premap)
{
	int		i;
	int		j;
	char 	**line

	i = 0;
	while (i < 6 && premap[i] != NULL)
	{
		line = ft_split(premap[i], ' ')
		j = 0
		while (line[j] != NULL)
			j++;
		if (j > 1)
		{
			ft_free(line);
			ft_print_error(7, premap);
		}
		else
			ft_select_texture(line);
		i++;
	}
}
