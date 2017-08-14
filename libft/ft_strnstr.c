/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:28:19 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/18 21:17:51 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	char		*bigcp;
	char		*littlecp;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	bigcp = (char *)b;
	littlecp = (char *)l;
	if (!*l)
		return ((char*)b);
	while (bigcp[i] && i < len)
	{
		j = 0;
		while (bigcp[i + j] == littlecp[j] && (i + j) < len)
		{
			j++;
			if (j == ft_strlen(littlecp))
				return ((char *)(b + (i)));
		}
		i++;
	}
	return (NULL);
}
