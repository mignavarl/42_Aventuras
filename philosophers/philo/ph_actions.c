/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-21 14:14:38 by mignavar          #+#    #+#             */
/*   Updated: 2024-08-21 14:14:38 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	if (its_dead(philo) == 0)
		print_text(philo, "t");
}

void	sleeping(t_philo *philo)
{
	if (its_dead(philo) == 0)
	{
		print_text(philo, "s");
		usleep(philo->data->sleep * 1000);
	}
}
