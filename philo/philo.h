/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 00:59:30 by kkeskin           #+#    #+#             */
/*   Updated: 2025/10/02 00:59:30 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_settings
{
	long	number_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	max_eat_count;
}				t_settings;

typedef struct s_info
{
	pthread_mutex_t	*all_mutexes;
	t_settings		set;
	int				index_of_philo;
}				t_info;

long	ft_atol(const char *num);

//	----- STDOUT Functions -----

void	fork_message(long ms_passed, int philo_id);
void	eat_message(long ms_passed, int philo_id);
void	sleep_message(long ms_passed, int philo_id);
void	think_message(long ms_passed, int philo_id);
void	died_message(long ms_passed, int philo_id);

void	*routine(void *x);

#endif
