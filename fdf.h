/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:57:35 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/09 18:57:30 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef	struct		s_bresen
{
	float			offset;
	float			threshold;
	float			adjust;
	float			delta;
	float			tmp;
	int				colorgrade;
	float			color;
	float			range;
	char			*str;
	char			**coord;
	char			*line;
}					t_bresen;


#endif
