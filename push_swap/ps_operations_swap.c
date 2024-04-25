/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:58:41 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/25 17:38:49 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, int i)
{
	t_stack	*clon;
	t_stack	*dir_1;
	t_stack	*dir_2;
	
	if (ps_lstsize(*stack) < 2 || !stack)
		return ;
	clon = *stack;
	dir_1 = clon;
	clon = clon->next;
	dir_2 = clon;
	clon = clon->next;
	dir_1->next = clon;
	dir_2->next = dir_1;
	*stack = dir_2;
	if (i == 1)
		write(1, "sa\n", 3);
	if (i == 2)
		write(1, "sb\n", 3);
}

void	double_swap(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	write(1, "ss\n", 3);
}
