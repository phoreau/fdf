/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:06:45 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/18 16:43:30 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include "fdf.h"

/*
** ++++++++++++++++++++++++++++++++++++++
** +									+
** +			M A C R O S				+
** +									+
** ++++++++++++++++++++++++++++++++++++++
*/

# define WIN_Y			750
# define WIN_X			1080

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYPRESSMASK (1L<<0)
# define KEYRELEASEMASK (1L<<1)

# define KEY_ESCAPE		53
# define KEY_ENTER		36
# define KEY_LEFT		123
# define KEY_DOWN		125
# define KEY_RIGHT		124
# define KEY_UP			126

# define KEY_PLUS 24
# define KEY_MINUS 27
# define PAGE_UP 116
# define PAGE_DOWN 121
# define RESET 51

# define GOLD			0x00e19f00
# define BRIGHTBLUE		0x0000ffec
# define PINK			0x00e27589
# define PINKCLEAR		0x00eca1ac
# define BRIGHTPINK		0x00f9cdd4
# define TURQUOISE1		0x0065abf3
# define TURQUOISE2		0x007dedf5
# define BORDEAUXRED	0x009c162e
# define PURPLE			0x00713da5

/*
** Essential colors
*/

# define BLACK			0x000000
# define WHITE			0xFFFFFF
# define RED			0xFF0000
# define ORANGE			0xFFA500
# define LIME			0x00FF00
# define BLUE			0x0000FF
# define YELLOW			0xFFFF00
# define CYAN			0x00FFFF
# define MAGENTA		0xFF00FF
# define SILVER			0xC0C0C0
# define GRAY			0x808080
# define MAROON			0x800000
# define OLIVE			0x808000
# define GREEN			0x008000
# define TEAL			0x008080
# define NAVY			0x000080

#endif
