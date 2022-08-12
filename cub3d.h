/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:07:00 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/12 20:17:46 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define NO_TEXTURE 0
# define EA_TEXTURE 1
# define SO_TEXTURE 2
# define WE_TEXTURE 3

# include <stdlib.h>

typedef struct s_tmp{
	int		y;
	size_t	x;
	size_t	max_x;
	int		fd;
	int		pos;
	int		spaces;
	char	*ln;
	char	**premap;
	char	**map;
}	t_tmp;

typedef struct s_map {
	char	*no_texture;
	char	*ea_texture;
	char	*so_texture;
	char	*we_texture;
	char	*f_color;
	char	*c_color;
	int		columns;
	int		rows;
	char	**map_content;
}	t_map;

void	ft_get_x(t_tmp *tmp);
void	ft_get_y(t_tmp *tmp);
int		ft_isstrprint(t_tmp *tmp);
int		ft_isstrspace(t_tmp *tmp);
int		ft_check_fchars(t_tmp *tmp);
/* void	ft_print_premap(t_tmp *tmp); */
void	ft_print_map(char **map);
/* void	ft_print_map(t_tmp *tmp); */
void	ft_extract_map(t_tmp *tmp);
int		ft_fchar(char *line);
int		ft_isspace(char *line);
int		ft_check_extension(char *file);
int		ft_print_error(int errno);

#endif
