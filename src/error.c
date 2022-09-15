/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:06:42 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/15 20:01:27 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>

void	ft_free_int(int **array)
{
	int	i;
	int	*tmp;

	i = 0;
	while (i < 3)
	{
		tmp = &array[i][0];
		free(tmp);
		i++;
	}
	free(array);
	array = NULL;
}	

void	ft_free(char **premap)
{
	int	i;

	i = 0;
	while (premap[i])
	{
		free(premap[i]);
		i++;
	}
	free(premap);
	premap = NULL;
}	

void	ft_free_texture(t_player *p)
{
	if (p->tmp->no_path != NULL)
		free(p->tmp->no_path);
	if (p->tmp->so_path != NULL)
		free(p->tmp->so_path);
	if (p->tmp->ea_path != NULL)
		free(p->tmp->ea_path);
	if (p->tmp->we_path != NULL)
		free(p->tmp->we_path);
}

void	ft_free_errors(t_player *p)
{
	if (p->tmp->ln != NULL)
		free(p->tmp->ln);
	if (p->tmp->premap != NULL)
		ft_free(p->tmp->premap);
	if (p->tmp->map != NULL)
		ft_free(p->tmp->map);
}

void	ft_free_int_errors(t_player *p)
{
	if (p->tmp->f_int != NULL)
		ft_free_int(p->tmp->f_int);
	if (p->tmp->c_int != NULL)
		ft_free_int(p->tmp->c_int);
}
