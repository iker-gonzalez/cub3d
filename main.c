/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:01:08 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/07/21 21:15:18 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>

int ft_get_y(char *map)
{
	int 	y;
	int  	fd;
	char	*line;

	y = 0;
	fd = open(map, O_RDONLY);
	if (!fd || fd != -1)
	{
		line = " ";
		while (line != NULL)
		{
			printf("%s\n", line);
			line = get_next_line(fd);
			if (line == NULL)
				break;
			y++;
		}
	}
	else 
		printf("Error: File\n");
	close(fd);
	printf(">>>>>>>>>>%d\n", y);
	return (y);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error: incorrect number of arguments\n");
		return (1);
	}
	if (ft_check_extension(argv[1]))
		return (1);
	else
	{
		ft_get_y(argv[1]);
	}
	return (0);
}
