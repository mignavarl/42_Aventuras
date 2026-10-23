/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_more_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-08 09:23:11 by mignavar          #+#    #+#             */
/*   Updated: 2024-05-08 09:23:11 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pos(t_stack **a, t_stack *aux)
{
	t_stack	*clon;
	int		pos;

	clon = *a;
	pos = 0;
	while (clon)
	{
		if (clon == aux)
			return (pos);
		pos++;
		clon = clon-> next;
	}
	return (pos);
}

t_stack	*find_node(t_stack **a, int x, int total)
{
	t_stack	*clon;

	clon = *a;
	while (clon)
	{
		if (clon->index < x && clon->index < total)
			return (clon);
		clon = clon->next;
	}
	return (clon);
}

void	more_to_b(t_stack **a, t_stack **b, t_stack *aux, int pos)
{
	if (pos < ps_lstsize(*a) / 2)
	{
		while (pos-- >= -1)
		{
			if ((*a) == aux)
			{
				push(a, b, 2);
				break ;
			}
			rotate(a, 1);
		}
	}
	else
	{
		while (pos-- >= -1)
		{
			if ((*a) == aux)
			{
				push(a, b, 2);
				break ;
			}
			reverse_rotate(a, 1);
		}
	}
}

void	sort_more_numbers(t_data data, t_stack **a, t_stack **b)
{
	t_stack	*aux;
	int		x;
	int		i;
	int		pos;
	int		piece;

	aux = *a;
	x = ((ps_lstsize(*a) * 10) / 100);
	piece = x;
	i = 0;
	while (i < data.numbers - 3)
	{
		aux = find_node(a, piece, data.numbers - 3);
		pos = find_pos(a, aux);
		more_to_b(a, b, aux, pos);
		i++;
		if (i == piece)
			piece += x;
	}
}
