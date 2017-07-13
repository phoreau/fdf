/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <phoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 18:10:01 by phoreau           #+#    #+#             */
/*   Updated: 2017/07/12 15:03:33 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		parse(char *argument)
{
	int		fd;
	char	*str;

	if ((str = ft_strstr(argument, ".fdf")) == 0)
	{	
		fd = open(str, O_RDONLY);
		if (fd == -1)
		{
			error("usage: ./fdf target_file");
			return (-1);
		}
		return (0);
	}
	return (0);
}