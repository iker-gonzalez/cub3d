/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikgonzal <ikgonzal@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:22:10 by ikgonzal          #+#    #+#             */
/*   Updated: 2022/08/07 12:32:21 by ikgonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_draw(t_ray *ray, t_draw *draw)
{
	printf("VERTICAL X COORDINATE TO DRAW:\n\n");
	printf("line->height: %d\n", draw->lineHeight);
	printf("drawStart: %d\n", draw->drawStart);
	printf("drawEnd: %d\n", draw->drawEnd);
	printf("--------------------\n\n");
}

void	print_delta(t_ray *ray)
{
	
}