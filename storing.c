/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:35:03 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/14 16:10:28 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		*get_z_values(char **s, int width)
{
	int		*map;
	int		i;

	i = 0;
	map = (int *)malloc(sizeof(int) * (width + 1));
	while (i < width)
	{
		map[i] = ft_atoi(s[i]);
		printf("[%2d]", map[i]);
		i++;
	}
	printf("\n");
	return (map);
}

/*
** we need to find the z value (let's say altitude)of each spot wether it's 0
** or 1 or 100. so we go through our get next line again and we strsplit to
** find get the values of each spot.
*/
void	find_z_value(int fd, t_map *in_map)
{
	int		x;
	int		i;
	char	*line;
	char 	**coord;

	x = 0;
	in_map->height_max = 0;
	in_map->height_min = 0;
	in_map->map = (int **)malloc(sizeof(int *) * (in_map->height + 1));
	while (get_next_line(fd, &line))
	{
		coord = ft_strsplit(line, ' ');
		in_map->map[x] = get_z_values(coord, in_map->width);
		free(coord);
		free(line);
		i = 0;
		while (i < in_map->width)
		{
			if (in_map->map[x][i] > in_map->height_max)
				in_map->height_max = in_map->map[x][i];
			else
				in_map->height_max = in_map->height_max;
			i++;
		}
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

/*
** we increment y to get the height
** and we call the find width function by incrementing x
*/
void	find_width_heigth(int fd, t_map *in_map)
{
	int		y;
	char	*line;
	char	**coord;

	y = 0;
	while ((get_next_line(fd, &line)) > 0)
	{
		y++;
		coord = ft_strsplit(line, ' ');
		in_map->width = find_width(coord);
	}
	in_map->height = y;
	free(coord);
	free(line);
	close(fd);
}

void	storing(char *argument, t_map *in_map)
{
	int		fd;

	if ((fd = open(argument, O_RDONLY)) == -1)
		error(0);
	find_width_heigth(fd, in_map);
	fd = open(argument, O_RDONLY);
	find_z_value(fd, in_map);
}