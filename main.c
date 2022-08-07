/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/07 19:58:23 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_get_y(t_tmp *tmp)
{
	int	i;

	i = 0;
	tmp->y = 0;
	tmp->pos = 0;
	if (!tmp->fd || tmp->fd != -1)
	{
		tmp->ln = " ";
		while (tmp->ln != NULL)
		{
			tmp->ln = get_next_line(tmp->fd);
			if (tmp->ln == NULL || !ft_check_fchars(tmp))
				break ;
			if ((tmp->ln[0] != '\n') || (!ft_isspace(tmp->ln)))
				tmp->y++;
			if (tmp->ln[0] == '\n' && tmp->pos != 0)
				i = 1;
			if ((i && tmp->ln[0] != '\n') || (tmp->pos && ft_isspace(tmp->ln)))
				ft_print_error(3);
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

void	ft_premap(char *map, t_tmp *tmp)
{
	size_t	size;
	size_t	i;
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
			continue ;
		size = ft_sizelines(tmp);
		tmp->premap[j] = (char *)malloc((size + 1) * sizeof(char));
		i = -1;
		while (++i < size)
			tmp->premap[j][i] = tmp->ln[i];
		tmp->premap[j][i] = '\0';
		j++;
	}
	tmp->premap[j] = NULL;
	free(tmp->ln);
	close(tmp->fd);
}
	/* ft_print_premap(tmp); */

int	main(int argc, char **argv)
{
	t_tmp	tmp;

	tmp.fd = open(argv[1], O_RDONLY);
	if (argc != 2)
		ft_print_error(1);
	if (!ft_check_extension(argv[1]))
		return (0);
	else
		ft_get_y(&tmp);
	ft_premap(argv[1], &tmp);
	return (1);
}
