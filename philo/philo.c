/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 00:59:24 by kkeskin           #+#    #+#             */
/*   Updated: 2025/10/02 00:59:25 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	settings_init(t_settings *set, int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (printf("Invalid Argument Count!\n"), 1);
	(*set).number_of_philo = ft_atol(argv[1]);
	if ((*set).number_of_philo <= 0)
		return (printf("Number of philosophers can't be negative!\n"), 1);
	(*set).time_to_die = ft_atol(argv[2]);
	if ((*set).time_to_die <= 0)
		return (printf("Time to die must be higher than 0!\n"), 1);
	(*set).time_to_eat = ft_atol(argv[3]);
	if ((*set).time_to_eat <= 0)
		return (printf("Time to eat must be higher than 0!\n"), 1);
	(*set).time_to_sleep = ft_atol(argv[4]);
	if ((*set).time_to_sleep <= 0)
		return (printf("Time to sleep must be higher than 0!\n"), 1);
	if (argc == 5)
		(*set).max_eat_count = -1;
	else if (argc == 6)
	{
		(*set).max_eat_count = ft_atol(argv[5]);
		if ((*set).max_eat_count <= 0)
			return (printf("Number of times each philo must eat can't"),
				printf("be lower than 1!\n"), 1);
	}
	return (0);
}

static pthread_t	*create_philos(t_settings set)
{
	pthread_t	*t;

	t = malloc(sizeof(pthread_t) * set.number_of_philo);
	if (!t)
		return (NULL);
	return (t);
}

static pthread_mutex_t	*create_fork(t_settings set)
{
	pthread_mutex_t	*m;

	m = malloc(sizeof(pthread_mutex_t) * set.number_of_philo);
	if (!m)
		return (NULL);
	return (m);
}

static t_info	*create_info(pthread_mutex_t *m, int index_of_philo, t_settings set)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	(*info).all_mutexes = m;
	(*info).index_of_philo = index_of_philo;
	(*info).set = set;
	return (info);
}

static void	general_loop(t_settings set)
{
	pthread_t		*t;
	pthread_mutex_t	*m;
	t_info			*info;
	int				i;

	i = 0;
	t = create_philos(set);
	m = create_fork(set);
	while (i < set.number_of_philo)
	{
		pthread_mutex_init(&m[i], NULL);
		info = create_info(m, i, set);
		pthread_create(&t[i], NULL, &routine, (void **)info);
		i++;
	}
	i = 0;
	while (i < set.number_of_philo)
	{
		pthread_join(t[i], (void **)&info);
		free(info);
		pthread_mutex_destroy(&m[i]);
		i++;
	}
	free(t);
	free(m);
}

static void	set_time(t_settings *set)
{
	gettimeofday(&(*set).start_time, NULL);
}

int	main(int argc, char *argv[])
{
	t_settings	set;

	if (settings_init(&set, argc, argv))
		return (1);
	set_time(&set);
	general_loop(set);
	return (0);
}
