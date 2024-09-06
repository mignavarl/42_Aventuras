/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-01 14:56:44 by mignavar          #+#    #+#             */
/*   Updated: 2024-08-01 14:56:44 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_forks(t_data *data)
{
	int	ph;

	data->array_philo[1].left_fork = &data->array_philo[data->num_ph].fork;
	ph = 2;
	while (ph <= data->num_ph)
	{
		data->array_philo[ph].left_fork = &data->array_philo[ph - 1].fork;
		ph++;
	}
}

t_data	*stats_args(t_data *data, char **argv, int argc)
{
	int		ph;

	ph = 1;
	data->die = ft_atoi(argv[2]);
	data->eat = ft_atoi(argv[3]);
	data->sleep = ft_atoi(argv[4]);
	while (ph <= data->num_ph)
	{
		memset(&data->array_philo[ph], 0, sizeof(t_philo));
		data->array_philo[ph].id = ph;
		data->array_philo[ph].num_philo = data->num_ph;
		if (argc == 6)
			data->array_philo[ph].must_eat = ft_atoi(argv[5]);
		pthread_mutex_init(&data->array_philo[ph].fork, NULL);
		data->array_philo[ph].data = data;
		ph++;
	}
	put_forks(data);
	return (data);
}

void	init_all(t_data *data, char **argv, int argc)
{
	data->num_ph = ft_atoi(argv[1]);
	data->argc = argc;
	data->array_philo = malloc((data->num_ph + 1) * sizeof(t_philo));
	pthread_mutex_init(&data->mutex_text, NULL);
	pthread_mutex_init(&data->mutex_dead, NULL);
	pthread_mutex_init(&data->mutex_time, NULL);
	pthread_mutex_init(&data->mutex_eat, NULL);
	pthread_mutex_init(&data->mutex_reaper_time, NULL);
	pthread_mutex_init(&data->mutex_must_eat, NULL);
	data = stats_args(data, argv, argc);
}

void	close_all(t_data *data)
{
	int	ph;

	ph = 1;
	while (ph <= data->num_ph)
	{
		pthread_mutex_destroy(&data->array_philo[ph].fork);
		ph++;
	}
	pthread_mutex_destroy(&data->mutex_text);
	pthread_mutex_destroy(&data->mutex_dead);
	pthread_mutex_destroy(&data->mutex_time);
	pthread_mutex_destroy(&data->mutex_eat);
	pthread_mutex_destroy(&data->mutex_reaper_time);
	pthread_mutex_destroy(&data->mutex_must_eat);
	free(data->array_philo);
}
