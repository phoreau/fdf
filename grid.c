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

// void	draw_grid(t_data *info, t_map *map)
// {
// 	info->y = 0;
// 	while (info->y <= HEIGHT - 150)
// 	{
// 		info->x = 0;
// 		while (info->x <= WIDTH - 150)
// 		{
// 			line_negative(info, info->x, info->y, info->x + 50, info->y);
// 			vertical_line(info, info->x, info->y, info->x, info->y + 50);
// 			info->x += 50;
// 		}
// 		info->y += 50;
// 	}
// }
