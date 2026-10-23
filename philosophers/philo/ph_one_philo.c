/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_one_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 10:37:23 by mignavar          #+#    #+#             */
/*   Updated: 2024-09-09 10:37:23 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_text(philo, "f");
	usleep(philo->data->die * 1000);
	print_text(philo, "d");
	return ((void *)0);
}

void	only_one(t_data *data)
{
	pthread_create(&data->array_philo[1].philo,
		NULL, one_philo, &data->array_philo[1]);
	pthread_join(data->array_philo[1].philo, NULL);
	close_all(data);
}
