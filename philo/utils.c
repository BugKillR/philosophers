/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 00:59:04 by kkeskin           #+#    #+#             */
/*   Updated: 2025/10/02 00:59:05 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_message(long ms_passed, int philo_id)
{
	printf("%ld %d has taken a fork\n", ms_passed, philo_id);
}

void	eat_message(long ms_passed, int philo_id)
{
	printf("%ld %d is eating\n", ms_passed, philo_id);
}

void	sleep_message(long ms_passed, int philo_id)
{
	printf("%ld %d is sleeping\n", ms_passed, philo_id);
}

void	think_message(long ms_passed, int philo_id)
{
	printf("%ld %d is thinking\n", ms_passed, philo_id);
}

void	died_message(long ms_passed, int philo_id)
{
	printf("%ld %d died\n", ms_passed, philo_id);
}
