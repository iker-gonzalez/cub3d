/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 19:07:06 by ingonzal          #+#    #+#             */
/*   Updated: 2022/08/21 20:53:57 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"

void	ft_get_x(t_tmp *tmp)
{
	if (tmp->ln != NULL)
	{
		if (tmp->x < ft_strlen(tmp->ln))
			tmp->x = ft_strlen(tmp->ln);
	}
}

		/* if (tmp->ln[tmp->x - 1] == '\n') */
		/* 	tmp->x = tmp->x - 1; */

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
				ft_print_error(3, tmp);
			free(tmp->ln);
		}
		printf("pos -> %d\n", tmp->y);
	}
	else
		printf("Error:\nFile\n");
	close(tmp->fd);
}
			/* printf("pos -> %d\n", tmp->pos); */
