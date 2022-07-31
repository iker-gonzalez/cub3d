/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_text_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:18:41 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/31 08:51:17 by ikgonzal         ###   ########.fr       */
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

uint32_t hex2int(char *hex) {
    uint32_t val = 0;
	int i;

	i = 0;
    while (hex[i] != '\0') 
	{
        // transform hex character to the 4bit equivalent number, using the ascii table indexes
        if (hex[i] >= '0' && hex[i] <= '9') hex[i] = hex[i] - '0';
        else if (hex[i] >= 'a' && hex[i] <='f') hex[i] = hex[i] - 'a' + 10;
        else if (hex[i] >= 'A' && hex[i] <='F') hex[i] = hex[i] - 'A' + 10;    
        // shift 4 to make space for new digit, and add the 4 bits of the new digit 
        val = (val << 4) | (hex[i] & 0xF);
		i++;
    }
    return val;
}

int	ft_hex_to_int(char *color)
{
	int i;
	char *hex;
	int	value;
	int result;

	i = 0;
	while (color[i] != '#' || i < 2)
		i++;
	i++;
	hex = ft_substr(color, i, 6);
	printf("%s\n", hex);
	return (hex2int(hex));
	/*i = 0;
	while (hex[i] != '\0')
	{
		if ((hex[i] >= 'A' && hex[i] <= 'F'))
			value = hex[i] - UPPERCASE_DIGIT_DIFF;
		else if ((hex[i] >= 'a' && hex[i] <= 'f'))
			value = hex[i] - LOWERCASE_DIGIT_DIFF;
		else if (hex[i] >= '0' && hex[i] <= '9')
			value = hex[i] - '0';
		else
			value = 0;
		result += value * (int)pow((float)16, (float)value);
		i++;
		printf("hola\n");
	}
	printf("\n\n\n\n");
	
	return (0);*/
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
		color = ft_hex_to_int(text->colors[k]);
		//printf("color: %d\n", color);
		text->pixels[text_nb][col][row] = color;
		printf("%d\n\n", text->pixels[text_nb][col][row]);
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


