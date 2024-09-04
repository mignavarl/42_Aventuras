/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_reaper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-03 09:56:42 by mignavar          #+#    #+#             */
/*   Updated: 2024-09-03 09:56:42 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*reaper(void *arg)
{
	t_data	*data;
	int		ph;
	size_t	time;		

	data = (t_data *)arg;

	ph = 1;
	while (42)
	{
		pthread_mutex_lock(&data->mutex_reaper_time);
		time = ft_time(&data->array_philo[ph]);
		pthread_mutex_unlock(&data->mutex_reaper_time);
		pthread_mutex_lock(&data->mutex_eat);
		if (time >= (data->array_philo[ph].last_eat
				+ data->array_philo[ph].time_die))
		{
			dead(&data->array_philo[ph]);
			pthread_mutex_unlock(&data->mutex_eat);
			break ;
		}
		ph++;
		if (ph == data->num_ph)
			ph = 1;
		pthread_mutex_unlock(&data->mutex_eat);
	}
	return ((void *)0);
}
