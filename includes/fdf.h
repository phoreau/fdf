/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:57:35 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/18 14:35:59 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "macros.h"
# include "../minilibx_macos/mlx.h"

/*
** ++++++++++++++++++++++++++++++++++++++++++
** +										+
** +			S T R U C T S				+
** +										+
** ++++++++++++++++++++++++++++++++++++++++++
*/

typedef struct		s_map
{
	int				**map;
	int				j;
	int				w;
	int				h;
	int				h_min;
	int				h_max;
	int				mid_x;
	int				mid_y;
}					t_map;

typedef struct		s_values
{
	float			offset;
	float			threshold;
	float			adjust;
	float			delta;
	float			color;
	float			tmp;
	float			range;
	char			*str;
	char			**coord;
	char			*line;
}					t_values;

typedef struct		s_points
{
	float			x;
	float			y;
	float			z;
	float			rawz;
}					t_points;

typedef struct		s_data
{
	t_points		**cart;

	int				x;
	int				y;
	int				z;

	float			x1;
	float			x2;
	float			y1;
	float			y2;
	float			z1;
	float			z2;

	int				i;
	int				j;

	int				w;
	int				h;
	int				h_min;
	int				h_max;

	int				gap;
	int				big;
	int				max;
	int				smax;
	int				cur_z;
	int				next_z;

	float			rise;
	float			run;
	float			slope;
	float			fix;

	int				left_right;
	int				up_down;
	int				page_up_down;
	int				more_less;
	int				reset;
	
	float			e;

	void			*mlx;
	void			*win;
}					t_data;

/*
** ++++++++++++++++++++++++++++++++++++++++++
** +										+
** +			F U N C T I O N S			+
** +										+
** ++++++++++++++++++++++++++++++++++++++++++
*/

int					start(t_data *info);

void				ft_parse(char *av);
void				error_msg(char *str);

int					find_width(char **coord);
void				find_width_height_and_z(int fd, t_map *map);
void				storing(char *argument, t_map *map);

void				line_negative(t_data *env, int x0, int y0, int x1, int y1);
void				line_positive(t_data *env, int x0, int y0, int x1, int y1);

void				draw(t_data *info);
t_data				*get_info(t_map *map);
void				rotate(t_data *info);
void				decrease_z(t_data **info);
void				increase_z(t_data **info);

void				slope_gradual(t_data *info, t_values *values);
void				slope_sharp(t_data *info, t_values *values);
void				slope_straight(t_data *info);
void				draw_right(t_data *info, t_values **values);
void				draw_down(t_data *info, t_values **values);

void				translate(t_data **info);

#endif
