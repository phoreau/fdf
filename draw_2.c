/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:06:45 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/18 16:43:30 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	set_bres_values(t_data *info, t_values *values)
{
	info->slope = info->rise / info->run;
	values->adjust = info->slope >= 0 ? 1 : -1;
	values->threshold = 0.5;
	values->offset = 0;
}

void	set_values(t_data **info, int i, int j)
{
	(*info)->x1 = round((*info)->cart[i][j].x);
	(*info)->y1 = round((*info)->cart[i][j].y);
	(*info)->cur_z = (*info)->cart[i][j].z;
	if ((j + 1) < (*info)->w)
	{
		(*info)->x2 = round((*info)->cart[i][j + 1].x);
		(*info)->y2 = round((*info)->cart[i][j + 1].y);
		(*info)->next_z = (*info)->cart[i][j + 1].z;
	}
	else if ((i + 1) < (*info)->h)
	{
		(*info)->x2 = round((*info)->cart[i + 1][j].x);
		(*info)->y2 = round((*info)->cart[i + 1][j].y);
		(*info)->next_z = (*info)->cart[i + 1][j].z;
	}
	(*info)->rise = ((*info)->y2) - ((*info)->y1);
	(*info)->run = ((*info)->x2) - ((*info)->x1);
}

void	draw_right(t_data *info, t_values **values)
{
	info->i = 0;
	while (info->i < info->h)
	{
		info->j = 0;
		while (info->j < info->w)
		{
			set_values(&info, info->i, info->j);
			if (info->run == 0)
				slope_straight(info);
			else
			{
				set_bres_values(info, *values);
				if (info->slope <= 1 && info->slope >= -1)
					slope_gradual(info, *values);
				else
					slope_sharp(info, *values);
			}
			info->j++;
		}
		info->i++;
	}
}

void	draw_down(t_data *info, t_values **values)
{
	info->i = 0;
	while (info->i < info->h)
	{
		info->j = 0;
		while (info->j < info->w)
		{
			set_values(&info, info->i, info->j);
			if (info->run == 0)
				slope_straight(info);
			else
			{
				set_bres_values(info, *values);
				if (info->slope <= 1 && info->slope >= -1)
					slope_gradual(info, *values);
				else
					slope_sharp(info, *values);
			}
			info->j++;
		}
		info->i++;
	}
}

void	draw(t_data *info)
{
	t_values	*values;

	values = (t_values *)malloc(sizeof(t_values));
	// rotate(info);
	// translate(&info);
	draw_right(info, &values);
	draw_down(info, &values);
}
