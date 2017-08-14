/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 20:14:28 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/12 20:09:39 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				index;
	unsigned char		*d;
	unsigned char		*s;
	unsigned char		ch;

	index = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	ch = (unsigned char)c;
	while (index < n)
	{
		d[index] = s[index];
		if (s[index] == ch)
			return (&dst[index + 1]);
		index++;
	}
	return (NULL);
}
