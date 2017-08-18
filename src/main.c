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

#include "../includes/fdf.h"

void	error_msg(char *str)
{
	ft_putendl(str);
	exit(1);
}

int		main(int ac, char **av)
{
	t_data		coords;
	t_map		*map;
	int			fd;

	if (ac != 2)
		error_msg("Error: Wrong argument number");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		error_msg("Error: Failed to open.\n");
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		error_msg("Error: Malloc");
	ft_parse(av[1]);
	storing(av[1], map);
	coords = *get_info(map);
	start(&coords);
	return (0);
}
