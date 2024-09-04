/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-21 14:14:38 by mignavar          #+#    #+#             */
/*   Updated: 2024-08-21 14:14:38 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	if (its_dead(philo) == 0)
		print_text(philo, "is thinking");
}

void	sleeping(t_philo *philo)
{
	if (its_dead(philo) == 0)
	{
		print_text(philo, "is sleeping");
		// if (philo->time_sleep > (philo->last_eat + philo->time_die))
		// {
		// 	usleep(philo->time_die * 1000);
		// 	dead(philo);
		// 	return ;
		// }
		usleep(philo->time_sleep * 1000);
	}
}
