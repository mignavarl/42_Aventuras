/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-23 12:36:12 by mignavar          #+#    #+#             */
/*   Updated: 2024-08-23 12:36:12 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_dead);
	pthread_mutex_lock(&philo->data->mutex_text);
	if (philo->data->someone_is_dead_so_sad == 0)
	{
		printf("[%ld] %d %s\n", ft_time(philo), philo->id, "died");
		philo->data->someone_is_dead_so_sad = 1;
	}
	pthread_mutex_unlock(&philo->data->mutex_text);
	pthread_mutex_unlock(&philo->data->mutex_dead);
}

int	its_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_dead);
	if (philo->data->someone_is_dead_so_sad == 1)
	{
		pthread_mutex_unlock(&philo->data->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->mutex_dead);
	return (0);
}
