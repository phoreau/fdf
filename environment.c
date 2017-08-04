/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:35:03 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/14 16:10:28 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	my_data(t_data **data, t_map *map)
{
	(*data)->x1 = 0;
	(*data)->y1 = 0;
	(*data)->x2 = 0;
	(*data)->y2 = 0;
	(*data)->height_max = map->height_max;
	(*data)->height_min = 0;
	(*data)->width = map->width;
	(*data)->height = map->height;
	(*data)->i = 0;
	(*data)->j = 0;
	(*data)->mlx = mlx_init();
	(*data)->win = mlx_new_window((*data)->mlx, WIDTH, HEIGHT, "fdf");
}

t_data	*get_info(t_map *map)
{
	t_data		*data;

	data = (t_data*)malloc(sizeof(t_data));
	my_data(&data, map);
	return (data);
}
