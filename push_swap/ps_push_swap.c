/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:21:15 by mignavar          #+#    #+#             */
/*   Updated: 2024/03/28 16:50:04 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void d_leaks(void)
{
	system("leaks push_swap");
}

void	print_numbers(t_stack *stack_a, int numbers)
{
	int	i;
	int num;

	i = 0;
	while (i <= numbers)//Mostrar los int
	{
		num = stack_a -> content;
		ft_printf("Numbers %d = %d\n", i, num);
		i++;
		stack_a = stack_a->next;
		
	}
}


void print_bunker(char **bunker, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		ft_printf("Bunker[%d]: %s\n", i, bunker[i]);
		i++;
	}
}

//TODO: liberar cuando haya errores
//TODO: empezar con los movimientos

int	main(int argc, char **argv)
{
	//atexit(d_leaks);
	t_stack	**stack_a;
	t_data	data;

	if (check_letters(argc - 1, argv) == 1)
		return (0);
	data.numbers = count_number(argc - 1, argv);
	ft_printf("Nº Argumentos = %d\n", data.numbers);
	data.bunker = create_bunker(argv, argc - 1, data.numbers);
	print_bunker(data.bunker, data.numbers);
	//Crear lista y añadir los int
	stack_a = malloc(sizeof(t_stack));
	stack_a = create_list(stack_a, data.bunker, data.numbers);
	//ft_printf("Aquí\n");
	print_numbers(*stack_a, data.numbers - 1);
	//check_equal(data.numbers, stack);
	free_bunker(data.bunker, data.numbers);
	free_stack(stack_a);
	ft_printf(GREEN"Todo OK\n"END);
	return (0);
}
