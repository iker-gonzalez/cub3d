/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/30 21:40:44 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_print_premap(t_data *data)
{
	int	j;
	int	i;

	j = 0;
	while (data->premap[j] != NULL)
	{
		i = 0;
		while (data->premap[j][i] != '\0')
		{
			printf("%c", data->premap[j][i]);
			i++;
		}
		j++;
	}
}

int	ft_check_fchars(t_data *data)
{
	int		i;
	int		j;
	char	*set;

	i = 0;
	set = "NSEWFC10";
	while (data->line[i] == ' ')
		i++;
	j = 0;
	data->order = 0;
	while (set[j])
	{
		if (data->line[i] == '0' || data->line[i] == '1')
			data->order++;
		if (set[j] == data->line[i] || data->line[i] == '\n')
			break ;
		j++;
	}
	if (j > 7 || (data->y < 6 && data->order > 0))
	{
		printf("Error:\nNot Allowed Line First Char or Position\n");
		return (0);
	}
	return (1);
}

void	ft_get_y(t_data *data)
{
	data->y = 0;
	if (!data->fd || data->fd != -1)
	{
		data->line = " ";
		while (data->line != NULL)
		{
			data->line = get_next_line(data->fd);
			if (data->line == NULL || !ft_check_fchars(data))
				break ;
			if (data->line[0] != '\n')
				data->y++;
		}
	}
	else
		printf("Error:\nFile\n");
	close(data->fd);
}

void	ft_premap(char *map, t_data *data)
{
	char	*tbl;
	size_t	size;
	size_t	i;
	int		j;

	data->fd = open(map, O_RDONLY);
	data->premap = (char **)malloc((data->y + 1) * sizeof(char *));
	j = 0;
	tbl = NULL;
	while (j < (data->y))
	{
		tbl = get_next_line(data->fd);
		if (tbl[0] == '\n')
			continue ;
		if (tbl != NULL)
			size = ft_strlen(tbl);
		data->premap[j] = (char *)malloc((size + 1) * sizeof(char));
		i = -1;
		while (++i < size)
			data->premap[j][i] = tbl[i];
		data->premap[j][i] = '\0';
		j++;
	}
	data->premap[j] = NULL;
	close(data->fd);
}

	/* ft_print_premap(data); */

int	main(int argc, char **argv)
{
	t_data	data;

	data.fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		printf("Error:\nWrong number of arguments\n");
		return (1);
	}
	if (ft_check_extension(argv[1]))
		return (1);
	else
		ft_get_y(&data);
	ft_premap(argv[1], &data);
	return (0);
}
