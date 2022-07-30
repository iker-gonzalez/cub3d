/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_text_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:18:41 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/30 19:20:33 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


void	ft_extract_text_colors(char *line, t_text *text, int end)
{
	int start;
	char *nb;
	
	start = end + 1;
	while (!ft_isdigit((int)line[start]))
		start++;
	end = start;
	while (line[end] != ' ')
		end++;
	nb = ft_substr(line, start, end);
	text->nb_colors = ft_atoi(nb);
	free(nb);
}

void	ft_extract_text_data(char *line, t_text *text)
{
	int start;
	char	*nb;
	int end;

	start = 0;
	while (!ft_isdigit((int)line[start]))
		start++;
	end = start;
	while (line[end] != ' ')
		end++;
	nb = ft_substr(line, start, end);
	text->columns = ft_atoi(nb);
	free(nb);
	start = end + 1;
	while (!ft_isdigit((int)line[start]))
		start++;
	end = start;
	while (line[end] != ' ')
		end++;
	nb = ft_substr(line, start, end);
	text->rows = ft_atoi(nb);
	free(nb);
	ft_extract_text_colors(line, text, end);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_give_colors(char *color)
{
	int i;
	char *hex;
	char *red;
	char *green;
	char *blue;
	char *red_2;

	i = 0;
	while (color[i] != '#')
		i++;
	i++;
	hex = "0x";
	red = malloc(sizeof(char) * 2);
	red[0] = color[i];
	red[1] = color[i + 1];
	red_2 = ft_strjoin(hex, red);
	printf("red: %s\n", red_2);
	green = malloc(sizeof(char) * 2);
	green[0] = color[i + 2];
	green[1] = color[i + 3];
	blue = malloc(sizeof(char) * 2);
	blue[0] = color[i + 4];
	blue[1] = color[i + 5];
	//return (create_trgb(NO_TRANSPARENCY, ft_atoi(red), ft_atoi(green), ft_atoi(blue)));
	return 0;
}

void	ft_parse_pixel_column(t_text *text, int col, int text_nb)
{
	int row;
	int k;
	int color;

	row = 0;
	while (row < text->rows)
	{
		k = 0;
		//printf("text->pixels_map[row][col]: %c\n", text->pixels_map[row][col]);
		//printf("text->colors[k][1]: %c\n", text->colors[k][1]);
		while(text->pixels_map[row][col] != text->colors[k][1])
			k++;
		color = ft_give_colors(text->colors[k]);
		//printf("color: %d\n", color);
		text->pixels[text_nb][col][row] = color;
		//printf("%d\n", text->pixels[text_nb][col][row]);
		row++;
	}
}

void	ft_fill_pixels(t_map *map, t_text *text, int text_nb, int fd)
{
	int		col;

	text->pixels[text_nb] = (int **)malloc(sizeof(int *) * (text->columns + 1));
	col = 1;
	while (col - 1 != text->columns)
	{
		text->pixels[text_nb][col] = malloc(sizeof(int *) * (text->rows + 1));
		ft_parse_pixel_column(text, col, text_nb);
		col++;
	}
	
}

void	ft_create_pixels_array(t_map *map, t_text *text, int text_nb, int fd)
{
	char	*line;
	int		col;
	int		row;

	text->pixels_map = (char **)malloc(sizeof(char *) * (text->rows + 1));
	line = get_next_line(fd);
	row = 0;
	while (line != NULL && row != text->rows)
	{
		text->pixels_map[row] = ft_strdup(line);
		//printf("%s\n", text->pixels_map[row]);
		free(line);
		line = get_next_line(fd);
		row++;
	}
}

void	ft_fill_colors(t_map *map, t_text *text, int text_nb, int fd)
{
	int end_row;
	int i;
	char *line;
	int row;
	
	text->colors = (char **)malloc(sizeof(char *) * (text->nb_colors + 1));
	end_row = text->nb_colors + 5;
	i = 3;
	line = get_next_line(fd);
	row = 0;
	while (i < end_row - 2)
	{
		text->colors[row] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
		row++;
	}
	ft_create_pixels_array(map, text, text_nb, fd);
	ft_fill_pixels(map, text, text_nb, fd);
}

void	parse_xpm(char *texture_path, t_map *map, t_text *text, int text_nb)
{
	int fd;
	char *line;
	int	i;

	fd = open(texture_path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (i != 3)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	ft_extract_text_data(line, text);
	ft_fill_colors(map, text, text_nb, fd);
	//text->pixels[NO_TEXTURE][32] = malloc(sizeof(int) * (text->columns + 1));
}

void	xpm_parser(char *texture_path, t_map *map, t_text *text, int text_nb)
{
	parse_xpm(texture_path, map, text, text_nb);
}


