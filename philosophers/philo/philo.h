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
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;95m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define END "\033[0m"

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct s_philo
{
	pthread_t		philo;
	int				id;
	int				num_philo;
	int				must_eat;
	pthread_mutex_t	fork;
	pthread_mutex_t	*left_fork;
	int				eating;
	size_t			last_eat;
	t_data			*data;
};

struct s_data
{
	pthread_t		the_reaper;
	int				num_ph;
	t_philo			*array_philo;
	pthread_mutex_t	mutex_dead;
	pthread_mutex_t	mutex_text;
	pthread_mutex_t	mutex_time;
	pthread_mutex_t	mutex_eat;
	pthread_mutex_t	mutex_reaper_time;
	pthread_mutex_t	mutex_must_eat;
	int				all_eat;
	int				argc;
	size_t			die;
	size_t			eat;
	size_t			sleep;
	int				someone_is_dead_so_sad;
};

//STATS
int		init_all(t_data *data, char **argv, int argc);
void	close_all(t_data *data);

//ACTIONS
void	only_one(t_data *data);
void	*one_philo(void *arg);
void	sleeping(t_philo *philo);
void	think(t_philo *philo);
int		eat_odd(t_philo *philo);
int		eat_even(t_philo *philo);
int		eat(t_philo *philo);

//DEAD
void	dead(t_philo *philo);
int		its_dead(t_philo *philo);

//REAPER
void	reaper(void *arg);

//UTILS
int		all_args_nums(int argc, char **argv);
int		ft_atoi(const char *str);
size_t	ft_time(t_philo *philo);
void	print_text(t_philo *philo, const char *letter);

#endif