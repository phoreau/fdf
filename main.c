/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:06:45 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/12 15:02:32 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		error(char *str)
{
	ft_putendl(str);
	exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_map	*in_map;

	if (ac != 2)
	{
		error("Error: Wrong arguments number");
		return (0);
	}

	// just testing stuff
	// linebres_negative(0, 100, 100, 0);
	// linebres_positive(0, 100, 100, 0);

	if (!(in_map = (t_map *)malloc(sizeof(t_map))))
		error("Error: Malloc");
	parse(av[1]);
	storing(av[1], in_map);
	return (0);
}