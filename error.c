/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:06:42 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/31 19:25:39 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_extension(char *file)
{
	int i;
	int j;
	char *extension;

	i = ft_strlen(file);
	j = 4;
	while (j != 0)
	{
		i--;
		j--;
	}
	extension = ft_substr(file, i  , ft_strlen(file));
	if (ft_strncmp(extension, ".cub", 4) != 0)
	{
		printf("Error: invalid map extension\n");
		return (0);
	}
	return(1);
	
}
