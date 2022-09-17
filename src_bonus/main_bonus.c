/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/17 10:46:57 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#include <fcntl.h>

void	ft_change_struct(t_tmp *tmp, t_map *map)
{
	char	set[2];

	set[0] = ' ';
	set[1] = '\n';
	map->no_texture = ft_strtrim(tmp->no_path, set);
	map->so_texture = ft_strtrim(tmp->so_path, set);
	map->ea_texture = ft_strtrim(tmp->ea_path, set);
	map->we_texture = ft_strtrim(tmp->we_path, set);
	map->f_color = tmp->f_int;
	map->c_color = tmp->c_int;
	map->player = tmp->player;
	map->map_content = tmp->map;
	map->columns = (int)tmp->max_x - 1;
	map->rows = tmp->map_y + 1;
	map->player_x = tmp->player_x;
	map->player_y = tmp->player_y;
}

void	ft_premap(char *map, t_player *p)
{
	int		j;

	p->tmp->fd = open(map, O_RDONLY);
	p->tmp->premap = (char **)malloc((p->tmp->y + 1) * sizeof(char *));
	j = 0;
	while (j <= (p->tmp->y))
	{
		p->tmp->ln = get_next_line(p->tmp->fd);
		if (p->tmp->ln == NULL)
			break ;
		if ((p->tmp->ln[0] == '\n') || (p->tmp->ln && ft_isspace(p->tmp->ln)))
		{
			free(p->tmp->ln);
			continue ;
		}
		if (p->tmp->max_x < ft_strlen(p->tmp->ln))
			p->tmp->max_x = ft_strlen(p->tmp->ln);
		p->tmp->premap[j] = ft_strdup(p->tmp->ln);
		j++;
		free(p->tmp->ln);
	}
	p->tmp->premap[j] = NULL;
	p->tmp->ln = NULL;
	ft_extract_map(p);
	close(p->tmp->fd);
}

/* Linux function f_raycasting down free_all */
		/* mlx_destroy_display(p->mlx->mlx); */

void	ft_raycasting(t_player *p)
{
	void	*a;

	p->mlx->mlx = mlx_init();
	if (xpm_parser(p->mlx, p->map, p->text))
	{
		ft_free_pixels(p->text, p->text->columns);
		ft_free_all(p);
		free(p->mlx->mlx);
		ft_free_structs(p);
		exit (1);
	}
	a = mlx_new_window(p->mlx->mlx, WIN_WIDTH, WIN_HEIGHT, GAME_TITLE);
	p->mlx->mlx_win = a;
	p->map->current_col = -1;
	init_new_img(p);
}

void	ft_get_all(t_player *p, char *argv)
{
	ft_get_y(p);
	ft_init_int(p->tmp);
	ft_premap(argv, p);
	ft_headers(p);
	ft_change_struct(p->tmp, p->map);
	ft_print_map(p->tmp->premap);
}

int	main(int argc, char **argv)
{
	t_tmp		tmp;
	t_player	p;

	ft_memset(&p, 0, sizeof(t_player));
	if (argc != 2)
		ft_print_error(1, &p);
	if (!ft_check_extension(argv[1]))
		return (0);
	ft_init_structs(&p);
	ft_init_tmp(&tmp, p.map);
	p.tmp = &tmp;
	tmp.fd = open(argv[1], O_RDONLY);
	if (tmp.fd == -1)
		ft_print_error(1, &p);
	ft_get_all(&p, argv[1]);
	ft_init_player_dir(&p);
	ft_raycasting(&p);
	raycasting_loop(&p);
	ft_hook(&p);
	mlx_loop_hook(p.mlx->mlx, raycasting_loop, &p);
	mlx_loop(p.mlx->mlx);
	ft_free_all(&p);
	return (1);
}
