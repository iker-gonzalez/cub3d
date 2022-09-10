/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/10 19:23:45 by ikgonzal         ###   ########.fr       */
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
void	ft_init_structs(t_player *p)
{
	p->mlx = malloc(sizeof(t_mlx));
	p->img = malloc(sizeof(t_img));
	p->ray = malloc(sizeof(t_ray));
	p->draw = malloc(sizeof(t_draw));
	p->text = malloc(sizeof(t_text));
	p->map = malloc(sizeof(t_map));
	ft_memset(p->ray, 0, sizeof(t_ray));
	ft_memset(p->mlx, 0, sizeof(t_mlx));
	ft_memset(p->text, 0, sizeof(t_text));
	ft_memset(p->img, 0, sizeof(t_img));
	ft_memset(p->draw, 0, sizeof(t_draw));
	ft_memset(p->map, 0, sizeof(t_map));
	p->map->render_2 = 0;
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

void ft_raycasting(t_player *p)
{
	p->mlx->mlx = mlx_init();
	if (xpm_parser(p->mlx, p->map, p->text))
		exit (1);
	p->mlx->mlx_win = mlx_new_window(p->mlx->mlx, WIN_WIDTH, WIN_HEIGHT, GAME_TITLE);
	p->map->current_col = -1;
	init_new_img(p);
}

void	ft_get_all(t_tmp *tmp, t_player *p, char *argv)
{
	ft_get_y(tmp);
	ft_init_int(tmp);
	ft_premap(argv, tmp);
	ft_headers(tmp);
	ft_change_struct(tmp, p->map);
	ft_print_map(p->map->map_content);
}

void	ft_init_player_dir(t_player *player)
{
	player->posY = player->map->player_x;
	player->posX = player->map->player_y;
	if (player->map->player == 'N')
	{
		player->dirX = -1.0;
		player->planeY = 0.66;
	}
	else if (player->map->player == 'S')
	{
		player->dirX = 1.0;
		player->planeY = -0.66;
	}
	else if (player->map->player == 'W')
	{
		player->dirY = 1.0;
		player->planeX = 0.66;
	}
	else if (player->map->player == 'E')
	{
		player->dirY = -1.0;
		player->planeX = -0.66;
	}
}

int	main(int argc, char **argv)
{
	t_tmp	tmp;
	t_player p;

	if (argc != 2)
		ft_print_error(1, &tmp);
	if (!ft_check_extension(argv[1]))
		return (0);
	ft_init_structs(&p);
	ft_init_tmp(&tmp, p.map);
	tmp.fd = open(argv[1], O_RDONLY);
	if (tmp.fd == -1)
 		ft_print_error(1, &tmp);
	ft_get_all(&tmp, &p, argv[1]);
	ft_init_player_dir(&p);
	ft_raycasting(&p);
	raycasting_loop(&p);
	ft_hook(&p);
	mlx_loop_hook(p.mlx->mlx, raycasting_loop, &p);
	mlx_loop(p.mlx->mlx);
	//ft_free_all(&tmp, p.map);
	return (1);
}
