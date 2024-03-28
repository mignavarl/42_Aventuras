/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:15:18 by mignavar          #+#    #+#             */
/*   Updated: 2024/03/28 16:16:06 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_lst_intnew(int number)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s -> content = number;
	s -> next = NULL;
	return (s);
}

void	ps_lstadd_front(t_stack **lst, t_stack *new)
{
	new -> next = *lst;
	*lst = new;
}

t_stack	**create_list(t_stack **list, char **bunker, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		ps_lstadd_front(list, ps_lst_intnew(ps_atoi(bunker[i])));
		i++;
	}
	return (list);
}
