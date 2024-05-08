/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_trhee_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:30:20 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/23 16:14:51 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorythm_three(t_stack **stack, int a, int b, int c)
{
	if (a < b && b > c && a < c)
	{
		swap(stack, 1);
		rotate(stack, 1);
	}
	if (a > b && b < c && a < c)
		swap(stack, 1);
	if (a < b && b > c && a > c)
		reverse_rotate(stack, 1);
	if (a > b && b < c && a > c)
		rotate(stack, 1);
	if (a > b && b > c && a > c)
	{
		rotate(stack, 1);
		swap(stack, 1);
	}
}

void	sort_three_numbers(t_stack **stack)
{
	int		a;
	int		b;
	int		c;
	t_stack	*clon;

	clon = *stack;
	a = clon->content;
	clon = clon->next;
	b = clon->content;
	clon = clon->next;
	c = clon->content;
	algorythm_three(stack, a, b, c);
}
