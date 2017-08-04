/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:06:45 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/18 16:43:30 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

// void	draw_grid(t_data *map)
// {
// 	int x = 50;
// 	int y = 50;

// 	while (y <= 400)
// 	{
// 		x = 50;
// 		while (x <= 400)
// 		{
// 			line_negative(map, x, y, x + 50, y);
// 			vertical_line(map, x, y, x, y + 50);
// 			x += 50;
// 		}
// 		y += 50;
// 	}
// }

void	draw_grid(t_data *info, t_map *map)
{
	while (info->y <= info->height)
	{
		info->x = 50;
		while (info->x <= info->width)
		{
			// line_negative(info, x, y, x + 50, y);
			line_negative(info, info->x, info->y, info->x + 50, info->y);
			vertical_line(info, info->x, info->y, info->x, info->y + 50);
			info->x += 50;
		}
		info->y += 50;
	}
}
