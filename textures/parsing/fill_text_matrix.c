/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_text_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:18:41 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/30 10:46:43 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_text_struct (t_text *text)
{
	text->content = (int ***)malloc(sizeof(int **) * (4 + 1));
	text->content[NO_TEXTURE] = (int **)malloc(sizeof(int *) * (64 + 1));
	text->content[NO_TEXTURE][32] = malloc(sizeof(int) * (64 + 1));
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
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
}

void	parse_xpm(t_map *map, t_text *text)
{
	int fd;
	char *line;
	int	i;

	fd = open(map->no_texture, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		//printf("%s", line);
		free(line);
		line = get_next_line(fd);
		if (i == 2)
			ft_extract_text_data(line, text);
		i++;
	}
}

void	xpm_parser(t_map *map, t_text *text)
{
	init_text_struct(text);
	parse_xpm(map, text);
}


