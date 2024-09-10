/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-23 14:25:19 by mignavar          #+#    #+#             */
/*   Updated: 2024-07-23 14:25:19 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// if (philo->id % 2 == 0)
	// 	usleep(1000);
	while (42)
	{
		if (its_dead(philo) == 0)
		{
			if (eat(philo) == 1)
				break ;
			pthread_mutex_lock(&philo->data->mutex_must_eat);
			if (philo->data->argc == 6)
				philo->must_eat--;
			pthread_mutex_unlock(&philo->data->mutex_must_eat);
			sleeping(philo);
			think(philo);
		}
		if (its_dead(philo) == 1)
			break ;
	}
	return ((void *)0);
}

void	create_philos(t_data *data)
{
	int	ph;

	ph = 1;
	while (ph <= data->num_ph)
	{
		pthread_create(&data->array_philo[ph].philo,
			NULL, routine, &data->array_philo[ph]);
		ph++;
	}
}

int	main(int argc, char **argv)
{
	int		ph;
	t_data	data;

	if (argc < 5 || argc > 6 || ft_atoi(argv[1]) == 0)
		return (EXIT_FAILURE);
	if (all_args_nums(argc, argv) == 1)
		return (EXIT_FAILURE);
	memset(&data, 0, sizeof(data));
	init_all(&data, argv, argc);
	if (ft_atoi(argv[1]) == 1)
	{
		only_one(&data);
		return (0);
	}
	create_philos(&data);
	reaper(&data);
	ph = 1;
	while (ph <= data.num_ph)
	{
		pthread_join(data.array_philo[ph].philo, NULL);
		ph++;
	}
	close_all(&data);
	return (0);
}
