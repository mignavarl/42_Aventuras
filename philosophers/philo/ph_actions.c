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
	pthread_mutex_lock(&philo->data->mutex_dead);
	if (philo->data->someone_is_dead_so_sad == 0 && philo->eating == 0
		&& philo->sleeping == 0)
		print_text(philo, "is thinking");
	pthread_mutex_unlock(&philo->data->mutex_dead);
}

void	eat(t_philo *philo)
{
	if (philo->sleeping == 0 && philo->data->someone_is_dead_so_sad == 0)
	{
		pthread_mutex_lock(&philo->fork);
		philo->eating = 1;
		print_text(philo, "has taken a fork");
		if (philo->id != 0)
		{
			while (philo->data->array_philo[philo->id - 1].eating == 1)
				continue ;
		}
		else if (philo->id == 0)
		{
			while (philo->data->array_philo[philo->data->num_ph].eating == 1)
				continue ;
		}
		pthread_mutex_lock(&philo->left_fork);
		print_text(philo, "has taken a fork");
		print_text(philo, "is eating");
		usleep(philo->time_eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->left_fork);
		philo->eating = 0;
		philo->last_eat = ft_time();
	}
}

void	sleep(t_philo *philo)
{
	if (philo->eating == 0 && philo->data->someone_is_dead_so_sad == 0)
	{
		philo->sleeping = 1;
		print_text(philo, "is sleeping");
		usleep(philo->time_sleep);
		philo->sleeping = 0;
	}
}

void	dead(t_philo *philo)
{
	philo->data->someone_is_dead_so_sad = 1;
}
