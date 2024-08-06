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

	return ((void *)0);
}

//./philo [cant. filo y tenedores] [tiempo de morir] [tiempo comer] [tiempo dormir] [op: veces que comen]
int	main(int argc, char **argv)
{
	int				ph;
	t_data			data;

	// if (argc < 5 || argc > 6 || ft_atoi(argv[1]) < 2)
	// 	return (EXIT_FAILURE);
	if (all_args_nums(argc, argv) == 1)
		return (EXIT_FAILURE);
	printf(GREEN"EMPIEZA\n"END);
	data = init_all(data, argv, argc);
	ph = 0;
	while (ph < data.num_philo)
	{
		pthread_create(&data.philo[ph], NULL, routine, &data.array_philo[ph]);
		ph++;
	}
	ph -= 1;
	while (ph != 0)
	{
		pthread_join(data.philo[ph], NULL);
		ph--;
	}
	close_all(data);
	printf(GREEN"SE ACABÓ\n"END);
	return (0);
}
