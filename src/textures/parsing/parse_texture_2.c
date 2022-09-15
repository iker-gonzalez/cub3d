/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:43:27 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/09/15 20:10:51 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include "../../../libft/libft.h"
#include <stdlib.h>

void	ft_extract_colors_nb(char *line, t_text *text, int end)
{
	int		start;
	char	*nb;

	start = end + 1;
	while (!ft_isdigit((int)line[start]))
		start++;
	end = start;
	while (line[end] != ' ')
		end++;
	nb = ft_substr(line, start, end);
	text->nb_colors = ft_atoi(nb);
	free(nb);
}

void	ft_skip_to_color_nb(char *line, t_text *text)
{
	int	start;
	int	end;

	start = 0;
	while (!ft_isdigit((int)line[start]))
		start++;
	end = start;
	while (line[end] != ' ')
		end++;
	start = end + 1;
	while (!ft_isdigit((int)line[start]))
		start++;
	end = start;
	while (line[end] != ' ')
		end++;
	ft_extract_colors_nb(line, text, end);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

u_int32_t	hex2int(char *hex)
{
	u_int32_t	val;
	int			i;

	val = 0;
	i = 0;
	while (hex[i] != '\0')
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			hex[i] = hex[i] - '0';
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			hex[i] = hex[i] - 'a' + 10;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			hex[i] = hex[i] - 'A' + 10;
		val = (val << 4) | (hex[i] & 0xF);
		i++;
	}
	return (val);
}

int	ft_hex_to_int(char *color)
{
	int		i;
	char	*hex;
	int		hex_int;

	i = 0;
	while ((color[i] != '#' && i < 5) || (color[i] == '#' && i == 1))
		i++;
	i++;
	hex = ft_substr(color, i, 6);
	hex_int = hex2int(hex);
	free(hex);
	return (hex_int);
}
