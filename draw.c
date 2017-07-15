/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:03:42 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/14 18:27:33 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"



void	ft_draw(t_env *fdf)
{
	int			y;
	int			x;
	t_points	**points;
	t_env		env;
	t_info		info;

	points = env.points;
	y = 0;
	while (y < info.numlines - 2)
	{
		x = 0;
		while (x < info.numcols - 1)
		{
			draw_bres_line(points[y][x], points[y][x + 1], info);
			draw_bres_line(points[y][x], points[y + 1][x], info);
			x++;
		}
		draw_bres_line(points[y][x], points[y + 1][x], info);
		y++;
	}
	x = 0;
	while (x < info.numcols - 1)
	{
		draw_bres_line(points[y][x], points[y][x + 1], info);
		x++;
	}
}