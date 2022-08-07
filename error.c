/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:06:42 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/07 20:04:13 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
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
		return (0);
	}
	return (1);
}

int	ft_print_error(int errno)
{
	if (errno == 1)
		printf("Error:\nWrong number of arguments\n");
	if (errno == 2)
		printf("Error:\nNot Allowed Line First Char or Map Position\n");
	if (errno == 3)
		printf("Error:\nWrong newline or char position\n");
	exit (1);
}
