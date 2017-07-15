/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:57:35 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/14 18:27:06 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

# define KEY_ESCAPE	53
# define KEY_ENTER	36
# define KEY_LEFT	123
# define KEY_DOWN	125
# define KEY_RIGHT	124
# define KEY_UP		126

typedef struct		s_points
{
	float			x;
	float			y;
	float			z;
}					t_points;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	float			y1;
	float			x1;
	float			x2;
	float			y2;
	int				hmin;
	int				hmax;
	int				w;
	int				h;
	t_points		**points;
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

typedef struct		s_info
{
	int				numlines;
	int				numcols;
	int				height;
	int				width;
}					t_info;

//		Parsing
int					parse(char *argument);
void				error(int x);

//		Storing
int					find_width(char **coord);
void				find_width_height_and_z(int fd, t_map *in_map);
void				storing(char *argument, t_map *in_map);

//		Bullshit
void				linebres_negative(int x0, int y0, int x1, int y1);
void				linebres_positive(int x0, int y0, int x1, int y1);

#endif
