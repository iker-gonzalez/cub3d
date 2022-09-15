/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:43:49 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/15 16:00:49 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "../../../libft/libft.h"
#include "../../../gnl/get_next_line.h"

void	ft_parse_pixel_column(t_text *text, int col, int text_nb)
{
	int	row;
	int	k;
	int	color;

	row = 0;
	while (row < text->rows)
	{
		k = 0;
		while (text->pixels_map[row][col] != text->colors[k][1])
			k++;
		if (text->colors[k])
			color = ft_hex_to_int(text->colors[k]);
		text->pixels[text_nb][col][row] = color;
		row++;
	}
}

void	ft_fill_pixels(t_text *text, int text_nb)
{
	int		col;

	text->pixels[text_nb] = (int **)malloc(sizeof(int *) * (text->columns + 1));
	col = 0;
	while (col < text->columns)
	{
		text->pixels[text_nb][col] = malloc(sizeof(int *) * (text->rows + 1));
		ft_parse_pixel_column(text, col, text_nb);
		col++;
	}
}

void	ft_create_pixels_array(t_text *text, int fd)
{
	char	*line;
	int		row;

	text->pixels_map = (char **)malloc(sizeof(char *) * (text->rows + 2));
	line = get_next_line(fd);
	row = 0;
	while (row <= text->rows)
	{
		text->pixels_map[row] = ft_substr(line, 1, 64);
		free(line);
		line = get_next_line(fd);
		row++;
	}
	if (line)
		free(line);
	text->pixels_map[row] = NULL;
}
