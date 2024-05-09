/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:55:09 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/26 12:47:04 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	appendix_more(t_stack **a, t_stack **b, t_stack *aux, int pos)
{
	if (pos < ps_lstsize(*b) / 2)
	{
		while (pos-- >= -1)
		{
			if ((*b) == aux)
			{
				push(b, a, 1);
				break ;
			}
			rotate(b, 2);
		}
	}
	else
	{
		while (pos-- >= -1)
		{
			if ((*b) == aux)
			{
				push(b, a, 1);
				break ;
			}
			reverse_rotate(b, 2);
		}
	}
}

void	more_b_to_a(t_stack **a, t_stack **b, int t)
{
	t_stack	*clon;
	t_stack	*aux;
	int		pos;

	while (t > 0)
	{
		pos = 0;
		clon = *b;
		while (clon->index != t - 1)
		{
			clon = clon->next;
			pos++;
		}
		aux = clon;
		appendix_more(a, b, aux, pos);
		t--;
	}
}

void	algorithm(t_data data, t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	put_index(stack_a, data.numbers);
	if (data.numbers <= 50)
	{
		sort_few_numbers(data, stack_a, &stack_b);
		sort_three_numbers(stack_a);
		few_b_to_a(stack_a, &stack_b);
	}
	else
	{
		sort_more_numbers(data, stack_a, &stack_b);
		sort_three_numbers(stack_a);
		more_b_to_a(stack_a, &stack_b, ps_lstsize(stack_b));
	}
}

void	sort_numbers(t_data data, t_stack **stack_a)
{
	if (data.numbers == 2)
		swap(stack_a, 1);
	else if (data.numbers == 3)
		sort_three_numbers(stack_a);
	else
		algorithm(data, stack_a);
}
