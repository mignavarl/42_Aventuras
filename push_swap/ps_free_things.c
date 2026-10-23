/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:32:43 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/10 15:38:52 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_bunker(t_data data)
{
	int	i;

	i = 0;
	if (!data.bunker)
		exit(0);
	while (i < data.numbers)
	{
		free(data.bunker[i]);
		i++;
	}
	free(data.bunker);
}

void	free_stack(t_stack *stack)
{
	t_stack	*l;
	int		i;
	int		fin;

	i = 0;
	fin = ps_lstsize(stack);
	while (i < fin)
	{
		l = stack;
		stack = l -> next;
		free(l);
		i++;
	}
	stack = NULL;
}
