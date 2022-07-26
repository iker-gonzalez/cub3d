/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/26 20:34:30 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_get_axis(t_data *data)
{
	char	*line;

	data->y = 0;
	data->x = 0;
	if (!data->fd || data->fd != -1)
	{
		line = " ";
		while (line != NULL)
		{
			line = get_next_line(data->fd);
			/* printf("%s\n", tbl); */
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

char	**ft_matrix(char *map, t_data *data)
{
	char	*tbl;
	char	**mat;
	size_t		i;
	int		j;

	data->fd = open(map, O_RDONLY);
	mat = (char **)malloc(data->y * sizeof(char *));
	j = 0;;
	tbl = NULL;
	while (j < data->y)
	{
		tbl = get_next_line(data->fd);
		/* printf("%s\n", tbl); */
		mat[j] = (char *)malloc(data->x * sizeof(char));
		i = 0;
		while (i < (data->x - 2))
		{
			mat[j][i] = tbl[i];
			printf("%c", mat[j][i]);
			/* free(tbl[i]); */
			i++;
		}
		/* free(tbl); */
		j++;
	}
	close(data->fd);
	return (mat);
}


int	main(int argc, char **argv)
{
	t_data	data;

	data.fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		printf("Error: incorrect number of arguments\n");
		return (1);
	}
	if (ft_check_extension(argv[1]))
		return (1);
	else
		ft_get_axis(&data);
	printf("X_axis >>>>>>>>> %zu\n", data.x);
	printf("Y_axis >>>>>>>>> %d\n", data.y);
	ft_matrix(argv[1], &data);
	return (0);
}
