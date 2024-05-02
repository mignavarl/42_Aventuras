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

void	calculate_mov_a(t_stack **a, t_stack **b)
{
	t_stack	*clon;
	int		i;

	clon = *b;
	i = 0;
	while (clon->index != (*a)->index - 1)
	{
		clon = clon->next;
		i++;
	}
	if (i <= (ps_lstsize(*b) / 2))
	{
		while (i-- > 0)
		{
			rotate(b, 2);
			if ((*a)->index == ((*b)->index - 1))
			{
				push(b, a, 1);
				break ;
			}
		}
	}
	else
		while (i-- >= 0)
		{
			reverse_rotate(b, 2);
			if ((*a)->index == ((*b)->index - 1))
			{
				push(b, a, 1);
				break ;
			}
		}
}

void	appendix_middle_b(t_stack **a, t_stack **b, t_stack *aux)
{
	while ((*a)->index < (*b)->index)
	{
		reverse_rotate(b, 2);
		aux = ps_lstlast(*b);
		if ((*a)->index > (*b)->index || aux->index < (*b)->index)
		{
			push(a, b, 2);
			break ;
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
		appendix_middle_b(a, b, aux);
}

void	calculate_mov(t_stack **a, t_stack **b)
{
	t_stack	*aux;

	aux = ps_lstlast(*b);
	if ((*a)->index < (*b)->index && (*a)->index < aux->index
		&& (*b)->index > aux->index)
	{
		push(a, b, 2);
		rotate(b, 2);
	}
	else if ((*a)->index < (*b)->index && (*a)->index < aux->index
		&& (*b)->index < aux->index)
		in_middle_b(a, b);
	else if ((*a)->index > (*b)->index && (*a)->index < aux->index)
		push(a, b, 2);
	else if ((*a)->index > (*b)->index && (*a)->index > aux->index
			&& aux->index > (*b)->index)
	{
		push(a, b, 2);
		rotate(b, 2);
	}
	else if ((*a)->index < (*b)->index && (*a)->index > aux->index)
	{
		in_middle_b(a, b);
	}
	else if ((*a)->index > (*b)->index && (*a)->index > aux->index
			&& aux->index < (*b)->index)
		push(a, b, 2);
}
