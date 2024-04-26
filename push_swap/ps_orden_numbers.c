/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_orden_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:55:09 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/26 12:47:04 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*aux;
	int		l;

	aux = ps_lstlast(*b);
	l = ps_lstsize(*b);
	while (l > 0)
	{
		if (l == 1)
			push(b, a, 1);
		else if ((*b)->index < aux->index)
		{
			reverse_rotate(b, 2);
			push(b, a, 1);
		}
		else if ((*b)->index > aux->index)
			push(b, a, 1);
		l--;
	}
}

void	push_in_b(t_stack **a, t_stack **b)
{
	if (ps_lstsize(*b) == 1)
	{
		if ((*a)->index < (*b)->index)
		{
			push(a, b, 2);
			swap(b, 2);
		}
		else if ((*a)->index > (*b)->index)
			push(a, b, 2);
	}
	else
		calculate_mov(a, b);
}

void	push_all_less_three(t_data data, t_stack **a, t_stack **b)
{
	while (ps_lstsize(*a) > 3)
	{
		if ((*a)->index <= (data.numbers - 4))
		{
			if (ps_lstsize(*b) == 0)
				push(a, b, 2);
			else
				push_in_b(a, b);
		}
		else
			rotate(a, 1);
	}
	orden_three_numbers(a);
	//orden_b(b);
	push_to_a(a, b);
}

void	algorithm(t_data data, t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	put_index(stack_a, data.numbers);
	push_all_less_three(data, stack_a, &stack_b);
	print_numbers(*stack_a, NULL);
}

void	orden_numbers(t_data data, t_stack **stack_a)
{
	if (data.numbers == 3)
		orden_three_numbers(stack_a);
	else
		algorithm(data, stack_a);
}
