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

void	*routine(void *arg)
{
	t_info	info;

	info = *(t_info *)arg;
	printf("Number of philo: %ld\n", info.set.number_of_philo);
	printf("Time to die: %ld\n", info.set.time_to_die);
	printf("Time to eat: %ld\n", info.set.time_to_eat);
	printf("Time to sleep: %ld\n", info.set.time_to_sleep);
	printf("Max eat count: %ld\n", info.set.max_eat_count);
	return (arg);
}
