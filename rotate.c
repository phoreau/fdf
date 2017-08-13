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

/*
** ROTATION X: 0.6982 radians = 40˚ degrees
*/

void	rotate_x(t_data **info)
{
	float	y;
	float	z;
	int		i;
	int		j;

	i = 0;
	while (i < (*info)->h)
	{
		j = 0;
		while (j < (*info)->w)
		{
			y = (*info)->cart[i][j].y;
			z = (*info)->cart[i][j].z;
			(*info)->cart[i][j].y = (y * cos(-0.6982) - z * sin(0.6982));
			(*info)->cart[i][j].z = (y * sin(-0.6982) + z * cos(0.6982));
			j++;
		}
		i++;
	}
}

/*
** ROTATION Y: 0.0524 radians = 3˚ degrees
*/

void	rotate_y(t_data **info)
{
	float	x;
	float	z;
	int		i;
	int		j;

	i = 0;
	while (i < (*info)->h)
	{
		j = 0;
		while (j < (*info)->w)
		{
			x = (*info)->cart[i][j].x;
			z = (*info)->cart[i][j].z;
			(*info)->cart[i][j].x = (x * cos(0.0524) + z * sin(0.0524));
			(*info)->cart[i][j].z = -(x * sin(0.0524)) + z * cos(0.0524);
			j++;
		}
		i++;
	}
}

/*
** ROTATION Z: 0.7854 radians = 45˚ degrees
*/

void	rotate_z(t_data **info)
{
	float	x;
	float	y;
	int		i;
	int		j;

	i = 0;
	while (i < (*info)->h)
	{
		j = 0;
		while (j < (*info)->w)
		{
			x = (*info)->cart[i][j].x;
			y = (*info)->cart[i][j].y;
			(*info)->cart[i][j].x = (x * cos(0.7854) - y * sin(0.7854));
			(*info)->cart[i][j].y = (x * sin(0.7854) + y * cos(0.7854));
			j++;
		}
		i++;
	}
}

void	rotate(t_data *info)
{
	rotate_z(&info);
	rotate_y(&info);
	rotate_x(&info);
}
