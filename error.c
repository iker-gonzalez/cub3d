/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:06:42 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/22 20:33:25 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
/* #include <stdio.h> */

int	ft_check_extension(char *file)
{
	int		i;
	int		j;
	char	*ext;

	i = ft_strlen(file);
	j = 4;
	while (j != 0)
	{
		i--;
		j--;
	}
	ext = ft_substr(file, i, ft_strlen(file));
	if (ft_strncmp(ext, ".cub", 4) != 0)
	{
		printf("Error: invalid map extension\n");
		free(ext);
		return (0);
	}
	free(ext);
	return (1);
}

int	ft_print_error(int errno, t_tmp *tmp)
{
	if (errno == 1)
	{
		printf("Error:\nWrong number of arguments\n");
		exit (1);
	}
	if (errno == 2)
		printf("Error:\nNot Allowed Line First Char or Map Position\n");
	if (errno == 3)
		printf("Error:\nWrong newline or Char position\n");
	if (errno == 4)
		printf("Error:\nNot Allowed Char Map\n");
	if (errno == 5)
		printf("Error:\nMap not properly closed\n");
	if (errno == 6)
		printf("Error:\nWrong number of players\n");
	if (errno == 7)
		printf("Error:\nBad formatted headers\n");
	if (tmp->ln)
		free(tmp->ln);
	if (tmp->premap)
		ft_free(tmp->premap);
	if (tmp->map)
		ft_free(tmp->map);
	exit (1);
}
		/* printf("FREE:\nPREMAP\n"); */
		/* printf("FREE:\nMAP\n"); */
