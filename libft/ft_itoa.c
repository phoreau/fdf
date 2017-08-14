/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 14:42:21 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/17 11:09:33 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		int_len(long n)
{
	int		index;

	index = 0;
	while (n != 0)
	{
		n = n / 10;
		index++;
	}
	return (index);
}

char			*ft_itoa(int n)
{
	size_t			len;
	char			*str;
	unsigned int	nb;

	len = int_len(n);
	nb = n;
	if (n <= 0)
	{
		nb = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	str[--len] = nb % 10 + '0';
	while (nb /= 10)
		str[--len] = nb % 10 + '0';
	if (n <= 0 && str[0] != '0')
		str[0] = '-';
	return (str);
}
