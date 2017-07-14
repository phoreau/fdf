/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:57:35 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/14 15:21:12 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

typedef struct		s_env
{
	void			*mlx;
	void			*win;
					// gap;
					// m;
					
					// cart;
					// j;
					// i;

}					t_env;

typedef struct		s_map
{
	int				**map;
	int				height_min;
	int				height_max;
	int				width;
	int				height;
	int				mid_x;
	int				mid_y;
}					t_map;

typedef struct		s_points
{
	float			x;
	float			y;
	float			z;
}					t_points;

//		Parsing
int					parse(char *argument);
void				error(int x);

//		Storing
int					find_width(char **coord);
void				find_width_heigth(int fd, t_map *in_map);
void				storing(char *argument, t_map *in_map);
void				find_z_value(int fd, t_map *in_map);

//		Bullshit
void				linebres_negative(int x0, int y0, int x1, int y1);
void				linebres_positive(int x0, int y0, int x1, int y1);

#endif
