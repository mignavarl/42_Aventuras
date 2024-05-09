/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_index_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:11:15 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/25 16:29:25 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min_no_index(t_stack *a)
{
	t_stack	*aux;
	t_stack	*s_clon;
	int		min;

	s_clon = a;
	while (s_clon)
	{
		if (s_clon->index < 0)
		{
			min = s_clon->content;
			aux = s_clon;
			break ;
		}
		s_clon = s_clon->next;
	}
	while (s_clon)
	{
		if (s_clon->index < 0 && min > s_clon->content)
		{
			min = s_clon->content;
			aux = s_clon;
		}
		s_clon = s_clon->next;
	}
	return (aux);
}

void	put_index(t_stack **stack_a, int numbers)
{
	static int	idx;
	t_stack		*aux;

	if (!idx)
		idx = 0;
	aux = min_no_index(*stack_a);
	aux->index = idx;
	if (idx < numbers - 1)
	{
		idx++;
		put_index(stack_a, numbers);
	}
}
