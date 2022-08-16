/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:34:02 by ingonzal          #+#    #+#             */
/*   Updated: 2022/08/16 21:19:04 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
/* #include <stdio.h> */

/* void	ft_walls_cases(t_tmp *tmp, int i, int j) */
/* { */
/* 	if (((tmp->map[i][j] == ' ') */
/* 		&& ((tmp->map[i][j + 1] != ' ') && (tmp->map[i][j + 1] != '\n'))) && */
/* 	(((tmp->map[i][j + 1] != '1')) || */
/* 	((tmp->map[i + 1][j] != ' ') && (tmp->map[i + 1][j] != '1')))) */
/* 		ft_print_error(5, tmp); */
/* 	if ((tmp->map[0][j] == '1') && */
/* 	((((tmp->map[0][j + 1]) != '1') && ((tmp->map[0][j + 1]) != '\n')) && */
/* 	((tmp->map[0][j + 1]) != ' '))) */
/* 		ft_print_error(5, tmp); */
/* 	if ((tmp->map[i][j] == '0') && */
/* 	(((tmp->map[i][j + 1]) != '1') && ((tmp->map[i][j + 1]) != '0') && */
/* 	(tmp->map[i][j + 1] != tmp->player))) */
/* 		ft_print_error(5, tmp); */
/* 	if ((tmp->map[i][j] == '0') && */
/* 	((tmp->map[i + 1][j] != '1') && (tmp->map[i + 1][j] != tmp->player) && */
/* 	(tmp->map[i + 1][j] != '0'))) */
/* 		ft_print_error(5, tmp); */
/* 	if ((tmp->map[tmp->y - 9][j] != '1') && (tmp->map[tmp->y - 9][j] != ' ') && */
/* 	(tmp->map[tmp->y - 9][j] != '\n')) */
/* 		ft_print_error(5, tmp); */
/* } */	

/* void	ft_check_walls(t_tmp *tmp) */
/* { */
/* 	int	i; */
/* 	int	j; */

/* 	i = 0; */
/* 	while (tmp->map[i + 1] != NULL) */
/* 	{ */
/* 		j = 0; */
/* 		while (tmp->map[i][j]) */
/* 		{ */
/* 			ft_walls_cases(tmp, i, j); */
/* 			j++; */
/* 		} */
/* 		i++; */
/* 	} */
/* } */
				/* printf(">>>>>>>> %d\n", tmp->y); */
				/* printf("> ->%c\n", tmp->map[i][j]); */
				/* printf("j+1 ->%c\n", tmp->map[i][j+1]); */
				/* printf("i+1 ->%c\n", tmp->map[i+1][j]); */
				/* printf("elsei+1 ->%c\n", tmp->map[i+1][j]); */
				/* printf("else> ->%c\n", tmp->map[i][j]); */
				/* printf("elsej+1 ->%c\n", tmp->map[i][j+1]); */

void	ft_check_player(t_tmp *tmp)
{
	char		*set;
	static int	i;
	int			j;
	int			k;
	static int	o;

	set = "NSWO";
	while (tmp->map[++i] != NULL)
	{
		j = -1;
		while (tmp->map[i][++j])
		{
			k = -1;
			while (set[++k])
			{
				if (set[k] == tmp->map[i][j])
				{
					tmp->player = tmp->map[i][j];
					o += 1;
				}
			}
		}
	}
	if (o != 1)
		ft_print_error(6, tmp);
}

	/* printf("A >>>>%d\n", o); */
	/* printf("Char >>>%c\n", tmp->map[i][j]); */
	/* printf("B >>>>%d\n", o); */
	/* printf("C >>>>%d\n", o); */

/* void	ft_check_mapchars(t_tmp *tmp) */
/* { */
/* 	char	*set; */
/* 	int		i; */
/* 	int		j; */
/* 	int		k; */

/* 	set = "10NSWO "; */
/* 	i = -1; */
/* 	while (tmp->map[++i] != NULL) */
/* 	{ */
/* 		j = -1; */
/* 		while (tmp->map[i][++j]) */
/* 		{ */
/* 			k = -1; */
/* 			while (set[++k]) */
/* 			{ */
/* 				if (set[k] == tmp->map[i][j] || tmp->map[i][j] == '\n') */
/* 					break ; */
/* 			} */
/* 			if (k > 6) */
/* 				ft_print_error(4, tmp); */
/* 		} */
/* 	} */
/* 	ft_check_player(tmp); */
/* 	ft_check_walls(tmp); */
/* } */
				/* printf(">>>>>%d\n", k); */

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
	tmp->map = (char **)malloc((tmp->y - 6) * sizeof(char *));
	while (tmp->premap[y] != NULL)
	{
		tmp->map[i] = (char *)malloc((tmp->max_x) * sizeof(char));
		x = 0;
		while (x < tmp->max_x)
		{
			tmp->map[i][x] = tmp->premap[y][x];
			if (tmp->premap[y][x] == '\n' && x < tmp->max_x)
				x = ft_fill_blanks(x, i, tmp);
			x++;
		}
		tmp->map[i][x - 1] = '\n';
		tmp->map[i][x] = '\0';
		y++;
		i++;
	}
	tmp->map[i] = NULL;
	ft_check_mapchars(tmp);
}
