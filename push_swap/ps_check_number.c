/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:03:35 by mignavar          #+#    #+#             */
/*   Updated: 2024/03/14 16:51:17 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_number(int argc, char **argv)
{
	int	ac;
	int	num;
	int	pos;

	ac = 1;
	num = 0;
	pos = 0;
	while (ac <= argc)
	{
		while (argv[ac][pos])
		{
			if (ft_isdigit(argv[ac][pos]) == 1 && (argv[ac][pos + 1] == ' '
				|| argv[ac][pos + 1] == '\0'))
				num++;
			pos++;
		}
		pos = 0;
		ac++;
	}
	return (num);
}

// void	check_equal(int numbers, t_list **list)
// {
// 	int	n;
// 	int	l;

// 	n = 0;
// 	l = 1;
// 	while (n < numbers)
// 	{
// 		while (l <= numbers)
// 		{
// 			if (bunker[n] == bunker[l])
// 			{
// 				print_error("Equal numbers");
// 				exit(0);
// 			}
// 			l++;
// 		}
// 		n++;
// 		l = n + 1;
// 	}
// }

int	check_letters(int ac, char **av)
{
	int	n;

	n = 0;
	while (ac > 0)
	{
		while (av[ac][n])
		{
			if ((ft_isdigit(av[ac][n]) == 0 && av[ac][n] != '-'
				&& av[ac][n] != ' ')
				|| ft_strncmp(av[ac], "-0", ft_strlen(av[ac])) == 0)
				return (1);
			n++;
		}
		n = 0;
		ac--;
	}
	return (0);
}
