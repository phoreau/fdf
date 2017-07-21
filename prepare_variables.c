/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_variables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 15:24:39 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/14 18:19:10 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void			prep_variables(t_env **fdf, t_map *in_map)
{
	(*fdf)->x1 = 0;
	(*fdf)->y1 = 0;
	(*fdf)->x2 = 0;
	(*fdf)->y2 = 0;
	(*fdf)->hmax = in_map->height_max;
	(*fdf)->hmin = 0;
	(*fdf)->w = in_map->width;
	(*fdf)->h = in_map->height;
	(*fdf)->mlx = mlx_init();
	// (*fdf)->win = mlx_new_window((*fdf)->mlx, (*fdf)->max, (*fdf)->maxside, "FDF");
}

