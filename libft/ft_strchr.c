/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:53:40 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/17 11:12:05 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int					index;
	unsigned char		ch;
	char				*str;

	index = 0;
	ch = (unsigned char)c;
	str = (char*)s;
	while (str[index] != '\0')
	{
		if (str[index] == ch)
			return (&str[index]);
		index++;
	}
	if (ch == '\0')
		return (&str[index]);
	return (0);
}
