/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:06:42 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/14 21:33:36 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include <stdio.h>

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

int	ft_print_error(int errno)
{
	if (errno == 1)
		printf("Error:\nWrong number of arguments\n");
	if (errno == 2)
		printf("Error:\nNot Allowed Line First Char or Map Position\n");
	if (errno == 3)
		printf("Error:\nWrong newline or Char position\n");
	if (errno == 4)
		printf("Error:\nNot Allowed Char Map\n");
	if (errno == 5)
		printf("Error:\nMap not properly closed\n");
	exit (1);
}
