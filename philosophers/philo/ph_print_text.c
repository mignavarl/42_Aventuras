/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-09 12:58:26 by mignavar          #+#    #+#             */
/*   Updated: 2024-09-09 12:58:26 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_text(t_philo *philo, const char *letter)
{
	pthread_mutex_lock(&philo->data->mutex_dead);
	if (philo->data->someone_is_dead_so_sad == 0)
	{
		pthread_mutex_lock(&philo->data->mutex_text);
		if (letter[0] == 'f')
			printf("[%ld] %d has taken a fork 🍴\n", ft_time(philo), philo->id);
		if (letter[0] == 'e')
			printf(YELLOW"[%ld] %d is eating 🍝\n"END,
				ft_time(philo), philo->id);
		if (letter[0] == 's')
			printf(BLUE"[%ld] %d is sleeping 🛌\n"END,
				ft_time(philo), philo->id);
		if (letter[0] == 't')
			printf(PURPLE"[%ld] %d is thinking 🧠\n"END,
				ft_time(philo), philo->id);
		if (letter[0] == 'd')
			printf(RED"[%ld] %d died 💀\n"END, ft_time(philo), philo->id);
		pthread_mutex_unlock(&philo->data->mutex_text);
	}
	pthread_mutex_unlock(&philo->data->mutex_dead);
}
