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

#include "./includes/fdf.h"

int		keyboard(int keycode)
{
	ft_putstr("Keyevent: ");
	ft_putendl(ft_itoa(keycode));
	if (keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}

int		start(t_data *info)
{
	draw(info);
	mlx_key_hook(info->win, keyboard, 0);
	mlx_loop(info->mlx);
	return (0);
}
