/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/22 19:42:18 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"

void	ft_free(char **premap)
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
		if (tmp->max_x < ft_strlen(tmp->ln))
			tmp->max_x = ft_strlen(tmp->ln);
		tmp->premap[j] = ft_strdup(tmp->ln);
		j++;
		free(tmp->ln);
		printf("J ------ %d\n", j);
	}
	tmp->premap[j] = NULL;
	ft_extract_map(tmp);
	close(tmp->fd);
}
	/* ft_print_premap(tmp); */
		/* ft_sizelines(tmp); */

void	ft_init_tmp(t_tmp *tmp)
{
	tmp->premap = NULL;
	tmp->map = NULL;
	tmp->y = 0;
	tmp->x = 0;
	tmp->max_x = 0;
	tmp->map_y = 0;
	tmp->pos = 0;
	tmp->ln = " ";
}

int	main(int argc, char **argv)
{
	t_tmp	tmp;

	ft_init_tmp(&tmp);
	tmp.fd = open(argv[1], O_RDONLY);
	if (argc != 2 || tmp.fd == -1)
		ft_print_error(1, &tmp);
	if (!ft_check_extension(argv[1]))
		return (0);
	else
		ft_get_y(&tmp);
	ft_premap(argv[1], &tmp);
	ft_headers(&tmp);
	ft_print_map(tmp.premap);
	if (tmp.premap != NULL)
		ft_free(tmp.premap);
	if (tmp.map != NULL)
		ft_free(tmp.map);
	return (1);
}
	/* printf("MAX---%zu\n", tmp.max_x); */
