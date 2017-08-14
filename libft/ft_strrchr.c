/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 16:06:58 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/12 21:25:21 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int					index;
	unsigned char		ch;
	char				*str;

	index = ft_strlen(s);
	ch = (unsigned char)c;
	str = (char *)s;
	while (index >= 0)
	{
		if (str[index] == ch)
			return (&str[index]);
		index--;
	}
	if (index == 0)
		return (&str[index]);
	return (0);
}
