/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 14:41:06 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/17 11:04:14 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_words(char const *str, char c, unsigned int *index)
{
	unsigned int	i;
	unsigned int	start;
	unsigned int	end;
	char			*word;

	i = *index;
	while (str[i] == c)
		i++;
	start = i;
	while (str[i] != c && str[i] != '\0')
		i++;
	end = i;
	*index = i;
	word = ft_strnew(end - start);
	i = 0;
	while (start < end)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *str, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	words;
	char			**array;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			words++;
		i++;
	}
	i = 0;
	j = 0;
	array = (char**)malloc(sizeof(char*) * (words + 1));
	if (!array)
		return (NULL);
	while (i < words)
	{
		array[i] = get_words(str, c, &j);
		i++;
	}
	array[i] = 0;
	return (array);
}
