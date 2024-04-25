/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:03:35 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/23 16:11:57 by mignavar         ###   ########.fr       */
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

int	check_letters(int ac, char **av)
{
	int	n;

	n = 0;
	while (ac > 0)
	{
		while (av[ac][n])
		{
			if ((ft_isdigit(av[ac][n]) == 0 && av[ac][n] != '-'
				&& av[ac][n] != ' ' && av[ac][n] != '+')
				|| ft_strncmp(av[ac], "-0", ft_strlen(av[ac])) == 0)
				return (1);
			if ((av[ac][n] == '-' && av[ac][n - 1] == '-')
				|| (av[ac][n] == '+' && av[ac][n - 1] == '+')
				|| (av[ac][n] == '-' && av[ac][n - 1] == '+')
				|| (av[ac][n] == '+' && av[ac][n - 1] == '-'))
				return (1);
			n++;
		}
		n = 0;
		ac--;
	}
	return (0);
}

void	check_equal(t_data data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < data.numbers)
	{
		while (j < data.numbers)
		{
			if (ft_atoi(data.bunker[i]) == ft_atoi(data.bunker[j]))
			{
				print_error(data);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	check_limits(t_data data)
{
	int	i;

	i = 0;
	while (i < data.numbers)
	{
		ps_atoi(data.bunker[i], data);
		i++;
	}
}

void	check_numbers(t_data data)
{
	check_equal(data);
	check_limits(data);
}
