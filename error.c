/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:06:42 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/04 16:56:55 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_extension(char *file)
{
	int i;
	char *extension;

	i = 0;
	while (file[i] != '.')
		i++;
	extension = ft_substr(file, i + 1, ft_strlen(file));
	if (ft_strncmp(extension, "cub", 3) != 0)
	{
		printf("Error: invalid map extension\n");
		return (1);
	}
	return(0);
	
}