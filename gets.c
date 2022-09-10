/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:58:06 by ingonzal          #+#    #+#             */
/*   Updated: 2022/09/10 20:08:56 by ingonzal         ###   ########.fr       */
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

void	ft_get_y(t_tmp *tmp)
{
	int	i;

	i = 0;
	if (!tmp->fd || tmp->fd != -1)
	{
		while (tmp->ln)
		{
			tmp->ln = get_next_line(tmp->fd);
			ft_get_x(tmp);
			if (tmp->ln == NULL || !ft_check_fchars(tmp))
				break ;
			if ((tmp->ln[0] != '\n') && (!ft_isspace(tmp->ln)))
				tmp->y++;
			if (tmp->ln[0] == '\n' && tmp->pos != 0)
				i = 1;
			if ((i && tmp->ln[0] != '\n') || (tmp->pos && ft_isspace(tmp->ln)))
				tmp->err = 3;
			free(tmp->ln);
		}
		if (tmp->err != 0)
			ft_print_error(tmp->err, tmp);
	}
	else
		printf("Error:\nFile\n");
	close(tmp->fd);
}
