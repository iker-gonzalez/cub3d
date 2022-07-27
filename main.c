
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/27 21:07:22 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void ft_print_map(char **map)
{
	int j;
	int i;

	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			printf("%c", map[j][i]);
			i++;
		}
		j++;
	}
}

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
				data->x = ft_strlen(line) - 1;
			data->y++;
		}
	}
	else
		printf("Error: File\n");
	close(data->fd);
}

char	**ft_premap(char *map, t_data *data)
{
	char	*tbl;
	char	**premap;
	size_t	i;
	int		j;
	size_t		size;

	data->fd = open(map, O_RDONLY);
	premap = (char **)malloc((data->y) * sizeof(char *));
	j = 0;;
	tbl = NULL;
	while (j < (data->y))
	{
		tbl = get_next_line(data->fd);
		if (tbl != NULL)
			size = ft_strlen(tbl);
		premap[j] = (char *)malloc(size * sizeof(char));
		i = 0;
		while (i <= size)
		{
			premap[j][i] = tbl[i];
			i++;
		}
		j++;
	}
	premap[j + 1] = NULL;
	/* ft_print_map(premap); */
	close(data->fd);
	return (premap);
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
	ft_premap(argv[1], &data);
	return (0);
}
