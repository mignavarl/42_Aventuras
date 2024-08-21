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

	data->array_philo[0].left_fork = &data->array_philo[data->num_ph - 1].fork;
	ph = 1;
	while (ph < data->num_ph)
	{
		data->array_philo[ph].left_fork = &data->array_philo[ph - 1].fork;
		ph++;
	}
}

t_data	*stats_args(t_data *data, char **argv, int argc)
{
	int		ph;
	size_t	die;
	size_t	eat;
	size_t	sleep;

	ph = 0;
	die = ft_atoi(argv[2]);
	eat = ft_atoi(argv[3]);
	sleep = ft_atoi(argv[4]);
	while (ph < data->num_ph)
	{
		memset(&data->array_philo[ph], 0, sizeof(t_philo));
		data->array_philo[ph].id = ph;
		data->array_philo[ph].num_philo = data->num_ph;
		data->array_philo[ph].time_die = die;
		data->array_philo[ph].time_eat = eat;
		data->array_philo[ph].time_sleep = sleep;
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
	data->array_philo = malloc(data->num_ph * sizeof(t_philo));
	pthread_mutex_init(&data->mutex_text, NULL);
	data = stats_args(data, argv, argc);
}

void	close_all(t_data *data)
{
	int	ph;

	ph = 0;
	while (ph < data->num_ph)
	{
		pthread_mutex_destroy(&data->array_philo[ph].fork);
		ph++;
	}
	pthread_mutex_destroy(&data->mutex_text);
	free(data->array_philo);
}
