/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 21:48:47 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/17 11:10:57 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		index;
	int		nbr;
	int		neg;

	index = 0;
	nbr = 0;
	neg = 0;
	while (str[index] == ' ' || str[index] == '\t' || str[index] == '\n' ||
		str[index] == '\v' || str[index] == '\f' || str[index] == '\r')
		index++;
	if (str[index] == '-')
		neg = 1;
	if (str[index] == '+' || str[index] == '-')
		index++;
	while (str[index] && (str[index] >= '0') && (str[index] <= '9'))
	{
		nbr *= 10;
		nbr += (str[index] - 48);
		index++;
	}
	if (neg == 1)
		return (-nbr);
	return (nbr);
}
