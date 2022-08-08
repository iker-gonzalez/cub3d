/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/08 20:49:48 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_get_x(t_tmp *tmp)
{
	if (tmp->ln != NULL)
	{
		if (tmp->x < ft_strlen(tmp->ln))
			tmp->x = ft_strlen(tmp->ln);
		if (tmp->ln[tmp->x - 1] == '\n')
			tmp->x = tmp->x - 1;
	}
}
	/* printf("x MAX -> %zu\n", tmp->x); */

void	ft_get_y(t_tmp *tmp)
{
	int	i;

	i = 0;
	if (!tmp->fd || tmp->fd != -1)
	{
		while (tmp->ln != NULL)
		{
			tmp->ln = get_next_line(tmp->fd);
			ft_get_x(tmp);
			if (tmp->ln == NULL || !ft_check_fchars(tmp))
				break ;
			if ((tmp->ln[0] != '\n') || (!ft_isspace(tmp->ln)))
				tmp->y++;
			if (tmp->ln[0] == '\n' && tmp->pos != 0)
				i = 1;
			if ((i && tmp->ln[0] != '\n') || (tmp->pos && ft_isspace(tmp->ln)))
				ft_print_error(3);
			free(tmp->ln);
		}
	}
	else
		printf("Error:\nFile\n");
	close(tmp->fd);
}
			/* printf("pos -> %d\n", tmp->pos); */

size_t	ft_sizelines(t_tmp *tmp)
{
	if (tmp->ln != NULL)
		return (ft_strlen(tmp->ln));
	return (0);
}

void ft_free(char **premap)
{
	int	i;

	i = 0;
	while (premap[i] != NULL)
	{
		free(premap[i]);
		i++;
	}
	free(premap);
	premap = NULL;
}
	
void	ft_premap(char *map, t_tmp *tmp)
{
	size_t	size;
	int		j;

	tmp->fd = open(map, O_RDONLY);
	tmp->premap = (char **)malloc((tmp->y + 1) * sizeof(char *));
	j = 0;
	while (j < (tmp->y))
	{
		tmp->ln = get_next_line(tmp->fd);
		if (tmp->ln == NULL)
			break ;
		if ((tmp->ln[0] == '\n') || (tmp->ln && ft_isspace(tmp->ln)))
		{
			free(tmp->ln);
			continue ;
		}
		size = ft_sizelines(tmp);
		tmp->premap[j] = ft_strdup(tmp->ln);
		j++;
		free(tmp->ln);
	}
	tmp->premap[j] = NULL;
	ft_print_premap(tmp);
	close(tmp->fd);
}

int	main(int argc, char **argv)
{
	t_tmp	tmp;

	tmp.y = 0;
	tmp.x = 0;
	tmp.pos = 0;
	tmp.ln = " ";
	tmp.fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		ft_print_error(1);
	if (!ft_check_extension(argv[1]))
		return (0);
	else
		ft_get_y(&tmp);
	ft_premap(argv[1], &tmp);
	ft_free(tmp.premap);
	return (1);
}
