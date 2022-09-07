/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:06:42 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/06 21:12:57 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"

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

void	ft_free_texture(t_tmp *tmp)
{
	if (tmp->no_path != NULL)
		free(tmp->no_path);
	if (tmp->so_path != NULL)
		free(tmp->so_path);
	if (tmp->ea_path != NULL)
		free(tmp->ea_path);
	if (tmp->we_path != NULL)
		free(tmp->we_path);
}

void	ft_free_errors(t_tmp *tmp)
{
	if (tmp->ln != NULL)
		free(tmp->ln);
	if (tmp->premap != NULL)
		ft_free(tmp->premap);
	if (tmp->map != NULL)
		ft_free(tmp->map);
}

void	ft_free_int_errors(t_tmp *tmp)
{
	if (tmp->f_int != NULL)
		ft_free_int(tmp->f_int);
	if (tmp->c_int != NULL)
		ft_free_int(tmp->c_int);
}
