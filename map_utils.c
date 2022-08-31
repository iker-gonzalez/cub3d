/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:34:02 by ingonzal          #+#    #+#             */
/*   Updated: 2022/08/31 21:05:17 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int ft_player_pos(t_tmp *tmp, int i, int j)
{
	static int o;

	tmp->player = tmp->map[i][j];
	tmp->player_y = i;
	tmp->player_x = j;
	tmp->map[i][j] = '0';
	o += 1;

	return (o);
}

/* static int ft_player_pos(t_tmp *tmp, char player, int i, int j) */
/* { */
/* 	char		*set; */
/* 	static int	o; */
/* 	int			k; */
	
/* 	k = 0; */
/* 	set = "NSWE"; */
/* 	while (set[k]) */
/* 	{ */
/* 		if (set[k] == player) */
/* 		{ */
/* 			tmp->player = player; */
/* 			tmp->player_y = i; */
/* 			tmp->player_x = j; */
/* 			tmp->map[i][j] = '0'; */
/* 			o += 1; */
/* 		} */
/* 		k++; */
/* 	} */
/* 	return (o); */
/* } */

void	ft_check_player(t_tmp *tmp)
{
	char		*set;
	int			i;
	int			j;
	int			k;
	static int	o;

	set = "NSWE";
	i = 0;
	while (tmp->map[i] != NULL)
	{
		j = -1;
		while (tmp->map[i][++j])
		{
			k = -1;
			while (set[++k])
			{
				if (set[k] == tmp->map[i][j])
					o = ft_player_pos(tmp, i, j);
			}
		}
		i++;
	}
	if (o != 1)
		ft_print_error(6, tmp);
}

			/* o = ft_player_pos(tmp, tmp->map[i][j], i, j); */
					/* tmp->player = tmp->map[i][j]; */
					/* o += 1; */
					/* tmp->map[i][j] = '0'; */

size_t	ft_fill_blanks(size_t x, int i, t_tmp *tmp)
{
	while (x < tmp->max_x - 1)
	{
		tmp->map[i][x] = ' ';
		x++;
	}
	return (x);
}

void	ft_extract_map(t_tmp *tmp)
{
	int		y;
	int		i;
	size_t	x;

	y = 6;
	i = 0;
	tmp->map = (char **)malloc((tmp->y - 5) * sizeof(char *));
	while (tmp->premap[y] != NULL)
	{
		tmp->map[i] = (char *)malloc((tmp->max_x + 1) * sizeof(char));
		x = -1;
		while (++x < tmp->max_x)
		{
			tmp->map[i][x] = tmp->premap[y][x];
			if (tmp->premap[y][x] == '\n' && x < tmp->max_x)
				x = ft_fill_blanks(x, i, tmp);
		}
		tmp->map[i][x - 1] = '\n';
		tmp->map[i][x] = '\0';
		y++;
		i++;
	}
	tmp->map[i] = NULL;
	tmp->map_y = i - 1;
	ft_check_mapchars(tmp);
}
