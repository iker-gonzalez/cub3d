/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 20:13:25 by ikgonzal          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/30 10:03:29 by ikgonzal         ###   ########.fr       */
=======
/*   Updated: 2022/08/16 19:53:46 by ingonzal         ###   ########.fr       */
>>>>>>> ingonzal
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buff[11];
	int			bytes_read;
	static char	*rest;
	char		*line;

	if (fd < 0)
		return (NULL);
	bytes_read = 1;
	while (!check_line_break(rest) && bytes_read != 0)
	{
		bytes_read = read(fd, buff, 10);
		if (bytes_read == -1)
			return (NULL);
		buff[bytes_read] = '\0';
		rest = ft_strjoin_gnl(rest, buff);
	}
<<<<<<< HEAD
	line = ft_substr_gnl(rest, 0, ft_strlen_gnl(rest, '\n') + 1);
	rest = ft_substr2_gnl(rest, ft_strlen_gnl(line, '\0'),
			ft_strlen_gnl(rest, '\0') - ft_strlen_gnl(line, '\0'));
	if (bytes_read == 0 && ft_strlen_gnl(line, '\0') == 0)
=======
	line = ft_substr(rest, 0, ft_strgnlen(rest, '\n') + 1);
	rest = ft_substr2(rest, ft_strgnlen(line, '\0'),
			ft_strgnlen(rest, '\0') - ft_strgnlen(line, '\0'));
	if (bytes_read == 0 && ft_strgnlen(line, '\0') == 0)
>>>>>>> ingonzal
	{
		free(line);
		return (NULL);
	}
	return (line);
}
