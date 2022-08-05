/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/05 19:14:23 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

int	ft_isstrprint(t_data *data)
{
	int i;

	i = 0;
	while(data->line[i])
	{
		if(ft_isprint(data->line[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_isstrspace(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(data->line[i])
	{
		if(data->line[i] == ' ' || data->line[i] == '\t')
			j++;
		i++;
	}
	printf("I >>>>>>>>>> %d\n", i);
	printf("J >>>>>>>>>> %d\n", j);
	if ((i - 1) == j && j != 0)
		return (1);
	return (0);
}

int	ft_isspace(char *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data[i])
	{
		if (data[i] == ' ')
			j++;
		i++;
	}
	i -= 1;
	printf("I >>>>>>>>>> %d\n", i);
	printf("J >>>>>>>>>> %d\n", j);
	if (i == j && j != 0)
		return (1);
	return (0);
}


int	ft_print_error(int errno)
{
	if (errno == 1)
		printf("Error:\nWrong number of arguments\n");
	if (errno == 2)
		printf("Error:\nNot Allowed Line First Char or Map Position\n");
	if (errno == 3)
		printf("Error:\nWrong newline or char position\n");
	exit (1);
}

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

int	ft_fchar(char *line)
{
	int		i;

	i = 0;
	while (line[i] == ' ')
		i++;
	/* printf("I >>>>>>>>>> %d\n", i); */
	/* printf("line[i]>>>>>>>>>> %c\n", line[i]); */
	printf("AQUI\n");
	if (line[i] == '1')
		return (1);
	return (0);
}

int	ft_check_fchars(t_data *data)
{
	int		i;
	int		j;
	char	*set;

	i = 0;
	set = "NSEWFC1";
	while (data->line[i] == ' ')
		i++;
	j = 0;
	while (set[j])
	{
		if (data->line[i] == '0' || data->line[i] == '1')
			data->order = 1;
		if (set[j] == data->line[i] || data->line[i] == '\n')
			break ;
		j++;
	}
	if (j > 7 || (data->y < 6 && data->order > 0))
		ft_print_error(2);
	return (1);
}

void	ft_get_y(t_data *data)
{
	int i;

	i = 0;
	data->y = 0;
	data->order = 0;
	if (!data->fd || data->fd != -1)
	{
		data->line = " ";
		while (data->line != NULL)
		{
			printf("order -> %d\n", data->order);
			data->line = get_next_line(data->fd);
			if (data->line == NULL || !ft_check_fchars(data))
				break ;
			if ((data->line[0] != '\n') || (!ft_isspace(data->line) && ft_fchar(data->line)))
				data->y++;
			if (data->line[0] == '\n' && data->order != 0)
				i = 1;
			if (i && data->line[0] != '\n')
			{
				/* printf("i -> %d\n", i); */
				ft_print_error(3);
			}
		}
	}
	else
		printf("Error:\nFile\n");
	close(data->fd);
}

/* void	ft_tblchecks(char *tbl, t_data *data) */
/* { */
/* 	data->x = 0; */
/* 	if (ft_fchar(tbl)) */
/* 		data->x = 1; */
/* 	if (ft_isspace(tbl) && data->x == 0) */
/* 		free(tbl); */
/* } */

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
		if (tbl == NULL)
			break ;
		if ((tbl[0] == '\n') || (tbl && ft_isspace(tbl) && !ft_fchar(tbl)))
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
	ft_print_premap(data);
	close(data->fd);
}


int	main(int argc, char **argv)
{
	t_data	data;

	data.fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		ft_print_error(1);
	if (!ft_check_extension(argv[1]))
		return (0);
	else
		ft_get_y(&data);
	ft_premap(argv[1], &data);
	return (1);
}
