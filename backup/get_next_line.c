/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 20:30:37 by phoreau           #+#    #+#             */
/*   Updated: 2017/04/22 20:31:01 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_line(char **line, char **saved)
{
	char	*first_null_char_set;
	char	*after_new_line;

	if ((first_null_char_set = ft_strchr(*saved, '\n')))
	{
		*first_null_char_set = '\0';
		first_null_char_set++;
		after_new_line = ft_strdup(first_null_char_set);
		*line = ft_strdup(*saved);
		free(*saved);
		*saved = after_new_line;
		return (1);
	}
	return (0);
}

static int	get_line_extra_after_last_new_line(char **line, char **saved)
{
	*line = ft_strdup(*saved);
	ft_strdel(saved);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			ret_of_read;
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	static char	*saved = NULL;

	if (!saved)
		saved = ft_strnew(BUFF_SIZE);
	if (!line || fd < 0 || read(fd, buf, 0) < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (get_line(line, &saved))
		return (1);
	while ((ret_of_read = read(fd, buf, BUFF_SIZE)))
	{
		if (ret_of_read == -1)
			return (-1);
		buf[ret_of_read] = '\0';
		tmp = saved;
		saved = ft_strjoin(saved, buf);
		free(tmp);
		if (get_line(line, &saved))
			return (1);
	}
	if (*saved)
		return (get_line_extra_after_last_new_line(line, &saved));
	return (0);
}
