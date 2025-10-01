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
	pthread_t	*t1;

	t1 = malloc(sizeof(pthread_t) * set.number_of_philo);
	if (!t1)
		return (NULL);
	return (t1);
}

static pthread_t	*general_loop(t_settings set)
{
	pthread_t	*t1;
	int			i;

	i = 0;
	t1 = create_philos(set);
	while (i < set.number_of_philo)
	{
		pthread_create(&t1[i], NULL, &routine, (void **)&set);
		i++;
	}
	i = 0;
	while (i < set.number_of_philo)
	{
		pthread_join(t1[i], NULL);
		i++;
	}
	return (t1);
}

int	main(int argc, char *argv[])
{
	t_settings	set;

	if (settings_init(&set, argc, argv))
		return (1);
	free(general_loop(set));
	return (0);
}
