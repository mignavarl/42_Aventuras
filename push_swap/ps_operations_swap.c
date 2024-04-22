/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:58:41 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/16 10:54:51 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, int i)
{
	t_stack	*clon;
	int		temp_first;
	int		temp_second;

	if (ps_lstsize(*stack) < 2 || !stack)
		return ;
	clon = *stack;
	temp_first = clon->content;
	clon = clon->next;
	temp_second = clon->content;
	(*stack)->content = temp_second;
	stack = &(*stack)->next;
	(*stack)->content = temp_first;
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
