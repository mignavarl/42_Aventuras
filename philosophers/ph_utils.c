/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-26 09:38:36 by mignavar          #+#    #+#             */
/*   Updated: 2024-07-26 09:38:36 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int				sym;
	unsigned long	res;

	sym = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sym *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if (res > (unsigned long)LONG_MAX && sym == -1)
			return (0);
		else if (res > (unsigned long)LONG_MAX && sym == 1)
			return (-1);
		str++;
	}
	return (res * sym);
}

int	all_args_nums(int argc, char **argv)
{
	int	av;
	int	c;

	av = 1;
	c = 0;
	while (av < argc)
	{
		while (argv[av][c])
		{
			if (argv[av][c] < '0' && argv[av][c] > '9')
				return (1);
			c++;
		}
		c = 0;
		av++;
	}
	return (0);
}
