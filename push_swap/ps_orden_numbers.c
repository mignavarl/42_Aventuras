/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_orden_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:55:09 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/22 14:23:29 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_stack **stack_a, int numbers)
{
	static int	idx;
	t_stack 	*s_clon;
	t_stack		*aux;
	int			min;

	idx = 0;
	s_clon = stack_a;
	min = s_clon->content;
	if (!idx)
		idx = 0;
	while(s_clon && idx < numbers)
	{
		s_clon = s_clon->next;
		if (min > s_clon->content && s_clon->index == NULL)
		{
			min = s_clon->content;
			aux = s_clon;
		}
	}
	aux->index = idx;
	if (idx < numbers)
	{
		idx++;
		put_index(stack_a, numbers);
	}
}

void	algorithm(t_data data, t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	put_index(stack_a, data.numbers);
}

void	orden_numbers(t_data data, t_stack **stack_a)
{
	
	if (data.numbers == 3)
		orden_three_numbers(stack_a);
	else
		algorithm(data, stack_a);
}
