/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_few_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:04:40 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/26 16:08:04 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	few_b_to_a(t_stack **a, t_stack **b)
{
	int	t;

	t = ps_lstsize(*b);
	while (t > 0)
	{
		push(b, a, 1);
		t--;
	}
}

void	few_to_b(t_stack **a, t_stack **b, t_stack *aux, int pos)
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

void	sort_few_numbers(t_data data, t_stack **a, t_stack **b)
{
	t_stack	*aux;
	int		t;
	int		pos;
	int		i;

	t = data.numbers;
	aux = *a;
	pos = 0;
	i = 0;
	while (t > 3)
	{
		while (i != aux->index)
		{
			aux = aux->next;
			pos++;
		}
		few_to_b(a, b, aux, pos);
		aux = *a;
		t--;
		i++;
	}
}
