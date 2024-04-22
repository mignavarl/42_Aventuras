/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:11:23 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/01 14:59:56 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_atoi_limits(long res, long sym, t_data data)
{
	if ((res * sym) < INT_MIN)
		print_error("Below INT_MIN", data);
	else if ((res * sym) > INT_MAX)
		print_error("Above INT_MAX", data);
}

int	ps_atoi(const char *str, t_data data)
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
	ps_atoi_limits(res, sym, data);
	return (res * sym);
}
