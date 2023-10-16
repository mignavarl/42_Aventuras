/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:37:24 by mignavar          #+#    #+#             */
/*   Updated: 2023/10/16 18:22:05 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newlist;

	newlist = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		new = lst;
		new = ft_lstnew(f(new -> content));
		if (!new)
		{
			ft_lstclear(new -> content, del);
			return (0);
		}
		ft_lstadd_back(&newlist, new);
		lst = lst -> next;
	}
	return (newlist);
}
