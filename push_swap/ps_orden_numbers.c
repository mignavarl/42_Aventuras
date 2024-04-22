/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_orden_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:55:09 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/22 11:06:26 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	orden_numbers(t_data data, t_stack **stack_a)
{
	
	if (data.numbers == 3)
		orden_three_numbers(stack_a);
}
