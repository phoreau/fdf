/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:06:45 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/18 16:43:30 by phoreau          ###   ########.fr       */
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

int		main(int ac, char **av)
{
	t_data		*coords;
	t_map		*map;

	if (ac != 2)
		error(0);
	// parse
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		error(0);
	storing(av[1], map);
	coords = get_info(map);
	start(coords);
	return (0);
}
