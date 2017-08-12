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
** ROTATION Z:
** .7854 radians = 45˚ degrees
*/

void rotate_z(t_data **d)
{
	float	x;
	float	y;
	int		i;
	int		j;

	j = 0;
	while (j < (*d)->h)
	{
		i = 0;
		while (i < (*d)->w)
		{
			x = (*d)->cart[j][i].x;
			y = (*d)->cart[j][i].y;
			(*d)->cart[j][i].x = (x * cos(0.7854) - y * sin(0.7854));
			(*d)->cart[j][i].y = (x * sin(0.7854) + y * cos(0.7854));
			i++;
		}
		j++;
	}
}

/*
** ROTATION Y:
** .0524 radians = 3˚ degrees
*/

void rotate_y(t_data **d)
{
	float	x;
	float	z;
	int		i;
	int		j;

	j = 0;
	while (j < (*d)->h)
	{
		i = 0;
		while (i < (*d)->w)
		{
			x = (*d)->cart[j][i].x;
			z = (*d)->cart[j][i].z;
			(*d)->cart[j][i].y = (x * cos(0.6982) - z * sin(0.6982));
			(*d)->cart[j][i].z = (x * sin(0.6982) + z * cos(0.6982));
			i++;
		}
		j++;
	}
}

/*
** ROTATION X:
** .6982 radians = 40˚ degrees
*/

void rotate_x(t_data **d)
{
	float	y;
	float	z;
	int		i;
	int		j;

	j = 0;
	while (j < (*d)->h)
	{
		i = 0;
		while (i < (*d)->w)
		{
			y = (*d)->cart[j][i].y;
			z = (*d)->cart[j][i].z;
			(*d)->cart[j][i].y = (y * cos(0.6982) - z * sin(0.6982));
			(*d)->cart[j][i].z = (y * sin(0.6982) + z * cos(0.6982));
			i++;
		}
		j++;
	}
}

void	rotate(t_data *info)
{
	rotate_z(&info);
	rotate_x(&info);
	rotate_y(&info);
}
