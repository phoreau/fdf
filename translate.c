/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:06:45 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/18 16:43:30 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void			translate(t_data **info)
{
	int			i;
	int			j;
	float		x;
	float		y;

	i = 0;
	while (i < (*info)->h)
	{
		j = 0;
		while (j < (*info)->w)
		{
			x = (*info)->cart[i][j].x;
			y = (*info)->cart[i][j].y;
			(*info)->cart[i][j].x = (x + ((*info)->max / 2));
			(*info)->cart[i][j].y = (y + ((*info)->smax / 2));
			j++;
		}
		i++;
	}
}
