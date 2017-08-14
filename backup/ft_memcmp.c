/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 09:25:48 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/17 11:08:27 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*str1;
	unsigned char	*str2;

	index = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (n)
	{
		if (str1[index] != str2[index])
			return (str1[index] - str2[index]);
		index++;
		n--;
	}
	return (0);
}
