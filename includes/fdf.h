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

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // REMOVE AT THE END //
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

#define				HEIGHT 750
#define				WIDTH 1080

# define 			KEY_ESCAPE	53
# define 			KEY_ENTER	36
# define 			KEY_LEFT	123
# define 			KEY_DOWN	125
# define 			KEY_RIGHT	124
# define 			KEY_UP		126

typedef struct		s_map
{
	int				**map;
	int				width;
	int				height;
	int				height_min;
	int				height_max;
	int				mid_x;
	int				mid_y;
}					t_map;

typedef struct		s_data
{
	float			x;
	float			y;
	float			z;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	float			z1;
	float			z2;
	int				i;
	int				j;
	int				width;
	int				height;
	int				height_min;
	int				height_max;
	void			*mlx;
	void			*win;
}					t_data;

int					start(t_data *coords, t_map *map);

//		Parsing
int					parse(char *argument);
void				error(int x);

//		Storing
int					find_width(char **coord);
void				find_width_height_and_z(int fd, t_map *in_map);
void				storing(char *argument, t_map *in_map);

//		Bresenham
void				line_negative(t_data *env, int x0, int y0, int x1, int y1);
void				line_positive(t_data *env, int x0, int y0, int x1, int y1);

//		Bullshit
void				draw_grid(t_data *info, t_map *map);
void				vertical_line(t_data *e, int x0, int y0, int x1, int y1);
t_data				*get_info(t_map *map);

#endif
