/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_xpm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 13:22:09 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/24 13:41:44 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_validate_xpm(t_map *map, t_mlx *mlx, t_text *text)
{
	text->img = mlx_xpm_file_to_image(mlx, map->ea_texture, &text->img_width, &text->img_height);
	if (text->img == NULL)
	{
		printf("Invalid xpm\n");
		return ;
	}
	printf("Valid xpm\n");
	return ;
}