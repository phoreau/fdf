/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:38:48 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/18 16:38:51 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		change_pos_neg(int sign)
{
    if (sign > 0)
    	sign = 1;
    if (sign < 0)
    	sign = -1;
    return (sign);
}

void	vertical_line(t_data *env, int x1, int y1, int x2, int y2)
{
	int		y;

	y = y1;
	while (y < y2)
	{
		mlx_pixel_put(env->mlx, env->win, x1, y, 0x10FF0000);
		y++;
	}
}

void	line_negative(t_data *env, int x1, int y1, int x2, int y2)
{
	int		dx = abs(x2 - x1);
	int		dy = abs(y2 - y1);
	int		d = 2 * dy - dx;
	int		twoDy = 2 * dy;
	int		twoDyMinusDx = 2 * (dy - dx);
	int		x, y;
	int		sign;

	if (x1 > x2)
	{
		x = x2;
		y = y2;
		x2 = x1;
	}
	else
	{
		x = x1;
		y = y1;
	}
	mlx_pixel_put(env->mlx, env->win, x, y, 0x00FF0000);
	while (x < x2)
	{
		sign = change_pos_neg(twoDyMinusDx);
		x++;
		if (d < 0)
			d += twoDy;
		else
		{
			y += sign;
			d += twoDyMinusDx;
		}
		mlx_pixel_put(env->mlx, env->win, x, y, 0x00FF0000);
	}
}

void	line_positive(t_data *env, int x1, int y1, int x2, int y2)
{
	int		dx = abs(x2 - x1);
	int		dy = abs(y2 - y1);
	int		d = 2 * dy - dx;
	int		twoDy = 2 * dy;
	int		twoDyMinusDx = 2 * (dy - dx);
	int		x, y;
	int		sign;

	if (x1 > x2)
	{
		x = x2;
		y = y2;
		x2 = x1;
	}
	else
	{
		x = x1;
		y = y1;
	}
	mlx_pixel_put(env->mlx, env->win, x, y, 0x00FF0000);
	while (x < x2)
	{
		sign = change_pos_neg(twoDy);
		// printf("%d\n", sign);
		x++;
		if (d < 0)
			d += twoDy;
		else
		{
			y += sign;
			d += twoDyMinusDx;
		}	
		mlx_pixel_put(env->mlx, env->win, x, y, 0x00FF0000);
	}
}
