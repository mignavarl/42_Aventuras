/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-23 13:07:10 by mignavar          #+#    #+#             */
/*   Updated: 2024-08-23 13:07:10 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat_dead(t_philo *philo)
{
	if (its_dead(philo) == 1)
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	else if (ft_time(philo) >= (philo->last_eat + philo->time_die))
	{
		dead(philo);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	return (0);
}

int	eat(t_philo *philo)
{
	if (its_dead(philo) == 0)
	{
		pthread_mutex_lock(&philo->fork);
		print_text(philo, "taken a fork");
		pthread_mutex_lock(philo->left_fork);
		if (eat_dead(philo) == 1)
			return (1);
		print_text(philo, "taken a fork");
		print_text(philo, "is eating");
		usleep(philo->time_eat);
		philo->last_eat = ft_time(philo);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}
	return (1);
}
