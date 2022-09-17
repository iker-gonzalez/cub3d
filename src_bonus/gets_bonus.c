/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:58:06 by ingonzal          #+#    #+#             */
/*   Updated: 2022/09/17 10:46:08 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"

void	ft_get_x(t_player *p)
{
	if (p->tmp->ln != NULL)
	{
		if (p->tmp->x < ft_strlen(p->tmp->ln))
			p->tmp->x = ft_strlen(p->tmp->ln);
	}
}

void	ft_get_y(t_player *p)
{
	while (p->tmp->ln)
	{
		p->tmp->ln = get_next_line(p->tmp->fd);
		ft_get_x(p);
		if (p->tmp->ln == NULL || !ft_check_fchars(p->tmp))
			break ;
		if ((p->tmp->ln[0] != '\n') && (!ft_isspace(p->tmp->ln)))
			p->tmp->y++;
		if ((p->tmp->ln[0] == '\n' && p->tmp->pos != 0)
			|| (p->tmp->pos && ft_isspace(p->tmp->ln)))
			p->tmp->err = 3;
		free(p->tmp->ln);
	}
	if (p->tmp->y < 8)
		p->tmp->err = 1;
	if (p->tmp->err != 0)
		ft_print_error(p->tmp->err, p);
	close(p->tmp->fd);
}

void	ft_free_last(char **line, t_player *p)
{
	ft_free(line);
	ft_print_error(7, p);
}
