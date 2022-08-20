/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:36:08 by ingonzal          #+#    #+#             */
/*   Updated: 2022/08/20 21:22:58 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include "stdio.h"

void	ft_check_values(char *val, t_tmp *tmp)
{
	int		rgb[3];
	int		i;
	int		j;
	char	**line;

	i = -1 ;
	line = ft_split(val, ',');
	while (line[++i] != NULL)
	{
		rgb[i] = ft_atoi(line[i]);
		j = 0;
		while (ft_isprint(line[i][j]))
		{
			if (!ft_isdigit(line[i][j]))
				ft_print_error(7, tmp);
			j++;
		}
	}
	if (i != 3 || rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255
		|| rgb[0] < 0 || rgb[1] < 0 || rgb[2] < 0)
	{
		ft_free(line);
		ft_print_error(7, tmp);
	}
	ft_free(line);
}

			/* printf("String >>>>>>> %c\n", line[i][j]); */
			/* printf("String >>>>>>> %s\n", line[j]); */
			/* printf("J >>>>>>>>>>>> %d\n", j); */
void	ft_check_paths(t_tmp *tmp)
{
	if (tmp->no_path == NULL || tmp->so_path == NULL || tmp->ea_path == NULL
		|| tmp->we_path == NULL || tmp->f_val == NULL || tmp->c_val == NULL)
		ft_print_error(7, tmp);
}

void	ft_select_texture(char **line, t_tmp *tmp)
{
	if (ft_strncmp(line[0], "NO", 2) == 0)
		tmp->no_path = line[1];
	if (ft_strncmp(line[0], "SO", 2) == 0)
		tmp->so_path = line[1];
	if (ft_strncmp(line[0], "EA", 2) == 0)
		tmp->ea_path = line[1];
	if (ft_strncmp(line[0], "WE", 2) == 0)
		tmp->we_path = line[1];
	if (ft_strncmp(line[0], "F", 2) == 0)
	{
		tmp->f_val = line[1];
		ft_check_values(tmp->f_val, tmp);
	}
	if (ft_strncmp(line[0], "C", 2) == 0)
	{
		tmp->c_val = line[1];
		ft_check_values(tmp->c_val, tmp);
	}
	ft_free(line);
}

		/* printf("TMP String >>>>>>> %s\n", tmp->no_path); */
		/* printf("TMP String >>>>>>> %s\n", tmp->so_path); */
		/* printf("TMP String >>>>>>> %s\n", tmp->ea_path); */
		/* printf("TMP String >>>>>>> %s\n", tmp->we_path); */
		/* printf("TMP String >>>>>>> %s\n", tmp->f_val); */
		/* printf("TMP String >>>>>>> %s\n", tmp->c_val); */
		/* printf("IN String >>>>>>> %s\n", line[0]); */
		/* printf("TMP String >>>>>>> %s\n", tmp->no_path); */
		/* printf("WORKS!!!!!!\n"); */
		/* printf("IN!!!!!!\n"); */

void	ft_headers(t_tmp *tmp)
{
	int		i;
	int		j;
	char	**line;

	i = 0;
	while (i < 6 && tmp->premap[i] != NULL)
	{
		line = ft_split(tmp->premap[i], ' ');
		j = 0;
		while (line[j] != NULL)
			j++;
		if (j > 2)
		{
			ft_free(line);
			ft_print_error(7, tmp);
		}
		else
			ft_select_texture(line, tmp);
		i++;
	}
	ft_check_paths(tmp);
}

			/* printf("String >>>>>>> %s\n", line[j]); */
			/* printf("J >>>>>>>>>>>> %d\n", j); */
