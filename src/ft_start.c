/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:06:45 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/18 16:43:30 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		keyboard(int keycode, t_data *info)
{
	ft_putstr("Keyevent: ");
	ft_putendl(ft_itoa(keycode));
	if (keycode == KEY_ESCAPE)
		exit(0);
	if (keycode == KEY_PLUS)
		increase_z(&info);
	if (keycode == KEY_MINUS)
		decrease_z(&info);
	return (0);
}

void	ft_print_settings(void)
{
	ft_putstr("\n\n      ################################################");
	ft_putstr("\n      #           WELCOLME TO WORLD OF FDF           #\n");
	ft_putstr("      ################################################\n\n");
	ft_putstr("              HERE'S HOW TO INTERACT WITH FDF:\n");
	ft_putstr("      ------------------------------------------------\n");
	ft_putstr("      |       KEY       |           ACTION           |\n");
	ft_putstr("      ------------------------------------------------\n");
	ft_putstr("      |      'esc'      |      exit the programm     |\n");
	ft_putstr("      ------------------------------------------------\n\n\n");
}

int		start(t_data *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, info->max, info->smax, "fdf");
	mlx_key_hook(info->win, keyboard, info);
	ft_print_settings();
	draw(info);
	mlx_loop(info->mlx);
	return (0);
}
