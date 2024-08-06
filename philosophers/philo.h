/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-23 14:26:24 by mignavar          #+#    #+#             */
/*   Updated: 2024-07-23 14:26:24 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define END "\033[0m"

typedef struct s_philo
{
	int				num_philo;
	int				must_eat;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_sleep;
	pthread_mutex_t	fork;
	int				dead;
	int				id;
}				t_philo;

typedef struct s_data
{
	int				num_philo;
	pthread_t		*philo;
	t_philo			*array_philo;
}				t_data;

//STATS
t_data	init_all(t_data data, char **argv, int argc);
void	close_all(t_data data);

//UTILS
int		all_args_nums(int argc, char **argv);
int		ft_atoi(const char *str);

#endif