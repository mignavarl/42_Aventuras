/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:21:15 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/24 19:09:52 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_numbers(t_stack *stack_a, t_stack *stack_b)
{
	printf("    A\t|   B\n------------------\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a != NULL)
		{
			printf(" (%d)%d\t|", stack_a->index, stack_a->content);
			stack_a = stack_a->next;
		}
		else
			printf("   \t|");
		if (stack_b != NULL)
		{
			printf("(%d)%d\n", stack_b->index, stack_b->content);
			stack_b = stack_b->next;
		}
		else
			printf("\n");
	}
}

void pruebargh(t_stack **stack_a, t_data data)
{
	char	arg[42];
	t_stack *stack_b;
	
	stack_b = NULL;
	while (1)
	{
		print_numbers(*stack_a, stack_b);
		scanf("%s", arg);
		if (ft_strncmp(arg, "pb", 2) == 0)
			push(stack_a, &stack_b, 2);
		else if (ft_strncmp(arg, "pa", 2) == 0)
			push(&stack_b, stack_a, 1);
		else if (ft_strncmp(arg, "sa", 2) == 0)
			swap(stack_a, 1);
		else if (ft_strncmp(arg, "sb", 2) == 0)
			swap(&stack_b, 2);
		else if (ft_strncmp(arg, "rrr", 3) == 0)
			double_reverse(stack_a, &stack_b);
		else if (ft_strncmp(arg, "ra", 2) == 0)
			rotate(stack_a, 1);
		else if (ft_strncmp(arg, "rb", 2) == 0)
			rotate(&stack_b, 2);
		else if (ft_strncmp(arg, "rra", 3) == 0)
			reverse_rotate(stack_a, 1);
		else if (ft_strncmp(arg, "rrb", 3) == 0)
			reverse_rotate(&stack_b, 2);
		else if (ft_strncmp(arg, "3", 1) == 0)
			orden_three_numbers(stack_a);
		else if (ft_strncmp(arg, "ss", 2) == 0)
			double_swap(stack_a, &stack_b);
		else if(ft_strncmp(arg, "rr", 2) == 0)
			double_rotate(stack_a, &stack_b);
		else if (ft_strncmp(arg, "algo", 4) == 0)
			algorithm(data, stack_a);
		else if (ft_strncmp(arg, "q", 1) == 0)
			break ;
	}
	free(stack_b);
}

// void d_leaks(void)
// {
// 	system("leaks push_swap");
// }
// 	atexit(d_leaks);

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
		print_error(data);
	data.bunker = create_bunker(argv, argc - 1, data);
	check_numbers(data);
	stack_a = NULL;
	stack_a = create_list(stack_a, data.bunker, data.numbers);
	free_bunker(data);
	//pruebargh(&stack_a, data);
	orden_numbers(data, &stack_a);
	free_stack(stack_a);
	ft_printf(GREEN"Todo OK\n"END);
	return (0);
}
