/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:24:44 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/26 12:02:48 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define END "\033[0m"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	//BUNKER
	char	**bunker;
	int		numbers;
}					t_data;
// TODO: borrar
void	print_numbers(t_stack *stack_a, t_stack *stack_b);


	//PRINCIPAL
int		count_number(int ac, char **av);
int		ps_atoi(const char *str, t_data data);
char	**create_bunker(char **argv, int argc, t_data data);
t_stack	*create_list(t_stack *list, char **bunker, int num);

	//CHEKERS
int		check_letters(int ac, char **av);
void	check_equal(t_data data);
int		check_min_max(int ac, int *bunker);
void	check_numbers(t_data data);
void	check_limits(t_data data);

	//OPERATIONS
void	swap(t_stack **stack, int i);
void	double_swap(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_orig, t_stack **stack_dest, int i);
void	rotate(t_stack **stack, int i);
void	double_rotate(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack, int i);
void	double_reverse(t_stack **stack_a, t_stack **stack_b);

	//ALGORYTHMS
void	orden_numbers(t_data data, t_stack **stack_a);
void	orden_three_numbers(t_stack **stack);
void	orden_five_numbers(t_stack **stack_a);
void	put_index(t_stack **stack_a, int numbers);
void	calculate_mov(t_stack **a, t_stack **b);
void	algorithm(t_data data, t_stack **stack_a);
void	orden_b(t_stack **b);

	//LIST_INT
t_stack	*ps_lst_intnew(int number);
void	ps_lstadd_front(t_stack **lst, t_stack *new);
int		ps_lstsize(t_stack *lst);
t_stack	*ps_lstlast(t_stack *lst);

	//ERRORS
void	print_error(t_data data);

	//FREES
void	free_bunker(t_data data);
void	free_stack(t_stack *stack);

#endif