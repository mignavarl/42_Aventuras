/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_calculate_mov.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:04:40 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/26 16:08:04 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	orden_b(t_stack **b)
{
	t_stack *aux;

	aux = ps_lstlast(*b);
	if ((*b)->index < aux->index)
	{
		while ((*b)->index < aux->index)
		{
			reverse_rotate(b, 2);
			aux = ps_lstlast(*b);
		}
	}
}

void	in_middle_b(t_stack **a, t_stack **b)
{
	t_stack	*aux;

	aux = ps_lstlast(*b);
	if (((*b)->index - (*a)->index) < ((*a)->index - aux->index))
	{
		while ((*a)->index < (*b)->index)
		{
			rotate(b, 2);
			if ((*a)->index > (*b)->index)
			{
				push(a, b, 2);
				break ;
			}
		}
	}
	else if (((*b)->index - (*a)->index) > ((*a)->index - aux->index))
	{
		while ((*a)->index < (*b)->index)
		{
			reverse_rotate(b, 2);
			if ((*a)->index > (*b)->index)
			{
				push(a, b, 2);
				break ;
			}
		}
	}
}

void	calculate_mov(t_stack **a, t_stack **b)
{
	t_stack	*aux;

	aux = ps_lstlast(*b);
	if ((*a)->index < (*b)->index && (*a)->index < aux->index)
	{
		push(a, b, 2);
		rotate(b, 2);
	}
	else if ((*a)->index > (*b)->index && (*a)->index < aux->index)
		push(a, b, 2);
	else if ((*a)->index > (*b)->index && (*a)->index > aux->index)
		push(a, b, 2);
	else if ((*a)->index < (*b)->index && (*a)->index > aux->index)
	{
		in_middle_b(a, b);
	}
	//print_numbers(*a, *b);
}
