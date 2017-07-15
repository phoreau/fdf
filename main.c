/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:06:45 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/14 17:25:26 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	error(int x)
{
	if (x == 0)
	{
		ft_putstr("non\n");
		exit(1);
	}
	if (x == 1)
		exit(1);
}

int		key_hook(int keycode, t_env *e)
{
	ft_putstr("Keyevent: ");
	ft_putendl(ft_itoa(keycode));
	if (keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;
	t_map	*in_map;

	if (ac != 2)
		error(0);
	if (!(in_map = (t_map *)malloc(sizeof(t_map))))
		error(0);
	parse(av[1]);
	storing(av[1], in_map);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 600, 600, "FDF");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
