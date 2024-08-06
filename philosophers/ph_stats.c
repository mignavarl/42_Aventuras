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

t_data	stats_args(t_data data, char **argv, int argc)
{
	int		ph;
	size_t	die;
	size_t	eat;
	size_t	sleep;

	ph = 0;
	data.num_philo = ft_atoi(argv[1]);
	die = ft_atoi(argv[2]);
	eat = ft_atoi(argv[3]);
	sleep = ft_atoi(argv[4]);
	while (ph < data.num_philo)
	{
		data.array_philo[ph].id = ph;
		data.array_philo[ph].num_philo = data.num_philo;
		data.array_philo[ph].dead = 0;
		data.array_philo[ph].time_die = die;
		data.array_philo[ph].time_eat = eat;
		data.array_philo[ph].time_sleep = sleep;
		if (argc == 6)
			data.array_philo[ph].must_eat = ft_atoi(argv[5]);
		pthread_mutex_init(&data.array_philo[ph].fork, NULL);
		ph++;
	}
	return (data);
}

t_data	init_all(t_data data, char **argv, int argc)
{
	data.philo = malloc(data.num_philo * sizeof(pthread_t));
	data.array_philo = malloc(data.num_philo * sizeof(t_philo));
	data = stats_args(data, argv, argc);
	return (data);
}

void	close_all(t_data data)
{
	int	ph;

	ph = 0;
	while (ph < data.num_philo)
	{
		pthread_mutex_destroy(&data.array_philo[ph].fork);
		ph++;
	}
}
