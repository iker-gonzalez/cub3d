/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:55:38 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/15 20:17:07 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>

size_t	ft_strlen_gnl(char *str, int c);
char	*get_next_line(int fd);
int		check_line_break(char *buff);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t end);
char	*ft_substr2_gnl(char *s, unsigned int start, size_t end);
void	zero_bytes_read(int bytes_read, char *line);

#endif
