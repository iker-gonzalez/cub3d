/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_text_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:18:41 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/28 19:09:41 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_text_struct (t_text *text)
{
	text->content = (int ***)malloc(sizeof(int **) * (4 + 1));
	text->content[NO_TEXTURE] = (int **)malloc(sizeof(int *) * (64 + 1));
	text->content[NO_TEXTURE][32] = malloc(sizeof(int) * (64 + 1));
	text->content[NO_TEXTURE][32][2] = 642;
	printf("secret number: %d\n", text->content[NO_TEXTURE][32][2]);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


