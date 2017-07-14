/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:35:03 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/14 11:53:03 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		*get_values(char **s, int width)
{
	int		*map;
	int		j;

	j = 0;
	map = (int *)malloc(sizeof(int) * (width + 1));
	while (j < width)
	{
		map[j] = ft_atoi(s[j]);
		printf("[%2d]", map[j]);
		j++;
	}
	printf("\n");
	return (map);
}

void	find_z_value(int fd, t_map *in_map)
{
	int		x;
	// int		i;
	char	**coord;
	char	*line;

	x = 0;
	in_map->height_max = 0;
	in_map->height_min = 0;
	in_map->map = (int **)malloc(sizeof(int *) * (in_map->height + 1));
	while (get_next_line(fd, &line))
	{
		coord = ft_strsplit(line, ' ');
		in_map->map[x] = get_values(coord, in_map->width);
		free(coord);
		free(line);
		// i = 0;
		// while (i < in_map->width)
		// {

		// 	i++;
		// }
	}
	close(fd);
}

int		find_width(char **coord)
{
	int		x;

	x = 0;
	while (coord[x] != '\0')
		x++;
	return (x);
}

void	find_width_heigth(int fd, t_map *in_map)
{
	int		y;
	char	*line;
	char	**coord;

	y = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		coord = ft_strsplit(line, ' ');
		in_map->width = find_width(coord);
	}
	free(coord);
	free(line);
	close(fd);
}

void	storing(char *argument, t_map *in_map)
{
	int		fd;

	if ((fd = open(argument, O_RDONLY)) == -1)
		error("Error Opening");
	find_width_heigth(fd, in_map);
	fd = open(argument, O_RDONLY);
	find_z_value(fd, in_map);
}