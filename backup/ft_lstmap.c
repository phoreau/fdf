/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phoreau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 12:25:33 by phoreau           #+#    #+#             */
/*   Updated: 2016/10/18 21:00:13 by phoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_link;

	if (lst)
	{
		new_link = f(lst);
		new_link->next = ft_lstmap(lst->next, f);
		return (new_link);
	}
	return (NULL);
}
