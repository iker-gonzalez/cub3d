/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/07 14:12:14 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"

void	ft_change_struct(t_tmp *tmp, t_map *map)
{
	map->no_texture = ft_substr(tmp->no_path, 0, ft_strlen(tmp->no_path) - 1);
	map->so_texture = ft_substr(tmp->so_path, 0, ft_strlen(tmp->so_path) - 1);
	map->ea_texture = ft_substr(tmp->ea_path, 0, ft_strlen(tmp->ea_path) - 1);
	map->we_texture = ft_substr(tmp->we_path, 0, ft_strlen(tmp->we_path) - 1);
	map->f_color = tmp->f_int;
	map->c_color = tmp->c_int;
	map->player = tmp->player;
	map->map_content = tmp->map;
	map->columns = (int)tmp->max_x - 1;
	map->rows = tmp->map_y + 1;
	map->player_x = tmp->player_x;
	map->player_y = tmp->player_y;
}

void	ft_premap(char *map, t_tmp *tmp)
{
	int		j;

	tmp->fd = open(map, O_RDONLY);
	tmp->premap = (char **)malloc((tmp->y + 1) * sizeof(char *));
	j = 0;
	while (j <= (tmp->y))
	{
		tmp->ln = get_next_line(tmp->fd);
		if (tmp->ln == NULL)
			break ;
		if ((tmp->ln[0] == '\n') || (tmp->ln && ft_isspace(tmp->ln)))
		{
			free(tmp->ln);
			continue ;
		}
		if (tmp->max_x < ft_strlen(tmp->ln))
			tmp->max_x = ft_strlen(tmp->ln);
		tmp->premap[j] = ft_strdup(tmp->ln);
		j++;
		free(tmp->ln);
	}
	tmp->premap[j] = NULL;
	tmp->ln = NULL;
	ft_extract_map(tmp);
	close(tmp->fd);
}

void	ft_init_int(t_tmp *tmp)
{
	int	i;

	i = -1;
	tmp->f_int = (int **)malloc(3 * sizeof(int *));
	while (++i < 3)
		tmp->f_int[i] = (int *)malloc(sizeof(int));
	i = -1;
	tmp->c_int = (int **)malloc(3 * sizeof(int *));
	while (++i < 3)
		tmp->c_int[i] = (int *)malloc(sizeof(int));
}

void	ft_init_tmp(t_tmp *tmp, t_map *map)
{
	tmp->premap = NULL;
	tmp->map = NULL;
	tmp->rgb = 'a';
	tmp->y = 0;
	tmp->x = 0;
	tmp->max_x = 0;
	tmp->map_y = 0;
	tmp->pos = 0;
	tmp->err = 0;
	tmp->ln = " ";
	tmp->no_path = NULL;
	tmp->so_path = NULL;
	tmp->ea_path = NULL;
	tmp->we_path = NULL;
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->ea_texture = NULL;
	map->we_texture = NULL;
}

int	main(int argc, char **argv)
{
	t_tmp	tmp;
	t_map	map;

	if (argc != 2)
		ft_print_error(1, &tmp);
	if (!ft_check_extension(argv[1]))
		return (0);
	ft_init_tmp(&tmp, &map);
	tmp.fd = open(argv[1], O_RDONLY);
	if (tmp.fd == -1)
		ft_print_error(1, &tmp);
	ft_get_y(&tmp);
	ft_init_int(&tmp);
	ft_premap(argv[1], &tmp);
	ft_headers(&tmp);
	ft_change_struct(&tmp, &map);
	ft_print_map(map.map_content);
	ft_free_all(&tmp, &map);
	return (1);
}
