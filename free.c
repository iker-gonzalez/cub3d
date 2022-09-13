/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:09:50 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/13 18:21:52 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

void	ft_free_colors(t_text *text, int nb_colors)
{
	int	i;

	if (!text->colors)
		return ;
	i = -1;
	while (++i < nb_colors)
		free(text->colors[i]);
	free(text->colors);
}

void	ft_free_pixels_map(t_text *text, int text_rows)
{
	int	i;

	if (!text->pixels_map)
		return ;
	i = -1;
	while (++i <= text_rows)
		free(text->pixels_map[i]);
	free(text->pixels_map);
}

void	ft_free_pixels(t_text *text, int text_columns)
{
	int	text_nb;
	int	k;

	text_nb = 0;
	while (text_nb < NB_TEXTURES)
	{
		k = 0;
		while (k < text_columns)
		{
			if (text->pixels[text_nb][k])
				free(text->pixels[text_nb][k]);
			k++;
		}
		if (text->pixels[text_nb])
			free(text->pixels[text_nb]);
		text_nb++;
	}
	if (text->pixels)
		free(text->pixels);
}

void	ft_free_structs(t_player *p)
{
	if (p->img)
		free(p->img);
	if (p->map)
		free(p->map);
	if (p->ray)
		free(p->ray);
	if (p->text)
		free(p->text);
	if (p->mlx)
		free(p->mlx);
	if (p->draw)
		free(p->draw);
}
