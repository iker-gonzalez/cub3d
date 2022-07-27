/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_text_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:18:41 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/27 18:13:20 by ikgonzal         ###   ########.fr       */
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

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

void	ft_hex_to_trgb(void)
{
	
	
	int hex;

	hex = 585400;
	double red;
	double green;
	double brown;

	red = ((hex >> 16) & 0xFF) / 255.0; // Extract the RR byte
	green = ((hex >> 8) & 0xFF) / 255.0; // Extract the GG byte
	brown = ((hex) & 0xFF) / 255.0; // Extract the BB byte

	printf("red: %f\n", red);
	printf("green: %f\n", green);
	printf("brown: %f\n", brown);

	//return rgbColor;*/
}
