/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/30 21:27:51 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"

void	ft_change_struct(t_tmp *tmp, t_map *map)
{
	map->no_texture = tmp->no_path;
	map->so_texture = tmp->so_path;
	map->ea_texture = tmp->ea_path;
	map->we_texture = tmp->we_path;
	map->f_color = tmp->f_int;
	map->c_color = tmp->c_int;
	map->map_content = tmp->map;
}

	/* printf("map.F[0] -> %d\n", map->f_color[0][0]); */
	/* printf("map.F[1] -> %d\n", map->f_color[1][0]); */
	/* printf("map.F[2] -> %d\n", map->f_color[2][0]); */
	/* printf("map.C[0] -> %d\n", map->c_color[0][0]); */
	/* printf("map.C[1] -> %d\n", map->c_color[1][0]); */
	/* printf("map.C[2] -> %d\n", map->c_color[2][0]); */
	/* /1* printf(">>> %s\n", map->no_texture); *1/ */
	/* printf(">>> %s\n", map->so_texture); */
	/* printf(">>> %s\n", map->ea_texture); */
	/* printf(">>> %s\n", map->we_texture); */

void	ft_premap(char *map, t_tmp *tmp)
{
	int		j;

	tmp->fd = open(map, O_RDONLY);
	tmp->premap = (char **)malloc((tmp->y + 1) * sizeof(char *));
	j = 0;
	while (j < (tmp->y))
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
	ft_extract_map(tmp);
	close(tmp->fd);
}
		/* printf("J ------ %d\n", j); */
	/* ft_print_premap(tmp); */
		/* ft_sizelines(tmp); */

void ft_init_int(t_tmp *tmp, t_map *map)
{
	int i;

	i = -1;
	tmp->f_int = (int **)malloc(3 * sizeof(int *));
	while (++i < 3)
		tmp->f_int[i] = (int *)malloc(sizeof(int));
	i = -1;
	tmp->c_int = (int **)malloc(3 * sizeof(int *));
	while (++i < 3)
		tmp->c_int[i] = (int *)malloc(sizeof(int));
	i = -1;
	map->f_color = (int **)malloc(3 * sizeof(int *));
	while (++i < 3)
		map->f_color[i] = (int *)malloc(sizeof(int));
	i = -1;
	map->c_color = (int **)malloc(3 * sizeof(int *));
	while (++i < 3)
		map->c_color[i] = (int *)malloc(sizeof(int));
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
	tmp->ln = " ";
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->ea_texture = NULL;
	map->we_texture = NULL;
	ft_init_int(tmp, map);
}

void	ft_free_all(t_tmp *tmp, t_map *map)
{
	if (tmp->premap != NULL)
		ft_free(tmp->premap);
	if (tmp->map != NULL)
		ft_free(tmp->map);
	if (map->no_texture != NULL)
		free(map->no_texture);
	if (map->so_texture != NULL)
		free(map->so_texture);
	if (map->ea_texture != NULL)
		free(map->ea_texture);
	if (map->we_texture != NULL)
		free(map->we_texture);
	if (tmp->f_int != NULL)
		ft_free_int(tmp->f_int);
	if (tmp->c_int != NULL)
		ft_free_int(tmp->c_int);
	if (map->f_color != NULL)
		ft_free_int(map->f_color);
	if (map->c_color != NULL)
		ft_free_int(map->c_color);
}

int	main(int argc, char **argv)
{
	t_tmp	tmp;
	t_map	map;

	ft_init_tmp(&tmp, &map);
	tmp.fd = open(argv[1], O_RDONLY);
	if (argc != 2 || tmp.fd == -1)
		ft_print_error(1, &tmp);
	if (!ft_check_extension(argv[1]))
		return (0);
	else
		ft_get_y(&tmp);
	ft_premap(argv[1], &tmp);
	ft_headers(&tmp);
	ft_change_struct(&tmp, &map);
	ft_print_map(map.map_content);
	ft_free_all(&tmp, &map);
	return (1);
}
	/* printf("MAX---%zu\n", tmp.max_x); */
