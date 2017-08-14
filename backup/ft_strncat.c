/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 13:15:45 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/10 13:33:53 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		len;
	int		index;

	len = ft_strlen(s1);
	index = 0;
	while (n > 0 && s2[index] != '\0')
	{
		s1[len] = s2[index];
		index++;
		len++;
		n--;
	}
	s1[len] = '\0';
	return (s1);
}
