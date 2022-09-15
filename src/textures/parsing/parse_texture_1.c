/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:18:41 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/15 19:59:34 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "../../../libft/libft.h"
#include "../../../gnl/get_next_line.h"
#include "../../../mlx/mlx.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_fill_colors(t_text *text, int text_nb, int fd)
{
	int		end_row;
	int		i;
	char	*line;
	int		row;

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
	if (line)
		free(line);
	ft_create_pixels_array(text, fd);
	ft_fill_pixels(text, text_nb);
	ft_free_colors(text, text->nb_colors);
	ft_free_pixels_map(text, text->rows);
}

void	parse_xpm(char *texture_path, t_text *text, int text_nb)
{
	int		fd;
	char	*line;
	int		i;

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
	free(line);
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
	mlx_destroy_image(mlx, img);
	text->valid_text++;
	return (0);
}

int	xpm_parser(t_mlx *mlx, t_map *map, t_text *text)
{
	text->valid_text = 0;
	text->pixels = (int ***)malloc(sizeof(int **) * (NB_TEXTURES));
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
