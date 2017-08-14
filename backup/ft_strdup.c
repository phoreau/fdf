/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 13:23:10 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/12 21:43:43 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *copy;

	copy = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (copy == NULL)
	{
		return (NULL);
	}
	return (ft_strcpy(copy, src));
}
