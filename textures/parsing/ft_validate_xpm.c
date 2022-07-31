/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_xpm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:22:09 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/31 10:01:40 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>

int	ft_mlx_validation(char *path, void *mlx, t_text *text)
{
	void	*img;

	int size; //provisional
	int size2; //provisional
	
	img = mlx_xpm_file_to_image(mlx, path, &size, &size2);
	if (img == NULL)
		return (1);
	return (0);
}

int	ft_validate_xpm(t_map *map, t_mlx *mlx, t_text *text)
{
	if (ft_mlx_validation(map->ea_texture, mlx, text))
		return (1);
	else if (ft_mlx_validation(map->no_texture, mlx, text))
		return (1);
	else if (ft_mlx_validation(map->so_texture, mlx, text))
		return (1);
	else if (ft_mlx_validation(map->we_texture, mlx, text))
		return (1);
	return (0);
}
