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

static long	calculate_time(t_settings set)
{
	struct timeval	current;
	long			elapsed_ms;

	gettimeofday(&current, NULL);
	elapsed_ms = (current.tv_sec - set.start_time.tv_sec) * 1000
			+	(current.tv_usec - set.start_time.tv_usec) / 1000;
	return (elapsed_ms);
}

static void	take_forks(t_info info)
{
	int left;
	int	right;

	left = info.index_of_philo;
	right = (info.index_of_philo + 1) % info.set.number_of_philo;

	pthread_mutex_lock(&info.all_mutexes[left]);
	pthread_mutex_lock(&info.all_mutexes[right]);
	fork_message(calculate_time(info.set), info.index_of_philo);
	eat_message(calculate_time(info.set), info.index_of_philo);
	usleep(info.set.time_to_eat * 1000);
	pthread_mutex_unlock(&info.all_mutexes[left]);
	pthread_mutex_unlock(&info.all_mutexes[right]);
	sleep_message(calculate_time(info.set), info.index_of_philo);
	usleep(info.set.time_to_sleep * 1000);
	think_message(calculate_time(info.set), info.index_of_philo);
}

void	*routine(void *arg)
{
	t_info	info;

	info = *(t_info *)arg;
	take_forks(info);
	return (arg);
}
