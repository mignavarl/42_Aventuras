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

int	reaper_eat(t_data *data)
{
	int	eaten;
	int	ph;

	ph = 1;
	pthread_mutex_lock(&data->mutex_must_eat);
	if (data->argc == 6)
	{
		eaten = 1;
		while (ph++ <= data->num_ph)
		{
			if (data->array_philo[ph].must_eat <= 0)
				eaten++;
		}
		//printf(WHITE"EATEN: %d"END, eaten);
		if (data->num_ph == eaten)
		{
			pthread_mutex_lock(&data->mutex_dead);
			data->someone_is_dead_so_sad = 1;
			pthread_mutex_unlock(&data->mutex_dead);
			pthread_mutex_unlock(&data->mutex_must_eat);
			printf(GREEN"[%ld] Everyone has eaten 🍾\n"END, ft_time(&data->array_philo[1]));
			return (1);
		}
	}
	pthread_mutex_unlock(&data->mutex_must_eat);
	return (0);
}

int	time_dead(t_data *data, int ph, size_t time, size_t ph_last_eat)
{
	if (time >= (ph_last_eat + data->die))
	{
		dead(&data->array_philo[ph]);
		pthread_mutex_unlock(&data->mutex_reaper_time);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_reaper_time);
	return (0);
}

void	reaper(void *arg)
{
	t_data	*data;
	size_t	time;		
	size_t	ph_last_eat;
	int		ph;

	data = (t_data *)arg;
	ph = 1;
	while (42)
	{
		pthread_mutex_lock(&data->mutex_eat);
		time = ft_time(&data->array_philo[ph]);
		ph_last_eat = data->array_philo[ph].last_eat;
		pthread_mutex_unlock(&data->mutex_eat);
		pthread_mutex_lock(&data->mutex_reaper_time);
		if (time_dead(data, ph, time, ph_last_eat) == 1)
			break ;
		if (reaper_eat(data) == 1)
			break ;
		ph++;
		if (ph > data->num_ph)
			ph = 1;
		usleep(100);
	}
}
