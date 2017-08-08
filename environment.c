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

t_points		**take_in_pts(t_data *data, t_map *map)
{
	t_points	**p;

	if (!(p = (t_points **)malloc(sizeof(t_points *) * (map->h + 1))))
		return (NULL);
	map->mid_x = map->w / 2;
	map->mid_y = map->h / 2;
	while (data->y < map->h)
	{
		p[data->y] = (t_points *)malloc(sizeof(t_points) * (map->w + 1));
		data->x = 0;
		while (data->x < map->w)
		{
			p[data->y][data->x].x = ((data->x - map->mid_x) * (data->gap));
			p[data->y][data->x].y = ((data->x - map->mid_y) * (data->gap));
			p[data->y][data->x].z = map->map[data->y][data->x];
			data->x++;
		}
		data->y++;
	}
	p[data->y] = NULL;
	return (p);
}

void		my_data(t_data **data, t_map *map)
{
	(*data)->x1 = 0;
	(*data)->y1 = 0;
	(*data)->x2 = 0;
	(*data)->y2 = 0;
	(*data)->h_max = map->h_max;
	(*data)->h_min = 0;
	(*data)->w = map->w;
	(*data)->h = map->h;
	(*data)->gap = map->w > map->h ? 750 / (map->w) : 750 / (map->h);
	/* if w > h
			gap = 750 / w;
		else
			gap = 750 / h;
	*/
	(*data)->x = 0;
	(*data)->y = 0;
	(*data)->cart = take_in_pts(*data, map);
	(*data)->mlx = mlx_init();
	(*data)->win = mlx_new_window((*data)->mlx, WIDTH, HEIGHT, "fdf");
}

t_data		*get_info(t_map *map)
{
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data));
	my_data(&data, map);
	return (data);
}
