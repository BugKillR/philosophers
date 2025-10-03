/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 00:59:13 by kkeskin           #+#    #+#             */
/*   Updated: 2025/10/02 00:59:13 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	calculate_whole_time(t_settings set)
{
	struct timeval	current;
	long			elapsed_ms;

	gettimeofday(&current, NULL);
	elapsed_ms = (current.tv_sec - set.start_time.tv_sec) * 1000
			+	(current.tv_usec - set.start_time.tv_usec) / 1000;
	return (elapsed_ms);
}

static long	calculate_time(struct timeval start)
{
	struct timeval	current;
	long			elapsed_ms;

	gettimeofday(&current, NULL);
	elapsed_ms = (current.tv_sec - start.tv_sec) * 1000
			+	(current.tv_usec - start.tv_usec) / 1000;
	return (elapsed_ms);
}

static void	take_forks(t_info info)
{
	struct timeval	last_time_eat;
	int 			left;
	int				right;

	left = info.index_of_philo;
	right = (info.index_of_philo + 1) % info.set.number_of_philo;
	last_time_eat = info.set.start_time;
	while (0 < *(info.set.max_eat_count) || *(info.set.max_eat_count) == -1)
	{
		pthread_mutex_lock(&info.all_mutexes[left]);
		pthread_mutex_lock(&info.all_mutexes[right]);
		if (calculate_time(last_time_eat) >= info.set.time_to_die)
		{
			pthread_mutex_unlock(&info.all_mutexes[left]);
			pthread_mutex_unlock(&info.all_mutexes[right]);
			*(info.set.max_eat_count) = 0;
			return (died_message(calculate_whole_time(info.set), info.index_of_philo));
		}
		fork_message(calculate_whole_time(info.set), info.index_of_philo);
		eat_message(calculate_whole_time(info.set), info.index_of_philo);
		usleep(info.set.time_to_eat * 1000);
		gettimeofday(&last_time_eat, NULL);
		pthread_mutex_unlock(&info.all_mutexes[left]);
		pthread_mutex_unlock(&info.all_mutexes[right]);
		sleep_message(calculate_whole_time(info.set), info.index_of_philo);
		usleep(info.set.time_to_sleep * 1000);
		think_message(calculate_whole_time(info.set), info.index_of_philo);
		if (*(info.set.max_eat_count) != -1)
			*(info.set.max_eat_count) = *(info.set.max_eat_count) - 1;
	}
	return ;
}

void	*routine(void *arg)
{
	t_info	info;

	info = *(t_info *)arg;
	take_forks(info);
	return (arg);
}
