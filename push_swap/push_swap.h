/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:24:44 by mignavar          #+#    #+#             */
/*   Updated: 2024/03/28 12:02:13 by mignavar         ###   ########.fr       */
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
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	//BUNKER
	char	**bunker;
	int		numbers;

	//STACK
	t_stack **a;
	t_stack	**b;
}					t_data;

	//PRINCIPAL
	int		count_number(int ac, char **av);
	int		ps_atoi(const char *str);
	char	**create_bunker(char **argv, int argc, int numbers);
	t_stack	**create_list(t_stack **list, char **bunker, int num);

	//CHEKERS
	int		check_letters(int ac, char **av);
	//void	check_equal(int numbers, t_stack **list);
	int		check_min_max(int ac, int *bunker);

	//ERRORS
	void	print_error(char *error);

	//FREES
	void	free_bunker(char **bunker, int numbers);
	void	free_stack(t_stack **stack);

#endif