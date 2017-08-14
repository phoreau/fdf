/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 21:21:35 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/12 20:08:03 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				index;
	unsigned char		*d;
	unsigned char		*s;

	index = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (index < n)
	{
		d[index] = s[index];
		index++;
	}
	return (dst);
}
