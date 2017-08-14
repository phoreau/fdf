/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:38:48 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/18 16:38:51 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

/*
** +-------------------------------------------------------------------------+
** |                                                                         |
** |                                             XXXXX                       |
** |                                       XXXXXX                            |
** |                                   X XX   |                              |
** |                               XXXX       |                              |
** |                          XXXXXX          | RISE                         |
** |                     XXXXX                |   = y2 - y1                  |
** |                 XXXX---------------------+                              |
** |             XXXX            RUN                                         |
** |          XXX                  = x2 - x1                                 |
** |                                                                         |
** +-------------------------------------------------------------------------+
** When slope is in decimals
** Slope = Rise / Run (regular)
** Re draw each pixel such as x increases by 1
** While y increases by the slope
*/

void		slope_gradual(t_data *info, t_values *values)
{
	float	y;

	values->delta = fabsf(info->slope);
	y = info->y1;
	if (info->x2 < info->x1)
	{
		values->tmp = info->x2;
		info->x2 = info->x1;
		info->x1 = values->tmp;
		y = info->y2;
	}
	values->tmp = info->x1;
	values->range = (info->x2 - values->tmp);
	while (info->x1 < info->x2)
	{
		mlx_pixel_put(info->mlx, info->win, info->x1, y, GOLD);
		values->offset += values->delta;
		if (values->offset >= values->threshold)
		{
			y += values->adjust;
			values->threshold += 1.0;
		}
		info->x1++;
	}
}

/*
** +-------------------------------------------------------------------------+
** |                                    X                                    |
** |                                  XXX                                    |
** |                                 XX +                                    |
** |                                XX  |                                    |
** |                               XX   | RISE                               |
** |                             XX     |   = x2 - x1                        |
** |                            XX      |                                    |
** |                          XXX+------+                                    |
** |                        XXX     RUN                                      |
** |                        X         = y2 - y1                              |
** +-------------------------------------------------------------------------+
** when slope > 1 and slope < -1
** Slope = to Run / Rise (flipped)
** We draw each pixel such as y increases by 1
** While x increases by the slope
*/

void		slope_sharp(t_data *info, t_values *values)
{
	float	x;

	values->delta = fabsf(info->run / info->rise);
	x = info->x1;
	if (info->y2 < info->y1)
	{
		values->tmp = info->y2;
		info->y2 = info->y1;
		info->y1 = values->tmp;
		x = info->x2;
	}
	values->tmp = info->y1;
	values->range = (info->y2 - values->tmp);
	while (info->y1 < info->y2)
	{
		mlx_pixel_put(info->mlx, info->win, x, info->y1, PURPLE);
		values->offset += values->delta;
		if (values->offset >= values->threshold)
		{
			x += values->adjust;
			values->threshold += 1.0;
		}
		info->y1++;
	}
}

void		slope_straight(t_data *info)
{
	float	tmp;

	if (info->y2 < info->y1)
	{
		tmp = info->y2;
		info->y2 = info->y1;
		info->y1 = tmp;
	}
	while (info->y1 <= info->y2)
	{
		mlx_pixel_put(info->mlx, info->win, info->x1, info->y1, SILVER);
		info->y1++;
	}
}
