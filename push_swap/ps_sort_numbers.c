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
	if (data.numbers == 3)
		sort_three_numbers(stack_a);
	else
		algorithm(data, stack_a);
}
