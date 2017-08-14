/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:26:24 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/11 14:34:38 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned char		*s;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (d < s)
		ft_memcpy(dst, src, n);
	else
	{
		d += n - 1;
		s += n - 1;
		while (n--)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dst);
}
