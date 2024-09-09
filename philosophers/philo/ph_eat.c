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
	return (0);
}

int	eat(t_philo *philo)
{
	if (its_dead(philo) == 0)
	{
		pthread_mutex_lock(&philo->fork);
		print_text(philo, "f");
		pthread_mutex_lock(philo->left_fork);
		if (its_dead(philo) == 1)
		{
			pthread_mutex_unlock(&philo->fork);
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
		print_text(philo, "f");
		print_text(philo, "e");
		pthread_mutex_lock(&philo->data->mutex_eat);
		philo->last_eat = (ft_time(philo));
		pthread_mutex_unlock(&philo->data->mutex_eat);
		usleep(philo->data->eat * 1000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->fork);
		return (0);
	}
	return (1);
}
