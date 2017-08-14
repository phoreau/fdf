/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 09:10:45 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/12 19:00:25 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t				index;
	unsigned char		*s;

	index = 0;
	s = (unsigned char*)str;
	while (index < n)
	{
		s[index] = (unsigned char)c;
		index++;
	}
	return (str);
}
