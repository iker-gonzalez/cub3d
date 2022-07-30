/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_text_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:18:41 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/30 12:27:18 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

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

void	ft_parse_pixel_row(char *line, t_text *text)
{
	int i;
	int x;

	i = 1;
	x = 0;
	printf("line[i]: %c\n", line[i]);
	printf("text->colors[x][1]: %c\n", text->colors[x][1]);
	while(line[i] != text->colors[x][1])
		x++;
	printf("color discovered: %s\n", text->colors[x]);
	
}

void	ft_fill_pixels(t_map *map, t_text *text, int text_nb, int fd)
{
	char	*line;
	int		row;

	text->pixels[text_nb] = (int **)malloc(sizeof(int *) * (text->rows + 1));
	line = get_next_line(fd);
	row = 0;
	while (line != NULL)
	{
		text->pixels[text_nb][row] = malloc(sizeof(int *) * (text->columns + 1));
		ft_parse_pixel_row(line, text);
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


