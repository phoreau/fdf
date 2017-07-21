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

void linebres_negative(int x0, int y0, int x1, int y1)
{
	t_env	e;
	int		dx = abs(x1 - x0);
	int		dy = abs(y1 - y0);
	int		d = 2 * dy - dx;
	int		twoDy = 2 * dy;
	int		twoDyMinusDx = 2 * (dy - dx);
	int		x, y;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 500, 500, "hey mamzelle");

	if (x0 > x1)
	{
		x = x1;
		y = y1;
		x1 = x0;
	}
	else
	{
		x = x0;
		y = y0;
	}
	mlx_pixel_put(e.mlx, e.win, x, y, 0x00FF0000);
	while (x < x1)
	{
		x++;
		if (d < 0)
			d += twoDy;
		else
		{
			y++;
			d += twoDyMinusDx;
		}
		mlx_pixel_put(e.mlx, e.win, x, y, 0x00FF0000);
	}
	mlx_loop(e.mlx);
}

void linebres_positive(int x0, int y0, int x1, int y1)
{
	t_env	e;
	int		dx = abs(x1 - x0);
	int		dy = abs(y1 - y0);
	int		d = 2 * dy - dx;
	int		twoDy = 2 * dy;
	int		twoDyMinusDx = 2 * (dy - dx);
	int		x, y;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 500, 500, "hey mamzelle");

	if (x0 > x1)
	{
		x = x1;
		y = y1;
		x1 = x0;
	}
	else
	{
		x = x0;
		y = y0;
	}
	mlx_pixel_put(e.mlx, e.win, x, y, 0x00FF0000);
	while (x < x1)
	{
		x++;
		if (d < 0)
			d += twoDy;
		else
		{
			y++;
			d += twoDyMinusDx;
		}
		mlx_pixel_put(e.mlx, e.win, x, y, 0x00FF0000);
	}
	mlx_loop(e.mlx);
}

