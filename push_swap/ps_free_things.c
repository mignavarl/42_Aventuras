/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:32:43 by mignavar          #+#    #+#             */
/*   Updated: 2024/03/28 11:45:42 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_bunker(char **bunker, int numbers)
{
	int	i;

	i = 0;
	while(i <= numbers)
	{
		free(bunker[i]);
		i++;
	}
	free(bunker);
}

void	free_stack(t_stack **stack)
{
	t_stack	*l;

	while (*stack != NULL)
	{
		l = *stack;
		*stack = l -> next;
		free(l);
	}
	free(stack);
}
