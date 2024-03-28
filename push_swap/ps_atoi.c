/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:11:23 by mignavar          #+#    #+#             */
/*   Updated: 2024/03/27 11:15:34 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_limits(long res, long sym)
{
	if ((res * sym) < INT_MIN)
		print_error("Below INT_MIN\n");
	else if ((res * sym) > INT_MAX)
		print_error("Above INT_MAX");
}

int	ps_atoi(const char *str)
{
	long	sym;
	long	res;

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
		str++;
	}
	check_limits(res, sym);
	return (res * sym);
}
