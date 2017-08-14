/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 20:30:15 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/12 20:18:38 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	index;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	index = 0;
	src_len = 0;
	while (dst[index] && index < size)
		index++;
	dst_len = index;
	while (src[index - dst_len] && index + 1 < size)
	{
		dst[index] = src[index - dst_len];
		index++;
	}
	if (dst_len < size)
		dst[index] = 0;
	return (dst_len + ft_strlen(src));
}
