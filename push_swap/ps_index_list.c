/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:11:15 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/23 14:12:24 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_no_index(t_stack *a)
{
	int	min;

	while(a)
	{
		if (a->index == NULL)
		{
			min = a->content;
			return (min);
		}
		a = a->next;
	}
	min = a->content;
	return (min);
}

void	put_index(t_stack **stack_a, int numbers)
{
	static int	idx;
	t_stack 	*s_clon;
	t_stack		*aux;
	int			min;

	idx = 0;
	s_clon = *stack_a;
	min = first_no_index(*stack_a);
	if (!idx)
		idx = 0;
	while(s_clon && idx < numbers)
	{
		if (min > s_clon->content && s_clon->index == NULL)
		{
			min = s_clon->content;
			aux = s_clon;
		}
		s_clon = s_clon->next;
	} 
	aux->index = &idx;
	if (idx < numbers)
	{
		idx++;
		put_index(stack_a, numbers);
	}
}
