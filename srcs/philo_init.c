/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:55:58 by ubazzane          #+#    #+#             */
/*   Updated: 2024/03/05 10:39:31 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (philo->data->life_state == ALIVE)
	{
		take_forks(philo);
		eating(philo);
		sleep_and_think(philo);
	}
	return (0);
}

void	init_philosophers(t_data *data)
{
	int i;

	i = 0;
	data->starting_time = get_time();
	while (i < data->philo_count)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL, routine, &data->philos[i]) != 0)
			ft_exit(data, "Thread init error\n", 1);
		i++;
	}
}

void	join_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_count)
	{
		printf("Joining thread %d\n", i);
		if (pthread_join(data->philos[i].thread_id, NULL) != 0)
			ft_exit(data, "Thread join error\n", 1);
		i++;
	}
}
