/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_orden_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:55:09 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/23 15:02:16 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_all_less_three(t_data data, t_stack **a, t_stack **b)
// {
// 	t_stack	*clon;
// 	t_stack	*aux;

// 	clon = *a;
// 	while (clon)
// 	{
// 		if (clon->index < (data.numbers - 3))
// 		{
// 			if (!b)
// 				push(a, b, 2);
// 			else
// 			{
// 				aux 
// 			}
// 		}
// 		clon = clon->next;
// 	}
// }

void	algorithm(t_data data, t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	put_index(stack_a, data.numbers);
	//push_all_less_three(data, stack_a, stack_b);
}

void	orden_numbers(t_data data, t_stack **stack_a)
{
	
	if (data.numbers == 3)
		orden_three_numbers(stack_a);
	else
		algorithm(data, stack_a);
}
