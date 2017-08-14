/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 16:22:34 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/12 20:17:06 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char const *s1, char const *s2)
{
	int		index;
	char	*str1;
	char	*str2;

	index = 0;
	str1 = (char*)s1;
	str2 = (char *)s2;
	while (str1[index] != '\0')
		index++;
	ft_strcpy(&str1[index], (char*)str2);
	return (str1);
}
