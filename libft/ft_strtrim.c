/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 09:11:06 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/17 11:10:28 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_blank(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*tmp;
	int		index;
	int		len;

	index = 0;
	len = ft_strlen(s) - 1;
	while (is_blank(s[index]))
		index++;
	while (is_blank(s[len]))
		len--;
	if (s[len] == '\0')
	{
		tmp = ft_strnew(0);
		return (tmp);
	}
	return (ft_strsub(s, index, len - index + 1));
}
