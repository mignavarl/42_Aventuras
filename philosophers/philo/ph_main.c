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
	while (42)
	{
		if ((ft_time(philo) - philo->last_eat) >= philo->time_die)
		{
			dead(philo);
			break ;
		}
		if (its_dead(philo) == 0)
		{
			if (eat(philo) == 1)
				break ;
			if (philo->data->argc == 6)
				philo->must_eat--;
			if ((philo->data->argc == 6 && philo->must_eat == 0))
				break ;
			sleeping(philo);
			think(philo);
		}
		if (its_dead(philo) == 1)
			break ;
	}
	return ((void *)0);
}

//./philo [cant. filo y tenedores] [tiempo de morir] [tiempo comer] [tiempo dormir] [op: veces que comen]
int	main(int argc, char **argv)
{
	int		ph;
	t_data	data;

	// if (argc < 5 || argc > 6 || ft_atoi(argv[1]) == 0)
	// 	return (EXIT_FAILURE);
	// if (ft_atoi(argv[1]) == 1)
	// 	TODO:pasan_cosas;
	if (all_args_nums(argc, argv) == 1)
		return (EXIT_FAILURE);
	printf(GREEN"EMPIEZA\n"END);
	memset(&data, 0, sizeof(data));
	init_all(&data, argv, argc);
	ph = 1;
	while (ph < data.num_ph)
	{
		pthread_create(&data.array_philo[ph].philo, NULL, routine, &data.array_philo[ph]);
		ph++;
	}
	ph = 1;
	while (ph < data.num_ph)
	{
		pthread_join(data.array_philo[ph].philo, NULL);
		ph++;
	}
	close_all(&data);
	printf(GREEN"SE ACABÓ\n"END);
	return (0);
}
