 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:02:54 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/09 15:33:08 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_lstlast(t_stack *lst)
{
	t_stack	*l;

	l = lst;
	while (l != NULL)
	{
		if (l -> next == NULL)
			return (l);
		l = l -> next;
	}
	return (0);
}

void	rotate(t_stack **stack, int i)
{
	t_stack	*dir;
	t_stack	*clon;

	if (ps_lstsize(*stack) < 2 || !stack)
		return ;
	dir = *stack;
	*stack = (*stack)->next;
	clon = ps_lstlast(*stack);
	clon->next = dir;
	dir->next = NULL;
	if (i == 1)
		write(1, "ra\n", 3);
	if (i == 2)
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack **stack, int i)
{
	t_stack	*dir;
	t_stack	*clon;

	if (ps_lstsize(*stack) < 2 || !stack)
		return ;
	dir = ps_lstlast(*stack);
	clon = *stack;
	while (clon)
	{
		if (clon->next == dir)
			break ;
		clon = clon->next;
	}
	dir->next = *stack;
	*stack = dir;
	clon->next = NULL;
	if (i == 1)
		write(1, "rra\n", 4);
	if (i == 2)
		write(1, "rrb\n", 4);
}

void	double_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	write(1, "rr\n", 3);
}

void	double_reverse(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	write(1, "rrr\n", 4);
}
