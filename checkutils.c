/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:28:12 by ingonzal          #+#    #+#             */
/*   Updated: 2022/08/15 21:18:02 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include <stdio.h>

int	ft_isstrprint(t_tmp *tmp)
{
	int	i;

	i = 0;
	while (tmp->ln[i])
	{
		if (ft_isprint(tmp->ln[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_isstrspace(t_tmp *tmp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tmp->ln[i])
	{
		if (tmp->ln[i] == ' ' || tmp->ln[i] == '\t')
			j++;
		i++;
	}
	if ((i - 1) == j && j != 0)
		return (1);
	return (0);
}
	/* printf("I >>>>>>>>>> %d\n", i); */
	/* printf("J >>>>>>>>>> %d\n", j); */

int	ft_isspace(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			j++;
		i++;
	}
	i -= 1;
	if (i == j && j != 0)
		return (1);
	return (0);
}
	/* printf("I >>>>>>>>>> %d\n", i); */
	/* printf("J >>>>>>>>>> %d\n", j); */

void	ft_lchar(char *line, t_tmp *tmp)
{
	if (line[ft_strlen(line) - 2] != '1' && line[ft_strlen(line) - 2] != ' ')
		ft_print_error(5, tmp);
}
	/* printf("I >>>>>>>>>> %d\n", i); */
	/* printf("ln[i]>>>>>>>>>> %c\n", ln[i]); */
	/* printf("AQUI\n"); */

int	ft_check_fchars(t_tmp *tmp)
{
	int			i;
	int			j;
	char		*set;
	static int	order;

	i = 0;
	set = "NSEWFC1";
	while (tmp->ln[i] == ' ')
		i++;
	j = 0;
	while (set[j])
	{
		if (tmp->ln[i] == '0' || tmp->ln[i] == '1')
			order = 1;
		if (set[j] == tmp->ln[i] || tmp->ln[i] == '\n')
			break ;
		j++;
	}
	tmp->pos = order;
	if (j >= 7 || (tmp->y <= 6 && tmp->pos != 0))
		ft_print_error(2, tmp);
	if (order == 1)
		ft_lchar(tmp->ln, tmp);
	return (1);
}
