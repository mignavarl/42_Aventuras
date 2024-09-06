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

void	*only_one(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_text(philo, "taken a fork");
	usleep(philo->data->die * 1000);
	print_text(philo, "died");
	return ((void *)0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
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
			// if ((philo->data->argc == 6 && philo->must_eat == 0))
			// 	break ;
			sleeping(philo);
			think(philo);
		}
		if (its_dead(philo) == 1)
			break ;
		//printf("Vuelta [%d]\n", philo->id);
	}
	printf(RED"FIN DEL HILO DE %d\n"END, philo->id);
	return ((void *)0);
}

//./philo [cant. filo y tenedores] [tiempo de morir] [tiempo comer] [tiempo dormir] [op: veces que comen]
int	main(int argc, char **argv)
{
	int		ph;
	t_data	data;

	if (argc < 5 || argc > 6 || ft_atoi(argv[1]) == 0)
		return (EXIT_FAILURE);
	if (all_args_nums(argc, argv) == 1)
		return (EXIT_FAILURE);
	printf(GREEN"EMPIEZA\n"END);
	memset(&data, 0, sizeof(data));
	init_all(&data, argv, argc);
	ph = 1;
	if (ft_atoi(argv[1]) == 1)
	{
		pthread_create(&data.array_philo[ph].philo, NULL, only_one, &data.array_philo[ph]);
		pthread_join(data.array_philo[ph].philo, NULL);
		close_all(&data);
		return (0);
	}
	while (ph <= data.num_ph)
	{
		pthread_create(&data.array_philo[ph].philo, NULL, routine, &data.array_philo[ph]);
		ph++;
	}
	ph = 1;
	//printf("Llega aquí\n"); 
	// pthread_create(&data.the_reaper, NULL, reaper, &data);
	// pthread_join(data.the_reaper, NULL);
	reaper(&data);
	while (ph <= data.num_ph)//TODO: no llegan todos
	{
		printf("PH: %d\n", ph);
		pthread_join(data.array_philo[ph].philo, NULL);
		ph++;
	}
	close_all(&data);
	printf(GREEN"SE ACABÓ\n"END);
	return (0);
}
