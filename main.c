/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:06:45 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/09 22:16:09 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



int		main()
{
	void	*mlx;
	void	*win;
	int		x1;
	int		x2;
	// int		y1;
	// int		y2;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "hey mamzelle");
	x1 = 150;
	x2 = 350;

	while (x1 < x2)
	{
		mlx_pixel_put(mlx, win, x1, x2, 0x00FF0000);
		x1++;
	}

	// while (x1 < x2)
	// {
	// 	y1 = 75;
	// 	y2 = 50;
	// 	while (y2 < y1)
	// 	{
	// 		mlx_pixel_put(mlx, win, x1, y2, 0x00FF0000);
	// 		y2++;
	// 	}
	// 	x1++;
	// }
	mlx_loop(mlx);
	return (0);
}