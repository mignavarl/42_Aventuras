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

void	waiting_fork(t_philo *philo)//TODO:buscar solucion eating variable, crear un mutex
{
	if (philo->id != 0)
	{
		while (philo->data->array_philo[philo->id - 1].eating == 1)
		{
			continue ;
		}
	}
	else if (philo->id == 0)
	{
		while (philo->data->array_philo[philo->data->num_ph].eating == 1)
			continue ;
	}
}

void	eat(t_philo *philo)//TODO: comer n veces
{
	if (its_dead(philo) == 0)
	{
		pthread_mutex_lock(&philo->fork);
		philo->eating = 1;
		print_text(philo, "has taken a fork");
		waiting_fork(philo);
		if (its_dead(philo) == 1)
		{
			pthread_mutex_unlock(&philo->fork);
			return ;
		}
		pthread_mutex_lock(philo->left_fork);//TODO: ¿se mueren con tenedor en mano?
		print_text(philo, "has taken a fork");
		print_text(philo, "is eating");
		usleep(philo->time_eat);
		
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->left_fork);
		philo->last_eat = ft_time(philo);
	}
}
