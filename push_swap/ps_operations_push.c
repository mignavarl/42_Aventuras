/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:10:08 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/15 17:26:17 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_orig, t_stack **stack_dest, int i)
{
	t_stack	*dir;

	if (!*stack_orig)
		return ;
	dir = *stack_orig;
	*stack_orig = (*stack_orig)->next;
	dir->next = *stack_dest;
	*stack_dest = dir;
	if (i == 1)
		write(1, "pa\n", 3);
	if (i == 2)
		write(1, "pb\n", 3);
}
