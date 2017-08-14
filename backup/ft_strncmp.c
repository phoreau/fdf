/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 20:34:53 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/17 11:06:26 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				index;
	unsigned char		*str1;
	unsigned char		*str2;

	index = 0;
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (index < n)
	{
		if (str1[index] != str2[index])
			return (str1[index] - str2[index]);
		if (str1[index] == '\0' && str2[index] == '\0')
			return (0);
		index++;
	}
	return (0);
}
