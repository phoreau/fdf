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
	int			i;
	int			j;
	t_points	**p;

	map->mid_x = map->w / 2;
	map->mid_y = map->h / 2;
	if (!(p = (t_points **)malloc(sizeof(t_points *) * (map->h + 1))))
		return (NULL);
	i = 0;
	while (i < map->h)
	{
		j = 0;
		p[i] = (t_points *)malloc(sizeof(t_points) * (map->w + 1));
		while (j < map->w)
		{
			p[i][j].x = (j - map->mid_x) * (data->gap);
			p[i][j].y = (i - map->mid_y) * (data->gap);
			p[i][j].z = map->map[i][j] * 6;
			j++;
		}
		i++;
	}
	p[i] = NULL;
	return (p);
}

void			my_data(t_data **data, t_map *map)
{
	(*data)->x1 = 0;
	(*data)->y1 = 0;
	(*data)->x2 = 0;
	(*data)->y2 = 0;
	(*data)->h_max = map->h_max;
	(*data)->h_min = 0;
	(*data)->w = map->w;
	(*data)->h = map->h;
	(*data)->fix_right = 0;
	(*data)->gap = map->w > map->h ? 700 / map->w : 700 / (map->h);
	(*data)->big = map->w > map->h ? map->w : map->h;
	(*data)->slope = 0;
	(*data)->rise = 0;
	(*data)->run = 0;
	(*data)->i = 0;
	(*data)->j = 0;
	(*data)->max = 700 + (*data)->gap * (*data)->big;
	(*data)->smax = (*data)->max - 450;
	(*data)->cart = take_in_pts(*data, map);
	(*data)->mlx = mlx_init();
	(*data)->win = mlx_new_window((*data)->mlx,
		(*data)->max, (*data)->smax, "fdf");
}

t_data			*get_info(t_map *map)
{
	t_data		*data;

	data = (t_data *)malloc(sizeof(t_data));
	my_data(&data, map);
	return (data);
}
