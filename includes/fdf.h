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

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

# define KEY_ESCAPE	53
# define KEY_ENTER	36
# define KEY_LEFT	123
# define KEY_DOWN	125
# define KEY_RIGHT	124
# define KEY_UP		126

# ifndef ERRS
#  define ERR(a, b) if(a){return(b);}
#  define ERR1(a, b, c) if(a){b;return(c);}
#  define ERR2(a, b, c, d) if(a){b;c;return(d);}
#  define ERR3(a, b, c, d, e) if(a){b;c;d;return(e);}
#  define ERR4(a, b, c, d, e, f) if(a){b;c;d;e;return(f);}
# endif

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
	int				y1;
	int				x1;
	int				x2;
	int				y2;
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
// void				linebres_positive(t_env *points);
void				linebres_positive(int x0, int y0, int x1, int y1);

#endif
