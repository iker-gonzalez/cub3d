/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_text_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:18:41 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/23 18:06:19 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


void	ft_extract_colors_nb(char *line, t_text *text, int end)
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

void	ft_skip_to_color_nb(char *line, t_text *text)
{
	int start;
	int end;

	start = 0;
	while (!ft_isdigit((int)line[start]))
		start++;
	end = start;
	while (line[end] != ' ')
		end++;
	start = end + 1;
	while (!ft_isdigit((int)line[start]))
		start++;
	end = start;
	while (line[end] != ' ')
		end++;
	ft_extract_colors_nb(line, text, end);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

uint32_t hex2int(char *hex) {
	
	uint32_t val;
	int i;

	val = 0;
	i = 0;
	while (hex[i] != '\0') 
	{
		// transform hex character to the 4bit equivalent number, using the ascii table indexes
		if (hex[i] >= '0' && hex[i] <= '9')
			hex[i] = hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <='f')
			hex[i] = hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <='F')
			hex[i] = hex[i] - 'A' + 10;
		// shift 4 to make space for new digit, and add the 4 bits of the new digit 
		val = (val << 4) | (hex[i] & 0xF);
		i++;
	}
	return (val);
}

int	ft_hex_to_int(char *color)
{
	int i;
	char *hex;

	i = 0;
	while (color[i] != '#' || i < 2)
		i++;
	i++;
	hex = ft_substr(color, i, 6);
	return (hex2int(hex));
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
		while(text->pixels_map[row][col] != text->colors[k][1])
			k++;
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

	text->pixels_map = (char **)malloc(sizeof(char *) * (text->rows + 1));
	line = get_next_line(fd);
	row = 0;
	while (row < text->rows)
	{
		text->pixels_map[row] = ft_substr(line, 1, 64);
		free(line);
		line = get_next_line(fd);
		row++;
	}
	text->pixels_map[row] = NULL;
}

void	ft_fill_colors(t_text *text, int text_nb, int fd)
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
	ft_create_pixels_array(text, fd);
	ft_fill_pixels(text, text_nb);
}

void	parse_xpm(char *texture_path, t_text *text, int text_nb)
{
	int fd;
	char *line;
	int	i;

	fd = open(texture_path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: file on path %s can not be open\n", texture_path);
		return ;
	}
	line = get_next_line(fd);
	i = 0;
	while (i < 3)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	ft_skip_to_color_nb(line, text);
	ft_fill_colors(text, text_nb, fd);
}

int	ft_validate_xpm(char *path, void *mlx, t_text *text)
{
	void	*img;
	
	img = mlx_xpm_file_to_image(mlx, path, &text->columns, &text->rows);
	if (img == NULL)
	{
		printf("Error: invalid xpm\n");
		return (1);
	}
	return (0);
}

int	xpm_parser(t_mlx *mlx, t_map *map, t_text *text)
{
	text->pixels = (int ***)malloc(sizeof(int **) * (NB_TEXTURES + 1));
	if (ft_validate_xpm(map->no_texture, mlx->mlx, text))
		return (1);
	else
		parse_xpm(map->no_texture, text, NO_TEXTURE);

	if (ft_validate_xpm(map->ea_texture, mlx->mlx, text))
		return (1);
	else
		parse_xpm(map->ea_texture, text, EA_TEXTURE);	
	if (ft_validate_xpm(map->so_texture, mlx->mlx, text))
		return (1);
	else
		parse_xpm(map->so_texture, text, SO_TEXTURE);
	if (ft_validate_xpm(map->we_texture, mlx->mlx, text))
		return (1);
	else
		parse_xpm(map->we_texture, text, WE_TEXTURE);
	return (0);
}