/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:15:18 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/24 18:40:31 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_lstsize(t_stack *lst)
{
	t_stack	*l;
	int		i;

	l = lst;
	i = 0;
	while (l != NULL)
	{
		i++;
		l = l -> next;
	}
	return (i);
}

t_stack	*ps_lst_intnew(int number)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s -> content = number;
	s -> next = NULL;
	s -> index = -1;
	return (s);
}

void	ps_lstadd_front(t_stack **lst, t_stack *new)
{
	new -> next = *lst;
	*lst = new;
}

void	ps_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*l;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	l = ps_lstlast(*lst);
	l->next = new;
}

t_stack	*create_list(t_stack *list, char **bunker, int num)
{
	int	n;

	n = 0;
	while (n < num)
	{
		ps_lstadd_back(&list, ps_lst_intnew(ft_atoi(bunker[n])));
		n++;
	}
	return (list);
}
