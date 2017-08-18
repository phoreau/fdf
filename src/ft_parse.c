/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:10:01 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/14 15:22:23 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** has to to be a positive or negative number 0-9
** and a space or a \n before the end of file
** no alphabet or anything that is not a space, a new line or a number positive
** or negative.
*/

int				ft_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

void			ft_line_check(char *s)
{
	int			i;

	i = 0;
	if (!*s)
		error_msg("Error: Invalid File");
	while (s[i] != '\0')
	{
		if (ft_isalpha(s[i]) == 1)
			error_msg("Error: Found alphabet character(s)");
		if ((s[i] == '-' && (!(ft_isdigit(s[i + 1])))) || s[i] == '\t')
			error_msg("Error: Found forbidden characters");
		i++;
	}
}

void			ft_checkwidth(int fd, int w, int w1, t_values *val)
{
	if (get_next_line(fd, &(val->line)))
	{
		ft_line_check(val->line);
		if ((val->coord = ft_strsplit(val->line, ' ')) == NULL || !*val->coord)
			error_msg("Error: Content");
		if (!(w = find_width(val->coord)))
			error_msg("Error: Width");
		free(val->coord);
		free(val->line);
	}
	else
		error_msg("Empty File");
	while (get_next_line(fd, &val->line))
	{
		ft_line_check(val->line);
		if ((val->coord = ft_strsplit(val->line, ' ')) == NULL || !*val->coord)
			error_msg("Error: Content");
		w1 = find_width(val->coord);
		if (w != w1)
			error_msg("Error: Width uneven");
		free(val->coord);
		free(val->line);
	}
}

void			ft_parse(char *av)
{
	t_values	values;
	int			w;
	int			w1;
	int			fd;

	w = 0;
	w1 = 0;
	if ((values.str = ft_strstr(av, ".fdf")) == 0)
		error_msg("Error: Filename");
	if ((fd = open(av, O_RDONLY)) < 0)
		error_msg("Error: Opening");
	ft_checkwidth(fd, w, w1, &values);
}
