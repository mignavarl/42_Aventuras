/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:21:15 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/25 18:26:11 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_data data)
{
	write(2, "Error\n", 6);
	if (data.bunker)
		free_bunker(data);
	exit(0);
}

void	check_sort(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	int		i;
	int		final;

	first = *a;
	second = *a;
	second = second->next;
	i = 0;
	final = ps_lstsize(*a);
	while (i < final)
	{		
		if (second->content < first->content)
			return ;
		second = second->next;
		first = first->next;
		if (!second)
			break ;
		i++;
	}
	free_stack(*a);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_data	data;

	if (argc == 1)
		return (0);
	if (check_letters(argc - 1, argv) == 1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	data.numbers = count_number(argc - 1, argv);
	if (data.numbers < 2)
		return (0);
	data.bunker = create_bunker(argv, argc - 1, data);
	check_numbers(data);
	stack_a = NULL;
	stack_a = create_list(stack_a, data.bunker, data.numbers);
	free_bunker(data);
	check_sort(&stack_a);
	sort_numbers(data, &stack_a);
	free_stack(stack_a);
	return (0);
}
