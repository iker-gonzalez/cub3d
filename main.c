/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/25 20:54:49 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_get_axis(char *map, t_data *data)
{
	char	*line;

	data->y = 0;
	data->x = 0;
	data->fd = open(map, O_RDONLY);
	if (!data->fd || data->fd != -1)
	{
		line = " ";
		while (line != NULL)
		{
			line = get_next_line(data->fd);
			if (line == NULL)
				break ;
			if (data->x < ft_strlen(line))
				data->x = ft_strlen(line);
			data->y++;
		}
	}
	else
		printf("Error: File\n");
	close(data->fd);
}

/* int	**ft_matrix(t_data *data) */
/* { */
/* 	char	**tbl; */
/* 	char	*str; */
/* 	int		**mat; */
/* 	int		i; */
/* 	int		j; */

/* 	mat = (int **)malloc(data->y * sizeof(int *)); */
/* 	j = 0; */
/* 	while (get_next_line(fd, &str)) */
/* 	{ */
/* 		tbl = ft_split(str, ' '); */
/* 		free(str); */
/* 		i = 0; */
/* 		mat[j] = (int *)malloc(data->x * sizeof(int)); */
/* 		while (tbl[i]) */
/* 		{ */
/* 			mat[j][i] = ft_atoi(tbl[i]); */
/* 			free(tbl[i]); */
/* 			i++; */
/* 		} */
/* 		free(tbl); */
/* 		j++; */
/* 	} */
/* 	free(str); */
/* 	return (mat); */
/* } */


int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("Error: incorrect number of arguments\n");
		return (1);
	}
	if (ft_check_extension(argv[1]))
		return (1);
	else
		ft_get_axis(argv[1], &data);
	printf("X_axis >>>>>>>>> %zu\n", data.x);
	printf("Y_axis >>>>>>>>> %d\n", data.y);
	/* ft_matrix(argv[1], &data); */
	return (0);
}
