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
	t_settings	set;

	set = *(t_settings *)arg;
	printf("Number of philo: %ld\n", set.number_of_philo);
	printf("Time to die: %ld\n", set.time_to_die);
	printf("Time to eat: %ld\n", set.time_to_eat);
	printf("Time to sleep: %ld\n", set.time_to_sleep);
	printf("Max eat count: %ld\n", set.max_eat_count);
	return (arg);
}
