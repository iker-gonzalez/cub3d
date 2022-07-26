/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_xpm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:22:09 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/26 18:17:27 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <stdio.h>

int	ft_mlx_validation(char *path, void *mlx)
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
	if (ft_mlx_validation(map->ea_texture, mlx))
		return (1);
	else if (ft_mlx_validation(map->no_texture, mlx))
		return (1);
	else if (ft_mlx_validation(map->so_texture, mlx))
		return (1);
	else if (ft_mlx_validation(map->we_texture, mlx))
		return (1);
	return (0);
}
