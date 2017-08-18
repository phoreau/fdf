/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:06:45 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/18 16:43:30 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			decrease_z(t_data **info)
{
	int			i;
	int			j;

	i = 0;
	while (i < (*info)->h)
	{
		j = 0;
		while (j < (*info)->w)
		{
			if ((*info)->cart[i][j].z > 0)
			{
				(*info)->cart[i][j].x += ((*info)->cart[i][j].z * -1.2);
				(*info)->cart[i][j].y += ((*info)->cart[i][j].z * 3);
			}
			j++;
		}
		i++;
	}
	mlx_clear_window((*info)->mlx, (*info)->win);
	draw(*info);
}

void			increase_z(t_data **info)
{
	int			i;
	int			j;

	i = 0;

	while (i < (*info)->h)
	{
		j = 0;
		while (j < (*info)->w)
		{
			if ((*info)->z > 0)
			{
				(*info)->cart[i][j].x += ((*info)->cart[i][j].z * 1.2);
				(*info)->cart[i][j].y += ((*info)->cart[i][j].z * -3);
			}
			j++;
		}
		i++;
	}
	mlx_clear_window((*info)->mlx, (*info)->win);
	draw(*info);
}
