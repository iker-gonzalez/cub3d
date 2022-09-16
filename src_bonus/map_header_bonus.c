/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:36:08 by ingonzal          #+#    #+#             */
/*   Updated: 2022/09/16 19:42:36 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	ft_color_int(int rgb, int i, t_tmp *tmp)
{
	if (tmp->rgb == 'F')
		tmp->f_int[i][0] = rgb;
	if (tmp->rgb == 'C')
		tmp->c_int[i][0] = rgb;
}

void	ft_check_values(char *val, t_player *p, char **str)
{
	int		rgb[3];
	int		i;
	int		j;
	char	**line;

	i = -1 ;
	line = ft_split(val, ',');
	free(val);
	while (line[++i] != NULL)
	{
		if (i > 2)
			ft_free_value(line, p, str);
		rgb[i] = ft_atoi(line[i]);
		ft_color_int(rgb[i], i, p->tmp);
		j = -1;
		while (ft_isprint(line[i][++j]))
		{
			if (!ft_isdigit(line[i][j]))
				ft_free_value(line, p, str);
		}
	}
	if (i != 3 || rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255
		|| rgb[0] < 0 || rgb[1] < 0 || rgb[2] < 0)
		ft_free_value(line, p, str);
	ft_free(line);
}

void	ft_check_paths(t_player *p)
{
	if (p->tmp->no_path == NULL || p->tmp->so_path == NULL
		|| p->tmp->ea_path == NULL || p->tmp->we_path == NULL
		|| p->tmp->f_val == NULL || p->tmp->c_val == NULL)
		ft_print_error(7, p);
}

void	ft_select_texture(char **line, t_player *p)
{
	if (ft_check_l(line[1]) || ft_strlen(line[0]) > 2
		|| (ft_strncmp(line[0], "F", 1) == 0 && ft_strlen(line[0]) != 1)
		|| (ft_strncmp(line[0], "C", 1) == 0 && ft_strlen(line[0]) != 1))
		ft_free_last(line, p);
	if (ft_strncmp(line[0], "NO", 2) == 0)
		p->tmp->no_path = ft_strdup(line[1]);
	if (ft_strncmp(line[0], "SO", 2) == 0)
		p->tmp->so_path = ft_strdup(line[1]);
	if (ft_strncmp(line[0], "EA", 2) == 0)
		p->tmp->ea_path = ft_strdup(line[1]);
	if (ft_strncmp(line[0], "WE", 2) == 0)
		p->tmp->we_path = ft_strdup(line[1]);
	if (ft_strncmp(line[0], "F", 1) == 0)
	{
		p->tmp->f_val = ft_strdup(line[1]);
		p->tmp->rgb = 'F';
		ft_check_values(p->tmp->f_val, p, line);
	}
	if (ft_strncmp(line[0], "C", 1) == 0)
	{
		p->tmp->c_val = ft_strdup(line[1]);
		p->tmp->rgb = 'C';
		ft_check_values(p->tmp->c_val, p, line);
	}
	ft_free(line);
}

void	ft_headers(t_player *p)
{
	int		i;
	int		j;
	char	**line;

	i = -1;
	while (++i < 6 && p->tmp->premap[i] != NULL)
	{
		line = ft_split(p->tmp->premap[i], ' ');
		j = 0;
		while (line[j] != NULL)
		{
			if (line[j][0] == '\n')
				break ;
			j++;
		}
		if (j > 2)
		{
			if (line != NULL)
				ft_free(line);
			ft_print_error(7, p);
		}
		else
			ft_select_texture(line, p);
	}
	ft_check_paths(p);
}
