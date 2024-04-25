/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_orden_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:55:09 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/25 18:01:59 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack **a, t_stack **b)
{
	while (ps_lstsize(*b) > 0)
	{
		push(b, a, 1);
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
		//print_numbers(*a, *b);
	}
	orden_three_numbers(a);
	//print_numbers(*a, *b);
	push_to_a(a, b);
	//print_numbers(*a, *b);
}

void	algorithm(t_data data, t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	put_index(stack_a, data.numbers);
	//print_numbers(*stack_a, NULL);
	push_all_less_three(data, stack_a, &stack_b);
}

void	orden_numbers(t_data data, t_stack **stack_a)
{
	if (data.numbers == 3)
		orden_three_numbers(stack_a);
	else
		algorithm(data, stack_a);
}
